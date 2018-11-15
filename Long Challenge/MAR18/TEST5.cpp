#include<bits/stdc++.h>
using namespace std;
set < string > s,ans,temp;
set < string > :: iterator st1,st2,st;
void gen(int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			string t="";
			for(k=0;k<i;k++)	t+='0';
			for(k=i;k<=j;k++)	t+='1';
			for(k=j+1;k<n;k++)	t+='0';
			s.insert(t);
		}
	}
}
void cal(int n,int k)
{
	for(st1=ans.begin();st1!=ans.end();st1++)
	{
		string z=*st1;
		for(st2=s.begin();st2!=s.end();st2++)
		{
			string t=*st2;
			string a="";
			for(int i=0;i<t.size();i++)
			{
				if(t[i]=='0')
				{
					a+=z[i];
				}
				else
				{
					a+=(k+48);
				}
			}
			temp.insert(a);
		}
	}
	ans.clear();
	for(st1=temp.begin();st1!=temp.end();st1++)
	{
		ans.insert(*st1);
	}
	temp.clear();
}
int an[100][100];
main()
{
	int n,k;
	for(n=1;n<=5;n++)	an[0][n]=0;
	for(n=1;n<=5;n++)
	{
		gen(n);
		//cout<<endl; 	for(st=s.begin();st!=s.end();st++)	cout<<*st<<endl;	cout<<endl;
		string a="";
		for(int i=0;i<n;i++)	a+='0';
		ans.insert(a);
		for(k=1;k<=5;k++)
		{
			cal(n,k);
			an[n][k]=ans.size();
			if(k)
			{
				cout<<n<<","<<k<<":";
				int z=ans.size();
				cout<<ans.size()<<" "<< (k+1)*an[n-1][k] << an[n-1][k-1] <<" "<<((k+1)*an[n-1][k]) +an[n-1][k-1]- z<<endl;
				//for(st=ans.begin();st!=ans.end();st++)	cout<<*st<<endl;	cout<<endl;
			}
		}
		s.clear();
		ans.clear();
	}
}
