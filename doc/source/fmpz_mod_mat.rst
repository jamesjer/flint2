.. _fmpz_mod_mat:

**fmpz_mod_mat.h** -- matrices over integers mod n
===============================================================================

Description.

Types, macros and constants
-------------------------------------------------------------------------------

.. type:: fmpz_mod_mat_struct

.. type:: fmpz_mod_mat_t

    Description.

    .. type:: fmpz_mod_mat_struct
                        
    .. type:: fmpz_mod_mat_t
                      
    Description.

Element access
--------------------------------------------------------------------------------


.. function:: fmpz * fmpz_mod_mat_entry(const fmpz_mod_mat_t mat, slong i, slong j)

    Return a reference to the element at row ``i`` and column ``j`` of ``mat``.

.. function:: void fmpz_mod_mat_set_entry(fmpz_mod_mat_t mat, slong i, slong j, const fmpz_t val)

    Set the entry at row ``i`` and column ``j`` of ``mat`` to ``val``.


Memory management
--------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_init(fmpz_mod_mat_t mat, slong rows, slong cols, const fmpz_t n)

    Initialise ``mat`` as a matrix with the given number of ``rows`` and
    ``cols`` and modulus ``n``.

.. function:: void fmpz_mod_mat_init_set(fmpz_mod_mat_t mat, const fmpz_mod_mat_t src)

    Initialise ``mat`` and set it equal to the matrix ``src``, including the
    number of rows and columns and the modulus.

.. function:: void fmpz_mod_mat_clear(fmpz_mod_mat_t mat)

    Clear ``mat`` and release any memory it used.


Basic manipulation                                                                        --------------------------------------------------------------------------------


.. function:: slong fmpz_mod_mat_nrows(const fmpz_mod_mat_t mat)

   Return the number of rows of ``mat``.

.. function:: slong fmpz_mod_mat_ncols(const fmpz_mod_mat_t mat)

    Return the number of columns of ``mat``.

.. function:: void _fmpz_mod_mat_set_mod(fmpz_mod_mat_t mat, const fmpz_t n)

    Set the modulus of the matrix ``mat`` to ``n``.

.. function:: void fmpz_mod_mat_one(fmpz_mod_mat_t mat)

    Set ``mat`` to the identity matrix (ones down the diagonal).

.. function:: void fmpz_mod_mat_zero(fmpz_mod_mat_t mat)

    Set ``mat`` to the zero matrix.

.. function:: void fmpz_mod_mat_swap(fmpz_mod_mat_t mat1, fmpz_mod_mat_t mat2)

    Efficiently swap the matrices ``mat1`` and ``mat2``.

.. function:: int fmpz_mod_mat_is_empty(const fmpz_mod_mat_t mat)

    Return `1` if ``mat`` has either zero rows or columns.

.. function:: int fmpz_mod_mat_is_square(const fmpz_mod_mat_t mat)

    Return `1` if ``mat`` has the same number of rows and columns.

.. function:: void _fmpz_mod_mat_reduce(fmpz_mod_mat_t mat)

    Reduce all the entries of ``mat`` by the modulus ``n``. This function is
    only needed internally.


Random generation
--------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_randtest(fmpz_mod_mat_t mat, flint_rand_t state)

    Generate a random matrix with the existing dimensions and entries in
    `[0, n)` where ``n`` is the modulus.


Windows and concatenation
--------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_window_init(fmpz_mod_mat_t window, const fmpz_mod_mat_t mat, slong r1, slong c1, slong r2, slong c2)

    Initializes the matrix ``window`` to be an ``r2 - r1`` by
    ``c2 - c1`` submatrix of ``mat`` whose ``(0, 0)`` entry
    is the ``(r1, c1)`` entry of ``mat``. The memory for the
    elements of ``window`` is shared with ``mat``.

.. function:: void fmpz_mod_mat_window_clear(fmpz_mod_mat_t window)

    Clears the matrix ``window`` and releases any memory that it
    uses. Note that the memory to the underlying matrix that
    ``window`` points to is not freed.

.. function:: void fmpz_mod_mat_concat_horizontal(fmpz_mod_mat_t res, const fmpz_mod_mat_t mat1, const fmpz_mod_mat_t mat2)

    Sets ``res`` to vertical concatenation of (``mat1``, ``mat2``)                            in that order. Matrix dimensions : ``mat1`` : `m \times n`,                               ``mat2`` : `k \times n`, ``res`` : `(m + k) \times n`.

.. function:: void fmpz_mod_mat_concat_vertical(fmpz_mod_mat_t res, const fmpz_mod_mat_t mat1, const fmpz_mod_mat_t mat2)

    Sets ``res`` to horizontal concatenation of (``mat1``, ``mat2``)
    in that order. Matrix dimensions : ``mat1`` : `m \times n`,
    ``mat2`` : `m \times k`, ``res``  : `m \times (n + k)`.


