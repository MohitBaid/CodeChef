#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		int st=n-n/2;
		for(i=st;i<st+n;i++)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
