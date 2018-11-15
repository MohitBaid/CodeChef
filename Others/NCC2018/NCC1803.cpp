#include<bits/stdc++.h>
using namespace std;
int prime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)	
			return 0;	
	}
	return 1;
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		int A[n];
		for(i=0;i<n;i++)
		{	
			cin>>A[i];
		}	
		if(n==1)	cout<<"Shivam\n";
		else if(n==2 )
		{
			if(__gcd(A[0],A[i])==1 || A[0]==A[1])
			{
				cout<<"Shivam\n";
			}
			else
			{
				cout<<"Sagar\n";
			}
		}
		else cout<<"Sagar\n";
		
	}
}
