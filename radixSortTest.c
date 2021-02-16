/* Academic Honesty Certification
 * Written sources used: Introduction to Algorithms 3rd ed.
 *
 * Help obtained: None
 *
 * My written or typed signature below confirms that the above list 
 * of sources is complete. 
 *
 * Signature: Joshua Turner
 */
 
#include <stdio.h>
#include <assert.h>

int
main ()
{
    /// Trivial Arrays ///
    int a1[] = {};              // Empty
    int b1[] = {};
    assert(radixTest(a1,b1,0));
    
    int a2[] = {1};             // Singleton
    int b2[] = {1};
    assert(radixTest(a2,b2,1));
    
    int a3[] = {1,1,1};         // Only one unique element
    int b3[] = {1,1,1};
    assert(radixTest(a3,b3,3));
    
    int a4[] = {1,2,3,4,5};     // Already sorted
    int b4[] = {1,2,3,4,5};
    assert(radixTest(a4,b4,5));
    
    /// Same Number of Digits ///
    int a5[] = {5,4,3,2,1};             // Reverse sorted order
    int b5[] = {1,2,3,4,5};
    assert(radixTest(a5,b5,5));
    
    int a6[] = {64,12,59,43,72,11,99};  // Double digit 
    int b6[] = {11,12,43,59,64,72,99};
    assert(radixTest(a6,b6,7));
    
    int a7[] = {873,574,217,975,890,720,302,881,703,860,539};   // Triple digit
    int b7[] = {217,302,539,574,703,720,860,873,881,890,975};
    assert(radixTest(a7,b7,11));
    
    int a8[] = {22351,67043,30945,49566,54984,67044};   // 5 digits
    int b8[] = {22351,30945,49566,54984,67043,67044};
    assert(radixTest(a8,b8,6));
    
    /// Varying Number of Digits ///
    int a9[] = {920,79,70,695,982,802,8,486};
    int b9[] = {8,70,79,486,695,802,920,982};
    assert(radixTest(a9,b9,8));
    
    int a10[] = {10,1,1000,10000,100,1,10,100,1000}; // Duplicates
    int b10[] = {1,1,10,10,100,100,1000,1000,10000};
    printf("All tests passed!\n");
    
    return 0;
}

int radixTest(int input[], int expected[], int n)
{
    radixSort(input, n);
    return arrayEqual(input, expected, n);
}

int arrayEqual(int a1[], int a2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a1[i] != a2[i])
        {
            return 0;    
        }
    }
    return 1;
}