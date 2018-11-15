#include<bits/stdc++.h>
using namespace std;
int prime(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)	return 0;
	}
	return 1;
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int x,y;	cin>>x>>y;
		int p=x+y+1;
		while(!prime(p))
		{
			p++;
		}
		cout<<p-x-y<<endl;
	}
}
