#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	while(T--)
	{
		string s,l,r;
		cin>>s;
		char ch='.';
		for(i=0;i<s.size();i++)
		{
			if(s[i]!='.')
				ch=s[i];
			l+=ch;
		}
		ch='.';
		for(i=s.size()-1;i>=0;i--)
		{
			if(s[i]!='.')
				ch=s[i];
			r+=ch;	
		}
		//cout<<l<<" "<<r<<endl;
		int a=0,b=0;
		for(i=0;i<s.size();i++)
		{
			if(l[i]==r[s.size()-1-i])
			{
				if(l[i]=='A')	a++;
				if(l[i]=='B')	b++;
			}
		}
		cout<<a<<" "<<b<<endl;
	}
}
