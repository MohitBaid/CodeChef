#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int k,d0,d1,sum=0,d2,i;
		cin>>k>>d0>>d1;
		d2=(d0+d1)%10;
		sum=d0+d1+d2;
		long long int A[4];
		for(i=0;i<4;i++)
		{
			A[i]=sum%10;
			sum+=A[i];
		}
		sum=d0+d1+d2;
		if(k<3)
		{
			sum=d0+d1+d2;
			if(sum%3==0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
		{
			k-=3;
			long long int q=k/4;
			long long int r=k%4;
			sum+=(A[0]+A[1]+A[2]+A[3])*q;
			for(i=0;i<r;i++)
			{
				sum+=A[i];
			}
			if(sum%3==0)
				cout<<"YES\n";
			else
				cout<<"NO\n";	
		}
		
	}
}
