// https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1
// https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1


// Approach :
// Take all 1's it will be one case.
// Now try to make a 2 by combining two 1's...m/2

int nthStair(int n)
{
    return n / 2 + 1;
}