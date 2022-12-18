#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    //Write your code here
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=input[i];
    }
    for(int j=0;j<n-d;j++){
        input[j]=input[j+d];
    }
    for(int k=n-d,i=0;k<n,i<d;k++,i++){
        input[k]=temp[i];
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
