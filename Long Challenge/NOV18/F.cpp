#include<bits/stdc++.h>
#define set unordered_set
#define map unordered_map
using namespace std;
set < string > st[10];
int v[1001][1001];
int C[1001]={0};
	
void gen(string a, int n)
{
	if(a.size()==n)
		st[n].insert(a);
	else
	{
		if(a.size()>0)
			st[a.size()].insert(a);
		gen(a+'0',n);
		gen(a+'1',n);
		gen(a+'2',n);
	}	
}
int main()
{
	int n,i,j;	cin>>n;

	for(i=1;i<=n;i++)
	{
		int p;	cin>>p;
		map < int , int > mp;
		
		for(j=0;j<p;j++)
		{
			int t;	cin>>t;
			if(C[t]>0)
			{
				for(int j1=0;j1<C[t];j1++)
				{
					mp[v[t][j1]]++;
				}
			}
			else	mp[t]++;	
		}
		
		for(map < int,int > :: iterator mt = mp.begin();mt!=mp.end();mt++)
		{
			if( (mt->second%2) != 0)
			{
				v[i][C[i]++]=mt->first;	
			}
		}
	}
	
	int q;	cin>>q;
	int A[10];
	gen("",6);
	set < int > fr1,fr2;
	while(q--)
	{
		int k;	cin>>k;
	
		int ans = 0,f1=0,f2=0;
		
		for(i=0;i<k;i++)	cin>>A[i];
		for(set < string > :: iterator it = st[k].begin();it!=st[k].end();it++)
		{
			string s = (*it);
			
			for(i=0;i<s.size();i++)
			{
				if(s[i]=='1')
				{
					f1=1;
					if(C[A[i]]>0)
						for(j=0;j<C[A[i]];j++)
						{
							if(fr1.find(v[A[i]][j])==fr1.end())
								fr1.insert(v[A[i]][j]);
							else
								fr1.erase(v[A[i]][j]);			
						}
					else	
					{
						if(fr1.find(A[i])==fr1.end())
							fr1.insert(A[i]);
						else
							fr1.erase(A[i]);			
					}
				}
			}
			
			for(i=0;i<s.size();i++)
			{
				if(s[i]=='0')
				{
					f2=1;
					if(C[A[i]]>0)
						for(j=0;j<C[A[i]];j++)
						{
							if(fr2.find(v[A[i]][j])==fr2.end())
								fr2.insert(v[A[i]][j]);
							else
								fr2.erase(v[A[i]][j]);			
						}
					else	
					{
						if(fr2.find(A[i])==fr2.end())
							fr2.insert(A[i]);
						else
							fr2.erase(A[i]);			
					}	
				}
			}
			
			int fr=1;
			for(set < int > :: iterator it = fr1.begin();it!=fr1.end();it++)
			{
				if(fr2.find(*it)==fr2.end())
				{
					fr = 0;
					break;
				}
				else	fr2.erase(*it);
			}
			if(fr2.size()>0)	fr=0;
			
			fr1.clear();
			fr2.clear();
			
			if(f1 && f2 && fr)
			{
				//cout<<s<<endl;
				
				ans = 1;
				break;
			}
		}
		cout<<ans ;
	}
	cout<<endl;
}
