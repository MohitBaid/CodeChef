//https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/
#include<bits/stdc++.h>
using namespace std;
set < string > g;
set < string > :: iterator it;
int count(string a, string b)
{
    int m = a.length();
    int n = b.length();
    int lookup[m + 1][n + 1];
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
int cal(string g)
{
	int n=g.size();
	int ans=0,i;
	string c="10";
	while(c.size()<=g.size())
	{
		i=count(g,c);	
		ans+=i;
		if(i<=1)
			break;
		c=c+"10";	
	}			
	return ans;
}
void gen(int n,string ge)
{
	if(ge.size()==n-1)
	{
		string f=ge+'0';
		g.insert(f);
	}
	else
	{
		gen(n,ge+'0');
		gen(n,ge+'1');
	}
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		string s;	cin>>s;
		int x,i;		cin>>x;
		set < int > se;
		set < int > ::iterator jt;
		string ge="1";
		gen(s.size(),ge);
		for(it=g.begin();it!=g.end();it++)
		{
			ge=*it;
			int a=cal(ge);
			if(a==x)
			{
				int f=0;
				for(i=0;i<s.size();i++)
				{
					if(s[i]!=ge[i])
						f++;
				}
				se.insert(f);
			}
		}
		g.clear();
		if(se.size())
		{
			jt=se.begin();
			cout<<"YES"<<endl;
			cout<<*jt<<endl;
			se.clear();
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
