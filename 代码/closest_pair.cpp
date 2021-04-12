#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrp(i,a,b) for(int i=b;i>=a;i--)
#define ll long long
using namespace std;
inline ll rdll(){ll x = 0;ll  f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
inline int rd(){int x = 0;int f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
template <class T> void read(T &x) { T res = 0, f = 1;char c = getchar();while (!isdigit(c)) {if (c == '-') f = -1;c = getchar();} while (isdigit(c)) {res = (res << 3) + (res << 1) + c - '0';c = getchar();}x = res * f;}
const double inf=1e20;
const int maxn=1e5+5;
struct Point{
    double x,y;
    bool operator<(const Point &a){
        if(x==a.x) return y<a.y;
        return x<a.x;
    }
}p[maxn];
bool cmpy(int &a,int &b){
    return p[a].y<p[b].y;
}
int n,mp[maxn];
double dis(int i ,int j){
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
}
double dfs(int l,int r){
    double dmin=inf;
    if(l==r) return dmin;
    if(l+1==r) return dis(l,r);
    int mid=(l+r)>>1;
    double d1=dfs(l,mid);
    double d2=dfs(mid+1,r);
    dmin=min(d1,d2);
    int cnt=0;
    rep(i,l,r){
        if(fabs(p[mid].x-p[i].x)<=dmin)  mp[cnt++]=i;
    }
    sort(mp,mp+cnt,cmpy);
    rep(i,0,cnt-1){
        rep(j,i+1,cnt-1){
            if(p[mp[j]].y-p[mp[i]].y<dmin) break;
            double d3=dis(mp[i],mp[j]);
            dmin=min(dmin,d3);
        }
    }
    return dmin;
}
double baoli(){
    double dmin=inf;
    rep(i,0,n-1){
        rep(j,i+1,n-1){
            dmin=min(dmin,dis(i,j));
        }
    }
    return  dmin;
}
void run(){
    n=rd();
    rep(i,0,n-1){
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }
    sort(p,p+n);
    printf("%lf\n",dfs(0,(n-1)/2));
    printf("%lf",baoli());
}
signed main(){
    int t=1;
    while(t--){
        run();
    }
    return 0;
}
/*
10
0 0
1 1
2 3
3 0
4 0
5 9
2 4
8 8
1 0
4 2
*/