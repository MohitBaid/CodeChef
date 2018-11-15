#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t,c=0;	cin>>n;
	while(n--)
	{
		cin>>t;
		if(t%2)	c--;
		else	c++;
	}
	if(c>0)	cout<<"READY FOR BATTLE\n";
	else	cout<<"NOT READY\n";
}
