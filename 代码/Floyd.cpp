#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const int inf=0x3f3f3f3f;
int dis[maxn][maxn];
int n,m;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    int u,v,w;
    scanf("%d%d",&n,&m);
    memset(dis,inf,sizeof dis);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v]=w;
    }
    floyd();
    int q;
    cin>>q;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        cout<<dis[x][y]<<endl;
    }
}
/*
5 8
1 2 2
1 3 6
2 3 3
3 1 7
1 4 4
4 1 5
4 3 12
3 4 1
*/