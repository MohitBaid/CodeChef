#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		if(n>=3)
		{
			for(i=1;i<=n-3;i=i+2)
			{
				cout<<i+1<<" "<<i<<" ";
			}
			n=n-3;
			if(n%2==0)	cout<<n+2<<" "<<n+3<<" "<<n+1<<endl;
			else		cout<<n+3<<" "<<n+2<<endl;
		}
		else 
		{
			cout<<"2 1\n";
		}
	}
}
