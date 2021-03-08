#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define pdd pair<double,double>
#define mem(a,x) memset(a,x,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0)
#define dbg(x)   cout<<#x<<" == "<<x<<endl
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define PI acos(-1.0) 
#define ll long long
using namespace std;
//typedef long long ll;
const ll INF = 1e18+5;
const int inf = 0x3f3f3f3f; 
const ll mod= 1e9+7; 
const double eps=1e-6;       
const int maxn=1e3+6;      
inline ll rdll(){ll x = 0;ll  f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
inline int rd(){int x = 0;int f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
int n,m;
int fa[maxn];
struct node{
    int s,to,dis;
    bool operator<(const node &a)const{
        return dis<a.dis;
    }
}e[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void init(){
    rep(i,0,n) fa[i]=i;
}
int kruskal(){
    init();
    int sum=0;
    rep(i,1,m){
        int a=find(e[i].s);
        int b=find(e[i].to);
        if(a!=b){
            sum+=e[i].dis;
            fa[a]=b;
        }
    }
    return sum;
}
void run(){
    n=rd(),m=rd();
    rep(i,1,m) {
        int u=rd(),v=rd(),w=rd();
        e[i].s=u,e[i].to=v,e[i].dis=w;
    }
    sort(e+1,e+1+m);
    printf("%d\n",kruskal());
}
signed main()
{	
	
	int t=1;
	while(t--){
		run();
	} 
	// run();
	return 0;
}
/*
6 10
1 3 1
1 2 6
1 4 5
2 3 5
2 5 3
5 3 6
5 6 6
3 6 4
3 4 5
4 6 2
15
*/

