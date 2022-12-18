#include <iostream>
#include <algorithm>
using namespace std;
int pairSum(int *arr, int i,int j, int num)
{
	

int count=0;
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
int tripletSum(int *arr, int n, int num)
{ 
    sort(arr, arr + n);
    int numTriplets = 0; 
    for (int i = 0; i < n; i++) 
    {
        int pairSumFor = num - arr[i];
        int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor); 
        numTriplets += numPairs;
    }
    return numTriplets;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}
