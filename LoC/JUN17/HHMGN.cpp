#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int n,i,j=0;	long long int s,sum=0;	cin>>n>>s;
		long long int A[n],ans=0,flag=0,temp;	
		for(i=0;i<n;i++)	
		{
			cin>>A[i];
			sum+=A[i];
		}
		if(sum<s)		printf("-1\n");
		else
		{
			sum=0;
			sort(A,A+n);
			for(i=0;i<n;i++)
			{
				temp=s/(n-i);
				if(temp==A[i])
				{
					if(s==temp*(n-i))
						{
							ans=temp;
							flag=1;
							break;
						}
				}	
				s-=A[i];	
			}
			if(flag)	printf("%lld\n",ans);
			else		printf("-1\n");	
		}
	}	
}
