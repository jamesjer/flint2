/*
    Copyright (C) 2016 William Hart

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include <gmp.h>
#include <stdlib.h>
#include "flint.h"
#include "fmpz.h"
#include "fmpz_mpoly.h"

slong _fmpz_mpoly_add1(fmpz * poly1, ulong * exps1,
                const fmpz * poly2, const ulong * exps2, slong len2,
                const fmpz * poly3, const ulong * exps3, slong len3,
                                         slong bits, slong n, int deg, int rev)
{
   slong i = 0, j = 0, k = 0;

   while (i < len2 && j < len3)
   {
      if (exps2[i] < exps3[j])
      {
         fmpz_set(poly1 + k, poly2 + i);
         exps1[k] = exps2[i];
         i++;
      } else if (exps2[i] == exps3[j])
      {
         fmpz_add(poly1 + k, poly2 + i, poly3 + j);
         exps1[k] = exps2[i];
         if (fmpz_is_zero(poly1 + k))
            k--;
         i++;
         j++;
      } else
      {
         fmpz_set(poly1 + k, poly3 + j);
         exps1[k] = exps3[j];
         j++;         
      }
      k++;
   }

   while (i < len2)
   {
      fmpz_set(poly1 + k, poly2 + i);
      exps1[k] = exps2[i];
      i++;
      k++;
   }

   while (j < len3)
   {
      fmpz_set(poly1 + k, poly3 + j);
      exps1[k] = exps3[j];
      j++;
      k++;
   }

   return k;
}

void fmpz_mpoly_add(fmpz_mpoly_t poly1, const fmpz_mpoly_t poly2,
                          const fmpz_mpoly_t poly3, const fmpz_mpoly_ctx_t ctx)
{
   slong len = 0, max_bits, N;
   int deg, rev;
   ulong * ptr1, * ptr2;

   max_bits = FLINT_MAX(poly2->bits, poly3->bits);
   N = (max_bits*ctx->n - 1)/FLINT_BITS + 1;
   
   if (N == 1)
   {
      degrev_from_ord(deg, rev, ctx->ord);

      ptr1 = _fmpz_mpoly_unpack_monomials(max_bits, poly2->exps, 
                                           poly2->bits, ctx->n, poly2->length);

      ptr2 = _fmpz_mpoly_unpack_monomials(max_bits, poly3->exps, 
                                           poly3->bits, ctx->n, poly3->length);

      if (poly1 == poly2 || poly1 == poly3)
      {
         fmpz_mpoly_t temp;

         fmpz_mpoly_init2(temp, poly2->length + poly3->length, ctx);
         fmpz_mpoly_fit_bits(temp, max_bits, ctx);

         len = _fmpz_mpoly_add1(temp->coeffs, temp->exps, 
                       poly2->coeffs, ptr1, poly2->length,
                       poly3->coeffs, ptr2, poly3->length,
                                                  max_bits, ctx->n, deg, rev);

         fmpz_mpoly_swap(temp, poly1, ctx);

         fmpz_mpoly_clear(temp, ctx);

      } else
      {
         fmpz_mpoly_fit_length(poly1, poly2->length + poly3->length, ctx);
         fmpz_mpoly_fit_bits(poly1, max_bits, ctx);

         len = _fmpz_mpoly_add1(poly1->coeffs, poly1->exps, 
                       poly2->coeffs, ptr1, poly2->length,
                       poly3->coeffs, ptr2, poly3->length,
                                                   max_bits, ctx->n, deg, rev);
      }

      if (ptr1 != poly2->exps)
         flint_free(ptr1);

      if (ptr2 != poly3->exps)
         flint_free(ptr2);

      _fmpz_mpoly_set_length(poly1, len, ctx);

   } else
      flint_throw(FLINT_ERROR, "Not implemented yet");
}