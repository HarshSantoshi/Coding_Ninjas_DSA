#include <iostream>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
int pairSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr , arr+n);
 
    int count=0;
    int i=0,j=n-1;
while(i<j){

if(arr[i]+arr[j]>num){
    j--;
}
else if(arr[i]+arr[j]<num){
    i++;
}
else if(arr[i]+arr[j]==num)
{
    int sele =arr[i];
    int eele=arr[j];
    
if(eele==sele){
    
    int total=(j-i)+1;
    count+=(total*(total-1)/2);
    return count;
}
    int p=i+1,q=j-1;
    while(p<=q&&arr[p]==sele)
    {
        p++;
    }
    while(q>=p&&arr[q]==eele)
    {
        q--;
    }
    int totaleles=(p-i);
    int totalelee=(j-q);
    count+= totaleles*totalelee;
    i=p;
    j=q;
}
}
    return count;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}
