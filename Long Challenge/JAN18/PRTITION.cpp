#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,x,i;	cin>>x>>n;
		long long int sum=n*(n+1)/2;
		char s[n];
		for(i=0;i<n;i++)	s[i]='0';
		s[x-1]='2';
		sum-=x;
		if(sum%2==1 || n==2)		cout<<"impossible"<<endl;
		else
		{
			sum=sum/2;
			long long int m=n;
			while(sum>0 && m>=0)
			{
				if(m==x)	m--;
				if(sum>=m && sum-m!=x)
				{
					sum-=m;
					s[m-1]='1';
				}
				m--;
			}
			if(sum==0)
			{	
				for(i=0;i<n;i++)
					cout<<s[i];
				cout<<endl;
			}
			else
			{
				cout<<"impossible"<<endl;
			}
		}
	}
}
