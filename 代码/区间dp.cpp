#include<bits/stdc++.h>
#define ll long long 
#define dbg(x) cout<<#x<<"=="<<x<<endl;
#define bug printf("*********\n");
#define debug(x) cout<<"["<<x<<"]" <<endl;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrp(i,a,b) for(int i=b;i>=a;i--)
#define mem(a,b)   memset(a,b,sizeof a)
#define esp 1e-8
#define pr pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int maxn=3e5+5;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
inline ll rdll(){ll x = 0;ll  f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
inline int rd(){int x = 0;int f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
template <class T> void read(T &x) { T res = 0, f = 1;char c = getchar();while (!isdigit(c)) {if (c == '-') f = -1;c = getchar();} while (isdigit(c)) {res = (res << 3) + (res << 1) + c - '0';c = getchar();}x = res * f;}
int p[maxn];
int dp[1001][1001];
int s[1001][1001];
void print(int i, int j)
{
	if (i == j)
	{
		cout << "A[" << i << "]";
		return;
	}
	cout << "(";
	print(i, s[i][j]);
	print(s[i][j] + 1, j);//递归1到s[1][j]
	cout << ")";
}
void run(){
    int n=rd();
    rep(i,0,n) p[i]=rd();
    mem(dp,inf);
    rep(i,1,n) dp[i][i]=0;
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=len+l-1;
            dp[l][r]=dp[l][l]+dp[l+1][r]+p[l-1]*p[l]*p[r];
            s[l][r]=l;
            for(int k=l+1;k<r;k++){
                int t=dp[l][k]+dp[k+1][r]+p[l-1]*p[k]*p[r];
                if(dp[l][r]>t){
                    dp[l][r]=t;
                    s[l][r]=k;
                }
            }
        }
    }
    print(1,n);
    cout<<"\n";
    cout<<dp[1][n]<<" "<<s[1][n]<<endl;
}
signed main(){
    int _=1;    
    while(_--){
        run();
    }
}
/*
5
30 35 15 5 10 20


*/