#include <cmath>
int balancedBTs(int n)
{
    // Write your code here
    if (n <= 1)
    {
        return 1;
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    // int ans = x*x + 2*x*y;
    int ans = (temp1 + temp2) % mod;
    return ans;
}