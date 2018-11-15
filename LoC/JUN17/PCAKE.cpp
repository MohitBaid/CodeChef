#include<bits/stdc++.h>
using namespace std;
int mp[100][1001];
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,i,j,k,temp;				scanf("%lld",&n);
		long long int ans=0;
		int A[n];int P[n],m=0;
		for(i=0;i<n;i++)		
		{
			scanf("%d",&A[i]);
			if(A[i]==2)						P[m++]=i;
		}
		if(n<100)
		{
			for(i=0;i<n;i++)
			{
				for(j=2;j<=1000;j++)
				{
					int d=0;
					if(A[i]%j==0)
					{
						while(A[i]%j==0)
							d++,A[i]=A[i]/j;	
					}
					mp[i][j]=d;
				}
			}
			for(i=1;i<n;i++)
				for(j=0;j<=1000;j++)
					mp[i][j]+=mp[i-1][j];				
			for(i=0;i<n;i++)
			{
				ans++;
				for(j=0;j<=1000;j++)
					if(mp[i][j]>1)
					{
						ans--;
						break;
					}
			}			
			for(i=0;i<n;i++)
			{
				for(k=i+1;k<n;k++)
				{
					int A[1001],f=1;
					for(j=0;j<=1000;j++)			A[j]=mp[k][j]-mp[i][j];
					ans++;
					for(j=0;j<=1000;j++)
						if(A[j]>1)
						{
							ans--;
							break;
						}
				}
			}
			printf("%lld\n",ans);
		}
		else
		{
			if(m>=2)
			{
				for(i=1;i<m;i++)
				{
					if(i>=2)					temp=P[i]-P[i-2]-1;
					else						temp=P[i];
					ans+=(temp*(temp+1))/2;
				}
				temp=n-P[m-2]-1;
				ans+=(temp*(temp+1))/2;
				//cout<<ans<<endl;
				for(i=1;i<m;i++)
				{
					temp=P[i]-P[i-1]-1;
					//cout<<P[i]<<" "<<P[i-1]<<" "<<temp<<endl;
					ans-=(temp*(temp+1))/2;
				}
				
			}
			else								ans=(n*(n+1))/2;
			printf("%lld\n",ans);
		}
	}
}
//}
