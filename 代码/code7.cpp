#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int a[100][100];
int n,m;
void run(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j],dp[i][j]=a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]=max(dp[i-1][j-k]+a[i][k],dp[i][j]);
               
            }
        }
    }    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[n][m]<<endl;
}
signed main(){
   run();
   return 0;
}
/*
4 5
11 12 13 14 15
0 5 10 15 20
2 10 30 32 40
20 21 22 23 24
*/