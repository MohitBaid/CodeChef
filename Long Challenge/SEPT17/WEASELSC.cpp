#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T;	cin>>T;
	while(T--)
	{
		long long int n,i,k,s;	cin>>n>>k;
		long long int A[n],min=-1,ans=-1,temp;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
			if(min==-1)		min=A[i];
			if(A[i]<min)	min=A[i];
		}
		if(min==0)
		{
			min=-1,s=-1;
			for(i=0;i<n;i++)
			{
				if(A[i]!=0)
				{
					if(min==-1)		min=A[i];
					if(A[i]<min)	min=A[i];
				}
				else
				{
					temp=(i-s-1)*min;
					//cout<<temp<<" ";
					if(ans==-1)		ans=temp;
					if(ans<temp)	ans=temp;
					s=i;
					min=-1;
				}
			}
			temp=(i-s-1)*min;
			//cout<<temp<<" ";
			if(ans==-1)		ans=temp;
			if(ans<temp)	ans=temp;
			printf("%lld\n",ans);
		}
		else	printf("%lld\n",min*n);
	}
}
