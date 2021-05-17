#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],w[maxn];
int n,suma,c1,c2,sum;


int main(){
    scanf("%d%d%d",&n,&c1,&c2);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]),sum+=w[i];
    sort(w+1,w+1+n);
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(suma+w[i]<=c1){
            a[cnt++]=w[i];
            suma+=w[i];
        }
    }
    if(sum-suma>c2){
        puts("NO solution!");
    }else{
        printf("A:");
        for(int i=1;i<cnt;i++) printf("%d ",a[i]);
        cout<<endl;
        printf("B:");
        for(int i=cnt;i<=n;i++){
            printf("%d%c",w[i]," \n"[i==n]);
        }
    }
    return 0;
}
/*
3 
50 50
10 40 40

*/