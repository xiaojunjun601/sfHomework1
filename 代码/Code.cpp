/*
jun xiao 
2021/5/26 14:57:23;
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int t[maxn];
int dp[maxn][maxn];
int path[maxn][maxn];
bool vis[maxn];
//递归输出可能的一种方案
void dfs(int n, int s)
{
    if(s==0)
        return;
    if(s<t[n]) 
    {
        dfs(n-1, s);   
    }
    else
    {
        if(s==dp[n-1][s-t[n]]+t[n])
        {
            dfs(n-1, s-t[n]);
            printf("%d ",n);
            vis[n]=1;
        }
        else
        {
            dfs(n-1, s);
        }
    }
}

int main()
{
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i],sum+=t[i];
    int mid=sum/2;  //背包的最大容量；
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=mid;j++)
        {
            if(j-t[i]>=0)
            {
                if(dp[i][j]<dp[i-1][j-t[i]]+t[i]) dp[i][j]=dp[i-1][j-t[i]]+t[i];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    // int ans=mid;          // for循环输出方案
    // for(int i=n;i>=1;i--){
    //     if(ans>=t[i]&&ans==dp[i][ans-t[i]]+t[i]){
    //      ans-=t[i];
    //      vis[i]=1;
    //      printf("%d%c",i,ans==0?'\n':' ');
    //     }
    // }
     
    cout<<"Possible solutions for the first machine:";
    dfs(n,dp[n][mid]);    //递归输出方案；
    puts("");
    cout<<"Possible solutions for the second machine:";
    for(int i=1;i<=n;i++){
        if(!vis[i]) cout<<i<<" ";
    }
    puts("");
    cout<<"The answer is "<<sum-dp[n][mid];
    
}
/*
5
1 5 2 10 3

*/