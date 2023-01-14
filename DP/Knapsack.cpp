
#include <iostream>
using namespace std;

// int solve(int *weight, int *values, int n, int maxWeight){
//     if(n==0){
//         if(weight[n]<=maxWeight){
// return values[0];}
//         else{
//             return 0;
//         }
//     }
//     int incl = 0;
//     if(weight[n]<=maxWeight){
//         incl = values[n] + solve(weight , values , n-1 , maxWeight - weight[n]);
//     }
//     int excl = solve(weight , values , n-1 , maxWeight);
    
//     return max(incl , excl);
// }

// int knapsack(int *weight, int *values, int n, int maxWeight)
// {
// 	//write your code here
//     int ans=  solve (weight , values , n-1 , maxWeight);
//     return ans;
// }





//Memoisation
// #include <vector>
// int solve(int *weight, int *values, int n, int maxWeight ,vector<vector<int>>&dp){
//     if(n==0){
//         if(weight[n]<=maxWeight){
// return values[0];
//        }
//         else{
//             return 0;
//         }
//     }
//     if(dp[n][maxWeight]!=-1){
//         return dp[n][maxWeight];
//     }
//     int incl = 0;
//     if(weight[n]<=maxWeight){
//         incl = values[n] + solve(weight , values , n-1 , maxWeight - weight[n] ,dp);
//     }
//     int excl = solve(weight , values , n-1 , maxWeight , dp);
    
//     dp[n][maxWeight] = max(incl , excl);
//     return dp[n][maxWeight];
// }

// int knapsack(int *weight, int *values, int n, int maxWeight)
// {
// 	//write your code here
//    vector<vector<int>>dp( n  , vector<int>(maxWeight+1 ,-1));
//     int ans=  solve (weight , values , n-1 , maxWeight , dp);
//     return ans;
// }




int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}