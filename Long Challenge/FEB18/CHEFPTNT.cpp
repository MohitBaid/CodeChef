#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,m,x,k,i;	cin>>n>>m>>x>>k;
		string s;	cin>>s;
		int e=0,o=0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='E')	e++;
			else			o++;
		}
		for(i=1;i<=m;i++)
		{
			if(i%2==0)
			{
				int w=min(x,e);
				n-=w;
				e-=w;
			}
			else
			{
				int w=min(x,o);
				n-=w;
				o-=w;
			}
		}
		if(n<=0)	cout<<"yes\n";
		else		cout<<"no\n";
	}
}
