#include <bits/stdc++.h>
#include<cmath>

using namespace std;


int solve ( int n , vector<long>&dp){
     dp[0]= 1;
  dp[1]= 1;
    dp[2]=2;
    int mod =1000000007;
  for(int i=3; i<=n; i++){
      dp[i] = (dp[i-1]+ dp[i-2] +dp[i-3])%mod;
  }
  //cout<<dp[n] % abs(pow(10,9) +7)<<endl;

   cout<<dp[n]<<endl;
    }

int main() {

  int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
    

  vector<long> dp(n+1);
int ans = solve (n , dp);

 
}
}