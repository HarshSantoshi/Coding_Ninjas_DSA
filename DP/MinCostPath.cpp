//Recursion
#include<bits/stdc++.h>
int solve(int**input , int i , int j , int row , int col){

	if(i>=row || j>=col){
		return INT_MAX ;
	}
	
	if(i==row-1  &&j==col-1 )return input[i][j];
	int res = min(solve(input  , i+1 , j, row , col) , min(solve(input,i,j+1 , row , col) ,solve(input , i+1,j+1, row , col) ))+input[i][j];
	return res;
}
int minCostPath(int **input, int m, int n)
{
	//Write your code here

	int ans = solve(input , 0 , 0 , m ,  n);
}