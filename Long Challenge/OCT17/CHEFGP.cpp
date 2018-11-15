#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		string s;	cin>>s;
		int a=0,b=0,x,y,i;	cin>>x>>y;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='a')	a++;
			else			b++;
		}
		if(a>b)
		{
			int grp=b+1;
			if(a<=grp*x)
			{
				int k2=ceil(a*1.0/grp);
				while(a>k2)
				{
					for(i=0;i<k2;i++)	cout<<"a";
					cout<<"b";
					a-=k2;
					b--;
					grp--;
					k2=ceil(a*1.0/grp);
				}
			}
			else
			{
				while(a>x)
				{
					for(i=0;i<x;i++)	cout<<"a";
					if(b)
					{
						cout<<"b";
						b--;
					}
					else	cout<<"*";	
					a-=x;
				}
			}
			while(a--)		cout<<"a";
		}
		else if(b>a)
		{
			int grp=a+1;
			if(b<=grp*y)
			{
				int k2=ceil(b*1.0/grp);
				while(b>k2)
				{
					for(i=0;i<k2;i++)	cout<<"b";
					cout<<"a";
					b-=k2;
					a--;
					grp--;
					k2=ceil(b*1.0/grp);
				}
			}
			else
			{
				while(b>y)
				{
					for(i=0;i<y;i++)	cout<<"b";
					if(a)
					{
						cout<<"a";
						a--;
					}
					else	cout<<"*";	
					b-=y;
				}
			}
			while(b--)		cout<<"b";
		}
		else	for(i=0;i<a;i++)	cout<<"ab";
		cout<<endl;
	}
}
