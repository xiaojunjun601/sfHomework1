#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e4+5;
int a[maxn];
void merge(int l,int r,int mid)//排序过程
{
    int aux[r-l+1],i,j;
    rep(k,l,r) aux[k-l]=a[k];
    i=l;
    j=mid+1;
    rep(k,l,r)
    {
        if(i>mid)
        {
            a[k]=aux[j-l];
            j++;
        }
        else if(j>r){
            a[k]=aux[i-l];
            i++;
        }
        else if(aux[i-l]>aux[j-l])
        {
            a[k]=aux[j-l];
            j++;
        }
        else
            {
            a[k]=aux[i-l];
            i++;
        }	    
    }	
}
void merge_sort(int l,int r)//归并
{
    if(l>=r)return ;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	merge(l,r,mid);	
}
int main()
{
    int n;
	scanf("%d",&n);
	rep(i,0,n-1) scanf("%d",&a[i]);
	merge_sort(0,n-1);
	rep(i,0,n-1) printf("%d%c",a[i]," \n"[i==n-1]);
	return 0;
 } 