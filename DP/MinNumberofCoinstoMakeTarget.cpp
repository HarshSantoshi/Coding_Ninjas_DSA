#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std ;

////Time complexcity is O(n^n)
// int solveByRecursion(vector<int>nums , int target){
//     //Base case
//      if(target==0){
//         return 0;
//     }
//     if(target<0){
//         return INT_MAX;
//     }
//     int count = INT_MAX;
 
//         for(int i=0;i<nums.size();i++){
//             int result = solveByRecursion(nums , target -nums[i]);
//             if(result!=INT_MAX){
//                 count = min(count , result +1);
//             }
//         }  
//         return count;
  
// }



//By Recursion and Memoization
// int solveByMemo(vector<int>&dp ,vector<int>&nums , int target){
//     //Base case
//      if(target==0){
//         return 0;
//     }
//     if(target<0){
//         return INT_MAX;
//     }
//     if(dp[target]!=-1){
//         return dp[target];
//     }
//     int count = INT_MAX;
 
//         for(int i=0;i<nums.size();i++){
//             int result = solveByMemo(dp ,nums , target -nums[i]);
//             if(result!=INT_MAX){
//                 count = min(count , result +1);
//             }
//         } 
//         dp[target] =count; 
//         return count;
  
// }

//By Tabulation 
int solveByTabu(vector<int>&nums , int target){
   vector<int>dp(target +1 , INT_MAX);
   dp[0]=0;
   for(int i=1;i<=target;i++){
    for(int j=0;j<nums.size();j++){
        if(i-nums[j] >=0 && dp[i-nums[j]]!=INT_MAX)
        dp[i]=min(dp[i] , 1+ dp[i - nums[j]]);
    }
   }
   if(dp[target]==INT_MAX){
    return -1;
   }
   return dp[target];
  
}

int minimumElements(vector<int>&nums , int target){
    //For recursive
    // int ans = solveByRecursion(nums ,  target);
    // if(ans==INT_MAX){
    //     return -1;
    // }
    // return ans;



    // //for memoization
    
    // vector<int> dp (target+1 , -1);
    // int ans = solveByMemo(dp , nums , target);
    // if(ans==INT_MAX){
    //     return -1;
    // }
    // else {
    //     return ans;
    // }

    //for tabulation 

    return solveByTabu(nums , target);


}
 int main(){

    int n;
    cin>>n;
    int a;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    int x;
    cin>>x;
    int ans = minimumElements(nums , x);
    cout<<ans;
 }