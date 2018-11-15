#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int p,q,r,ans=0,i,temp1,temp2;	scanf("%lld %lld %lld",&p,&q,&r);
		long long int A[p],B[q],C[r],px[q],py[q],cx=0,cy=0;
		for(i=0;i<p;i++)		scanf("%lld",&A[i]);			sort(A,A+p);
		for(i=0;i<q;i++)		scanf("%lld",&B[i]);			sort(B,B+q);
		for(i=0;i<r;i++)		scanf("%lld",&C[i]);			sort(C,C+r);
		for(i=0;i<p&&cx<q;i++)
		{
			if(B[cx]<A[i])
			{
				px[cx]=i-1;
				cx++;
				i--;
			}
		}
		for(;cx<q;cx++)		px[cx]=p-1;
		for(i=0;i<r&&cy<q;i++)
		{
			if(B[cy]<C[i])
			{
				py[cy]=i-1;
				cy++;
				i--;
			}
		}
		for(;cy<q;cy++)		py[cy]=r-1;
		for(i=1;i<p;i++)	A[i]=(A[i]+A[i-1])%MOD;
		for(i=1;i<r;i++)	C[i]=(C[i]+C[i-1])%MOD;
		for(i=0;i<q;i++)
		{
			if(py[i]>=0&&px[i]>=0)
			{
				temp1=((((py[i]+1))*(B[i]%MOD)%MOD+C[py[i]])%MOD)%MOD;
				temp2=((((px[i]+1))*(B[i]%MOD)%MOD+A[px[i]])%MOD)%MOD;
				ans+=((temp1%MOD)*(temp2%MOD)%MOD)%MOD;
			}
			ans=ans%MOD;
		}
		printf("%lld\n",ans%MOD);
	}
}
