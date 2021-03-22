#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+4;
int a[maxn];
int n;
int baoli(int x){
    for(int i=1;i<=n;i++){
        if(a[i]==x)  return i;
    }
    return 0;
}
int erfen(int x){
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]==x) return mid;
        else if(a[mid]>x) r=mid;
        else l=mid+1;
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int x;
    scanf("%d",&x);
    int pos1=baoli(x);
    int pos2=erfen(x);
    printf("%d %d\n",pos1,pos2);
    return 0;
}
/*
9
1 2 3 4 5 6 7 8 9
4
*/