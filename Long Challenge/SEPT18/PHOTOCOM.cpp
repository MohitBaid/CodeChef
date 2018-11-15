#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T	;	cin>>T;
	while(T--)
	{
		int h1,w1,h2,w2,i,j,i2;	
		string a,b;
		cin>>h1>>w1>>a>>h2>>w2>>b;
		int rows = h1*h2/__gcd(h1,h2);
		int cols = w1*w2/__gcd(w1,w2);
		string s1[35],s2[35],s3[1000],s4[1000],s5[1000],s6[1000];
		for(i=0;i<h1;i++)
		{
			string g="";
			for(j=0;j<w1;j++)
			{
				g = g+a[i*w1 +j];
			}
			s1[i]=g;
			g="";
		}
		
		for(i=0;i<h2;i++)
		{
			string g="";
			for(j=0;j<w2;j++)
			{
				g = g+b[i*w2 +j];
			}
			s2[i]=g;
			g="";
		}
		int k = rows/h1;
		for(i=0;i<h1;i++)
		{
			for(j=0;j<k;j++)
			{
				s3[i*k + j] = s1[i];
			}	
		}
		k=rows/h2;
		for(i=0;i<h2;i++)
		{
			for(j=0;j<k;j++)
			{
				s4[i*k + j] = s2[i];
			}	
			
		}
		k = cols/w1;
		for(i=0;i<rows;i++)
		{
			string g="";
			for(i2=0;i2<s3[i].size();i2++)
			{
				for(j=0;j<k;j++)
				{
					g=g+s3[i][i2];
				}
			}
			s5[i]=g;
		}
		
		k=cols/w2;
		for(i=0;i<rows;i++)
		{
			string g="";
			for(i2=0;i2<s4[i].size();i2++)
			{
				for(j=0;j<k;j++)
				{
					g=g+s4[i][i2];
				}
			}
			s6[i]=g;
		}
		int ans = 0;
		for(i=0;i<rows;i++)
		{
			for(j=0;j<cols;j++)
			{
				if(s5[i][j]==s6[i][j])
					ans++;
			}
		}
		
		cout<<ans<<endl;
	}
}
