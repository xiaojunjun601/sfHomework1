#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+8;
int dp[100][100];
string s1,s2;
int main(){
    cin>>s1>>s2;
    int len1=s1.size(),len2=s2.size();
    for(int i=1;i<=len1;i++) dp[i][0]=0;
    for(int i=1;i<=len2;i++) dp[0][i]=0;
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else  dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    } 
    cout<<dp[len1][len2]<<endl;
    stack<char>s;
    int i=len1,j=len2;
    while(dp[i][j]){    
        if(dp[i][j]==dp[i-1][j]) i--;///来自于左方向
        else if(dp[i][j]==dp[i][j-1])  j--; ///来自于上方向
        else if(dp[i][j]>dp[i-1][j-1])///来自于左上方向
        {
            i--,j--;
            s.push(s1[i]);
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<"\n";
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++) printf("%d%c",dp[i][j]," \n"[j==len2]);
}

/*
ABCBDAB
BDCABA
 */
