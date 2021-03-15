#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int maxn=1e3+4;
const int inf=0x3f3f3f3f;
int g[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int n,m;
void init(){
    memset(g,inf, sizeof g);
    rep(i,1,n){
        g[i][i]=0;
    }
}
void dijkstra(int a){
    memset(vis,0,sizeof vis);
    rep(i,1,n){
        dis[i]=g[a][i];
    }
    vis[a]=1;
    rep(i,1,n-1){
        int minn=inf,k;
        rep(j,1,n){
            if(!vis[j]&&minn>dis[j]){
                minn=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        rep(j,1,n){
            if(g[k][j]+dis[k]<dis[j]){
                dis[j]=g[k][j]+dis[k];
            }
        }
    }
}
int main(){
    init();
    char u,v;
    int w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
       cin>>u>>v>>w;
       int x=u-'a'+1,y=v-'a'+1;
       g[x][y]=w;
    }
    int q;
    cin>>q;
    while(q--){
        char x,y;
        cin>>x>>y;
        int a=x-'a'+1,b=y-'a'+1;
        dijkstra(a);
        cout<<dis[b]<<endl;
    }

    return 0;
}
/*
8 11
a b 1
b d 2
c a 2
d c 1
d f 8
e d 2
f e 2
e g 2
g f 3
g h 3
h f 2
1
a h

*/