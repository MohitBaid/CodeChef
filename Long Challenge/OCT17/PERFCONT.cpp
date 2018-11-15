#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;		cin>>T;
	while(T--)
	{
		int n,p;	cin>>p>>n;
		int ck=0,hp=0;
		while(p--)
		{
			int k;	cin>>k;
			if(k>=n/2)	ck++;
			if(k<=n/10)	hp++;
		}
		if(ck==1 && hp==2)		cout<<"yes\n";
		else					cout<<"no\n";
	}
}
