#include<bits/stdc++.h>
using namespace std;

int knapsackdp(vector<int>& weights,vector<int>& value,int capacity,int n){
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if(weights[i-1]<=j) dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i-1][j-weights[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][capacity];
}

int main(){
    int n=4;
    int capacity=9;
    vector<int> value={3,4,5,6};
    vector<int> weights={2,3,4,5};
    cout<<knapsackdp(weights,value,capacity,n)<<endl;
}