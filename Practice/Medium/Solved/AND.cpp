#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int n,i,j;	cin>>n;
	int A[n],ans=0;
	map <int,int > mp;
	for(i=0;i<n;i++)
		cin>>A[i];
	int C[30]={0};
	int P[30]={0};
	P[0]=1;
	for(i=1;i<30;i++)
	{
		P[i] = P[i-1] * 2;
	}
	int num = A[n-1];
	for(i=29;i>=0;i--)
	{
		int d = num / P [i];
		num -= P[i]*d;
		C[i]+=d;
	}
	//cout<<A[n-1]<<": ";	 for(j=0;j<30;j++)	cout<<C[j]<<" ";	cout<<endl;
	for(i=n-2;i>=0;i--)
	{
		//cout<<A[i]<<": ";	 
		for(j=29;j>=0;j--)
		{
			int d = A[i] / P[j];
			A[i] -= d*P[j];
			if(d!=0)
			{
				ans = ans + C[j]*P[j];
				C[j] +=d;
			}
		}
		//for(j=0;j<30;j++)	cout<<C[j]<<" ";	cout<<endl;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
