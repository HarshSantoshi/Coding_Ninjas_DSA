#include <bits/stdc++.h>
using namespace std;
#include<cmath>
#include<climits>
int countMinStepsToOne(int n)
{
    // Write your code here
   //Base case 
    if (n<=1){
return 0;}
    
    //Recursion 
    int x = countMinStepsToOne(n-1);
    int y =INT_MAX, z =INT_MAX;
    if(n%2==0){

    y = countMinStepsToOne(n/2);}
    
    if (n%3==0){

    z = countMinStepsToOne(n/3);}
    
    return 1 + min(x,min(y,z));
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}