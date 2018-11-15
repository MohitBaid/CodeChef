#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,x,i,sum=0;	cin>>n>>x;
		int A[n];	
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			sum+=A[i];
		}	
		sort(A,A+n);
		int p=sum%x;
		int q=sum/x;
		if(n==1)
		{
			if(sum>=x)	printf("%d\n",q);
			else		printf("-1\n");
		}
		else
		{
			if(p==0)
			{
				int ans=sum/x;
				cout<<ans<<endl;
			}
			else
			{
				if(p>=A[0])
					printf("-1\n",sum/x);
				else	
					printf("%d\n",sum/x);
			}
		}
	}
}
