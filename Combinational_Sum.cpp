 #include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 void solve(vector<int>&A , int B ,vector<vector<int>>&ans, int i ,vector<int>&v){
       if(B==0){
           ans.push_back(v);
           return ;
       }
       if(i==A.size()){
           return ;
       }
       while(i<A.size() && B -A[i]>=0){
           v.push_back(A[i]);
           solve(A,B-A[i] ,ans , i , v);
           i++;
           v.pop_back();
       }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin() ,A.end());
        set<int>s(A.begin() ,A.end());
        A.assign(s.begin(),s.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(A,B,ans, 0 ,v);
        return ans;
    }
    int main(){
        int n ;
        cin>>n;
        vector<int>A;
        for(int i=0;i<n;i++){
            int x ;
            cin>>x;
            A.push_back(x);
        }
        int sum ;
        cin>>sum;
        vector<vector<int>>ans = combinationSum(A,sum);
        for(int i=0;i<ans.size();i++){
            cout<<"(";
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j];
                if(j<ans[i].size()-1){
                    cout<<" ";
                }
            }
            cout<<") ";
            cout<<endl;
        }
    }
