#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using  namespace std;
const int maxn=1e5+8;
int s1[maxn],s2[maxn],a[maxn],mid[maxn];
int select(int num[],int p,int r,int k){
	int len=r-p+1;
	//当前小于等于五个元素直接排序求第k小 
	if(len<=5){
		sort(num,num+len);
		return num[k-1];
	}else{
		//将数组分组，五个一组
	    int group=len/5;
		int m=len-group*5; //剩下的元素赋值给m
		rep(i,0,group-1){ //分组排序 
			sort(num+i*5,num+i*5+5);
			mid[i]=num[i*5+2];
		}
		if(m>0){
			sort(num+group*5,num+group*5+m);
			mid[group]=num[group*5+m/2];
			group++;
		}
		sort(mid,mid+group);
		int mm=mid[group/2];
		int len1=0,len2=0;
		//用mm把数组分为s1和s2
		rep(i,p-1,r-1){
			if(num[i]<mm){
				s1[len1++]=num[i];
			}else s2[len2++]=num[i];
		}
		int ans=0;
		if(k==len1+1) ans=mm;
		else if(k<=len1) ans=select(s1,1,len1,k);
		else ans=select(s2,1,len2,k-len1);
		return ans;
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n-1) scanf("%d",&a[i]);
	printf("%d\n",select(a,1,n,k));
	return 0;
}
