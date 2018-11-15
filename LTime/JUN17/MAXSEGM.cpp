#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		int A[n+1],B[n],W[n+1],S[n];
		for(i=0;i<n;i++)	B[i]=-1;
		long long int ans=0,max=0;
		for(i=0;i<n;i++)	scanf("%d",&A[i]);		
		for(i=0;i<n;i++)	scanf("%d",&W[i]);	
		S[0]=W[0];int flag=0,p=-1,flag2=0;
		for(i=1;i<n;i++)		S[i]=S[i-1]+W[i];
		for(i=0;i<n;i++)
		{
			if(B[A[i]]==-1)		
			{	
				B[A[i]]=i;
				if(i==n-1)				flag2=1;
			}
			else
			{
				if(B[A[i]]==0)	max=S[i-1];
				else			max=S[i-1]-S[B[A[i]]-1];	
				if(ans<max)		ans=max;
				
				max=S[i]-S[B[A[i]]];
				
				if(ans<max)		ans=max;
				p=B[A[i]];
				B[A[i]]=i;		
				flag=1;
			}
			cout<<ans<<" "<<i<<endl;
		}
		
		if(!flag)
			ans=S[n-1];
		else
		{
			if(flag=2)
				ans+=W[n-1];
		}	
		printf("%lld\n",ans);
	}
}
