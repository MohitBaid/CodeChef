#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int k,a,b;	cin>>k>>a>>b;
		if(a>b)
		{
			long long int temp=b;
			b=a;
			a=temp;
		}
		long long int l=b-a-1;
		long long int r=k-l-2;
		if(k<=3)		cout<<"0"<<endl;	
		else if(l==r)	cout<<"0"<<endl;
		else			cout<<min(l,r)<<endl;
	}
}
