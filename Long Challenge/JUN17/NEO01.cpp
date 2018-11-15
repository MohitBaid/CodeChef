#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int n,i,ans=0,p=1,max;	scanf("%lld",&n);
		long long int A[n];
		for(i=0;i<n;i++)			scanf("%lld",&A[i]);
		sort(A,A+n);
		max=A[n-1];
		for(i=n-2;i>=0;i--)
		{
			if((max/p+A[i])*(p+1)>=max)
			{
				max=(max/p+A[i])*(p+1);
				p++;
			}
			else
				break;
		}
		for(;i>=0;i--)
			max+=A[i];
		printf("%lld\n",max);	
	}
}
