#include <stdio.h>
#include <math.h>

/*
Procedure:
    getDigit
Purpose:
    Get the dth digit from an integer. In 81, 1 is the first digit, 8 is the second.
Parameters:
    x, the number to get the digit from
    d, the digit to get
Produces:
    x_d, the dth digit of x. If x has fewer than d digits, x_d = 0
Preconditions and Postconditions:
    None
 */
 
int 
getDigit(int x, int d) 
{
    return (x / (int)pow(10,d-1)) % 10; // Chop first d-1 digits, mod 10 to get dth digit
}

/*
Procedure:
    countingSortByD
Purpose:
    Perform counting sort on an array in terms of the dth digit of each element.
    Helper procedure for radix sort.
Parameters:
    A, the array of nonnegative integers to be sorted
    B, the array to output to
    n, the length of A
    d, the digit by which to sort
Produces:
    None, but the version of A sorted by digit d is stored in by
Preconditions:
    B is an array of integers
    B has the same length as A 
    n > 0 
    d > 1
Postconditions:
    No additional
 */

void
countingSortByD (int A[], int B[], int n, int d)
{
    int C[10];

    for (int i = 0; i < 10; i++)	// Initialize counting array
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)	// Count how many times each number appears
    {
        C[getDigit(A[i],d)]++;
    }

    for (int i = 1; i < 10; i++)	// Count how many elements are <= each number
    {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        B[C[getDigit(A[i],d)] - 1] = A[i]; // Place A[i] in correct spot in output
        C[getDigit(A[i],d)]--; // Mark that A[i] has been accounted for
    }
}

/*
Procedure:
    radixSort
Purpose:
    Sort an array of nonnegative integers in Theta(dn) time, where d is the most
    digits of an element in the array
Parameters:
    x, an array of nonnegative integers
    n, the length of x
Produces:
    None, but x is replaced with its sorted version
Preconditions and Postconditions:
    No additional
 */
void
radixSort (int x[], int n)
{
    int d = 0; // Most digits of element in x
    int input[n];  // Arrays for storing intermediate steps
    int output[n];

    for (int i = 0; i < n; i++)
    {
        int digits = (int) log10 (1.0 * x[i]) + 1;
        if (digits > d) {
	        d = digits;
	    }

        output[i] = x[i]; // Initialize output
    }
    
    for (int i = 1; i <= d; i++) // Stable sort by each digit
    {
        for (int i = 0; i < n; i++) // Copy output of previous iteration into the input
        {
            input[i] = output[i];
        }
        countingSortByD(input, output, n, i);
    }
    
    for (int i = 0; i < n; i++) // Copy output into x
    {
        x[i] = output[i];
    }
}

/*
Procedure:
    printArray
Purpose:
    Display an array of integers
Parameters:
    A, an array of integers
    n, the length of A 
Produces:
    None
 */
void
printArray (int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf ("%d ", A[i]);
    }
    printf ("\n");
}
