#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,m,i,j,a1=0,a2=0;	cin>>n>>m;
		char c1[n][m],ch,c[n][m];
		ch='G';
		for(i=0;i<n;i++)
			cin>>c[i];
		for(i=0;i<n;i++)
		{
			if(ch=='G')	ch='R';
			else		ch='G';
			char ch2=ch;
			for(j=0;j<m;j++)
			{
				c1[i][j]=ch2;
				if(ch2=='G')	ch2='R';
				else			ch2='G';
			}
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cout<<c1[i][j]<<" ";
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(c[i][j]!=c1[i][j])
				{
					if(c[i][j]=='R')	a1+=5;
					else				a1+=3;
				}
			}
		}
		ch='H';
		for(i=0;i<n;i++)
		{
			if(ch=='G')	ch='R';
			else		ch='G';
			char ch2=ch;
			for(j=0;j<m;j++)
			{
				c1[i][j]=ch2;
				if(ch2=='G')	ch2='R';
				else			ch2='G';
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(c[i][j]!=c1[i][j])
				{
					if(c[i][j]=='R')	a2+=5;
					else				a2+=3;
				}
			}
		}
		cout<<min(a1,a2)<<endl;
	}
}
