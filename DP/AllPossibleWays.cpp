
#include<math.h>
#include <bits/stdc++.h>
int helper(int x, int n, int curNo, int *dp) {
  if (x < 0) {
    return 0;
  }
  if (x == 0) {
    return 1;
  }

  int ans = 0;

  for (int i = curNo; pow(i, n) <= x; i++) {
    ans += helper(x - pow(i, n), n, i + 1, dp);
  }
  dp[x] = ans;
  return ans;
}
int getAllWays(int x, int n) {
  int dp[100001];

memset(dp,-1,sizeof(dp));
  return helper(x, n, 1, dp);
}