Input and output
--------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_print_pretty(const fmpz_mod_mat_t mat)

    Prints the given matrix to ``stdout``.  The format is an
    opening square bracket then on each line a row of the matrix, followed
    by a closing square bracket. Each row is written as an opening square
    bracket followed by a space separated list of coefficients followed
    by a closing square bracket.


Comparison
--------------------------------------------------------------------------------


.. function:: int fmpz_mod_mat_is_zero(const fmpz_mod_mat_t mat)

    Return `1` if ``mat`` is the zero matrix.


Set and transpose
--------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_set(fmpz_mod_mat_t B, const fmpz_mod_mat_t A)

    Set ``B`` to equal ``A``.

.. function:: void fmpz_mod_mat_transpose(fmpz_mod_mat_t B, const fmpz_mod_mat_t A)

    Set ``B`` to the transpose of ``A``.


Addition and subtraction
-------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_add(fmpz_mod_mat_t C, const fmpz_mod_mat_t A, const fmpz_mod_mat_t B)

    Set ``C`` to `A + B`.

.. function:: void fmpz_mod_mat_sub(fmpz_mod_mat_t C, const fmpz_mod_mat_t A, const fmpz_mod_mat_t B)

    Set ``C`` to `A - B`.

.. function:: void fmpz_mod_mat_neg(fmpz_mod_mat_t B, const fmpz_mod_mat_t A)

    Set ``B`` to `-A`.


Scalar arithmetic
--------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_scalar_mul_si(fmpz_mod_mat_t B, const fmpz_mod_mat_t A, slong c)

    Set ``B`` to `cA` where ``c`` is a constant.

.. function:: void fmpz_mod_mat_scalar_mul_ui(fmpz_mod_mat_t B, const fmpz_mod_mat_t A, slong c)

    Set ``B`` to `cA` where ``c`` is a constant.

.. function:: void fmpz_mod_mat_scalar_mul_fmpz(fmpz_mod_mat_t B, const fmpz_mod_mat_t A, fmpz_t c)

    Set ``B`` to `cA` where ``c`` is a constant.


Matrix multiplication
---------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_mul(fmpz_mod_mat_t C, const fmpz_mod_mat_t A, const fmpz_mod_mat_t B)

    Set ``C`` to ``A\times B``. The number of rows of ``B`` must match the
    number of columns of ``A``.

.. function:: void _fmpz_mod_mat_mul_classical_threaded_pool_op(fmpz_mod_mat_t D, const fmpz_mod_mat_t C, const fmpz_mod_mat_t A, const fmpz_mod_mat_t B, int op, thread_pool_handle * threads, slong num_threads)

    Set ``D`` to ``A\times B + op*C`` where ``op`` is ``+1``, ``-1`` or ``0``.

.. function:: void _fmpz_mod_mat_mul_classical_threaded_op(fmpz_mod_mat_t D, const fmpz_mod_mat_t C, const fmpz_mod_mat_t A, const fmpz_mod_mat_t B, int op)

    Set ``D`` to ``A\times B + op*C`` where ``op`` is ``+1``, ``-1`` or ``0``.

.. function:: void fmpz_mod_mat_mul_classical_threaded(fmpz_mod_mat_t C, const fmpz_mod_mat_t A, const fmpz_mod_mat_t B)

    Set ``C`` to ``A\times B``. The number of rows of ``B`` must match the
    number of columns of ``A``.

.. function:: void fmpz_mod_mat_sqr(fmpz_mod_mat_t B, const fmpz_mod_mat_t A)

    Set ``B`` to ``A^2``. The matrix ``A`` must be square.


Trace
---------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_trace(fmpz_t trace, const fmpz_mod_mat_t mat)

    Set ``trace`` to the trace of the matrix ``mat``.

Gaussian elimination
--------------------------------------------------------------------------------


.. function:: slong fmpz_mod_mat_rref(slong * perm, fmpz_mod_mat_t mat)

    Uses Gauss-Jordan elimination to set ``mat`` to its reduced row echelon
    form and returns the rank of ``mat``.

    If ``perm`` is non-``NULL``, the permutation of
    rows in the matrix will also be applied to ``perm``.


Strong echelon form and Howell form
--------------------------------------------------------------------------------


.. function:: void fmpz_mod_mat_strong_echelon_form(fmpz_mod_mat_t mat)

    Transforms `mat` into the strong echelon form of `mat`. The Howell form and the
    strong echelon form are equal up to permutation of the rows, see
    [FieHof2014]_ for a definition of the strong echelon form and the
    algorithm used here.

    `mat` must have at least as many rows as columns.

.. function:: slong fmpz_mod_mat_howell_form_mod(fmpz_mod_mat_t mat)

    Transforms `mat` into the Howell form of `mat`.  For a definition of the
    Howell form see [StoMul1998]_. The Howell form is computed by first
    putting `mat` into strong echelon form and then ordering the rows.

    `mat` must have at least as many rows as columns.

