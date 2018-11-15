#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,d,i;	cin>>n>>d;
		long long int A[n];
		long long int sum=0;
		for(i=0;i<n;i++)	
		{
			cin>>A[i];
			sum+=A[i];
		}
		if(sum%n)	cout<<"-1\n";
		else
		{
			long long int temp=sum/n;
			long long int ans=0;
			for(i=0;i<n;i++)
			{
				if((i+d)<n)
				{
					if(A[i]>temp)
					{
						A[i+d]+=(A[i]-temp);
						ans+=(A[i]-temp);
						A[i]=temp;
					}
					else
					{
						A[i+d]-=(temp-A[i]);
						ans+=(temp-A[i]);
						A[i]=temp;
					}
				}
			}
			int flag=1;
			for(i=0;i<n;i++)
				if(A[i]!=temp)
				{
					flag=0;
					break;
				}		
			if(flag)	cout<<ans<<endl;
			else		cout<<"-1\n";	
		}
	}
}
