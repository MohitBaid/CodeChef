//https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/
#include <bits/stdc++.h>
using namespace std;
string chef="chef";
int count(string a, string b)
{
    int m = a.length();
    int n = b.length();
    int lookup[257][5] = { { 0 } };
    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] + 
                               lookup[i - 1][j];        
            else
                lookup[i][j] = lookup[i - 1][j];
        }
    }
    return lookup[m][n];
}
string reduce(string ch)
{
	int c=0,i;
	string a;
	for(i=0;i<ch.size();i++)
	{
		if(ch[i]=='c')
		{
			if(c==0)	c++;
			a+=ch[i];
		}
		if(ch[i]=='h')
		{
			if(c>=1)		a+=ch[i];
			if(c==1)	c++;
		}
		if(ch[i]=='e')
		{
			if(c>=2)		a+=ch[i];
			if(c==2)	c++;
		}
		if(ch[i]=='f')
		{
			if(c>=3)		a+=ch[i];
			if(c==3)	c++;
		}
	}
	string b;
	c=0;
	ch=a;
	for(i=a.size()-1;i>=0;i--)
	{
		if(ch[i]=='f')
		{
			if(c==0)	c++;
			b=ch[i]+b;
		}
		if(ch[i]=='e')
		{
			if(c>=1)		b=ch[i]+b;
			if(c==1)	c++;
		}
		if(ch[i]=='h')
		{
			if(c>=2)		b=ch[i]+b;
			if(c==2)	c++;
		}
		if(ch[i]=='c')
		{
			if(c>=3)		b=ch[i]+b;
			if(c==3)	c++;
		}	
	}
	return b;
}
int recur(string a,int p,int c,int n,int k)
{
	//cout<<a<<" "<<p<<" "<<endl;
	if(p==n)
	{
		int co=count(a,chef);
		if(co==k)
			return c;
		else
			return 1000;	
	}
	else
	{
		string b;
		for(int i=0;i<n;i++)
		{
			if(i!=p)
				b+=a[i];
		}
		int a1=recur(a,p+1,c,n,k);
		int b1=recur(b,p,c+1,n-1,k);
		return min(a1,b1);
	}
}
main()
{
	int T,i;	cin>>T;
	string b="chef";
	while(T--)
	{
		int n,k,ans=0;	cin>>n>>k;
		string a;	cin>>a;
		a=reduce(a);
		int c=count(a,b);
		if(c<k)		cout<<"-1"<<endl;
		else if(c==k)	cout<<"0"<<endl;
		else
		{
			int ans=recur(a,0,0,a.size(),k);
			cout<<ans<<endl;
		}
	}
}
