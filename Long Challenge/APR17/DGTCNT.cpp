#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int l,r;	scanf("%lld %lld",&l,&r);
		int A[10];
		int c=0;
		for(int i=0;i<10;i++)
		{
			scanf("%d",&A[i]);
			if(A[i]==0)
				c++;
		}
		if(c!=10)
		{
			int ans=0;
			for(int i=l;i<=r;i++)
			{
				int k=i;
				int C[10]={0};
				while(k>0)
				{
					C[k%10]++;
					k=k/10;
				}
				int flag=0;
				for(k=0;k<10;k++)
					if(C[k]==A[k])
					{
						flag=1;
						break;
					}
				if(!flag)
					ans++;	
			}
			printf("%d\n",ans);
		}
		else
		{
			long long int k=l;
			int l1=0,l2=0;
			while(k>0)
			{
				k=k/10;
				l1++;
			}
			int L[l1];
			int f=l1-1;
			while(l>0)
			{
				int d=l%10;
				L[f--]=d;
				l=l/10;
			}
			k=r;
			while(k>0)
			{
				k=k/10;
				l2++;
			}
			int R[l1];
			f=l2-1;
			while(l>0)
			{
				int d=r%10;
				R[f--]=d;
				r=r/10;
			}	
			int ans=0;
			do
			{
				ans++;
				int flag=1;
				for(int i=0;i<l1;i++)
					if(L[i]!=R[i])
					{
						flag=0;
						break;
					}
				if(flag)
					break;	
			}while(next_permutation(L,L+l1));
		}
	}
}
