#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ;
    cin>>n;
    vector<int>days ;
    int day;
    for(int i=0;i<n;i++){
        cin>>day;
        days.push_back(day);
    }
    vector<int>price;
    int a;
    for(int i=0;i<2;i++){
        cin>>a;
        price.push_back(a);
    }

}