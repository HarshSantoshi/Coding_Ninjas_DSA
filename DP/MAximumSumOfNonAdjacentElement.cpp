#include <bits/stdc++.h> 
// int solve (vector<int>&nums , int n){
//     //TC O(2^n);
//     //Base case
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return nums[0];
//     }
//     int incl= solve(nums , n-2 ) + nums[n];
//     int excl = solve (nums , n-1);
//     int ans = max(incl , excl);
//     return ans;
// }
// int solveMemo(vector<int>&nums , int n, vector<int> & dp){
//      if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return nums[0];
//     }
//     //Step 2
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     int incl = solveMemo(nums , n-2 , dp) + nums[n];
//     int excl = solveMemo(nums , n-1 , dp);
//     //Step 3
//     dp[n] =max(incl , excl);
//     return dp[n];
// }

//Tabulation 
// int solveTabo(vector<int>&nums , int n){
//     vector<int> dp (n , -1);
//     dp[0]=nums[0];
//     for(int i=1;i<n;i++){
//         int incl = dp[i-2] + nums[i];
//         int excl = dp[i-1] ;
//         dp[i] =max(incl , excl);
//     }
//     return dp[n-1];
// }

int bestSolve (vector<int>&nums ){
    int n = nums.size();
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return nums[0];
//     }
    
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i=1;i<n;i++){
        int incl = prev2 + nums[i];
        int excl = prev1;
        int ans = max(incl  ,  excl);
        prev2  = prev1 ;
        prev1 = ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
  //  Recursive Approach
//     int n= nums.size();
//     int ans = solve(nums , n-1);
//     return ans;
    
//     //Memoisation 
//     int n= nums.size();
//     //Step 1
//     vector<int>dp(n,-1);
//     int ans = solveMemo(nums , n-1 , dp);
//     return ans;
    
//     //By Tabulation 
//     int n = nums.size();
//     return solveTabo(nums , n);
    
    //Space Optimization 
    return bestSolve(nums);
}