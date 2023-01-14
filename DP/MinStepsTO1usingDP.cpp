#include <bits/stdc++.h>
using namespace std;
#include<cmath>
#include<climits>

#include<cmath>
#include<climits>

int Helper(int n , int * arr){
    
    if(n<=1){
return 0;}
    
    if(arr[n]!=-1){
return arr[n];}
    
    int x = Helper(n-1 ,arr);
    int y=INT_MAX, z=INT_MAX;
    if(n%2==0){
        y=Helper(n/2,arr);
    }
    
    if(n%3==0){
        z= Helper(n/3 , arr);
    }
    
    int output = min(x , min(y,z)) +1;
    
    arr[n]=output;
    return arr[n];
}
int countStepsToOne(int n)
{
    int *arr = new int [n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    
    Helper(n,arr);
}

int main()
{
    int n;
    cin >> n;
    cout << countStepsToOne(n);
}