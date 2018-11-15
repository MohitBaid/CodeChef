#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
int m;
map<int,int> mp[100000];
map<int,int> ind;
void seive()
{
    isprime[0] = isprime[1] = 1 ;
    for (int i=2; i<MAX_SIZE ; i++)
    {
	    if (!isprime[i])
        {
            prime[m++]=i;
            SPF[i] = i;
        }
        for (int j=0;j<m && i*prime[j]<MAX_SIZE && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=1;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
    for(int i=0;i<m;i++)
    	ind[prime[i]]=i;
}
int main()
{
	seive();
	int check[100000]={0};
	int n,q,i,d=0,j;	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)		scanf("%d",&A[i]);
	for(i=0;i<n;i++)
	{
		int num=A[i];
		int ctr=0;
		while(num!=1)
		{
			int x=ind[SPF[num]];
			if(i!=0)
				mp[i][x]=mp[i-1][x]+1;
			else	
				mp[i][x]++;
			check[x]=1;
			num=num/SPF[num];
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int x,y,l,r;	scanf("%d %d %d %d",&l,&r,&x,&y);
		int px=0,py=m-1,ans=0;
		l--;
		r--;
		while(1)
		{
			if(prime[px]>=x)		break;
			px++;	
		}
		while(1)
		{
			if(prime[py]<=y)		break;
			py--;	
		}	
		for(i=px;i<=py;i++)
			if(check[px])
				for(j=l;j<=r;j++)
					ans+=mp[j][i];
		printf("%d\n",ans);
	}
	return 0;
}
