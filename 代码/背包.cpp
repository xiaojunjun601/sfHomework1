#include<bits/stdc++.h>
using namespace std;
int dp[100];
int w[100],v[100];
int main(){
    int n,V;
    cin>>n>>V;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V];
    
}
/*
5 10
1 2 3 4 5
5 4 3 2 1
*/