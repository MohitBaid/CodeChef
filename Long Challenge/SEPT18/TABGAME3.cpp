#include<bits/stdc++.h>
using namespace std;
vector < string > com;
map < string , int > mp;
map < int , string > pm;
map < string , int > :: iterator mptr;
int mk = 1;
map < int ,int > mp0,mp1;
map < int ,int > :: iterator mptr1;
void nand(string a,int var)
{
	string g="";
	int i;
	if(var == 0)
	{
		for(i=0;i<a.size();i++)
		{
			int m = a[i]-'0';
			int k=!(var & m);
			g = g + (char)(k+'0');
			var = k;
		}
		if(mp[g]==0)
		{
			mp[g]=mk++;
			pm[mk-1]=g;
			mp0[mp[a]]=mp[g];
		}
		else
		{
			mp0[mp[a]]=mp[g];
		}
	}
	else
	{
		for(i=0;i<a.size();i++)
		{
			int m = a[i]-'0';
			int k=!(var & m);
			g = g + (char)(k+'0');
			var = k;
		}
		if(mp[g]==0)
		{
			mp[g]=mk++;
			pm[mk-1]=g;
			mp1[mp[a]]=mp[g];
		}
		else
		{
			mp1[mp[a]]=mp[g];
		}
	}
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		string row,col;	cin>>row>>col;
		int q=0,i ;	//cin>>q;
		mp[row] = mk++;
		pm[mk-1]=row;
		int A[col.size()];
		int r = mp[row];
		
		for(i=0;i<col.size();i++)
		{
			if(col[i]=='0')
			{
				if(mp0[r]==0)
				{
					nand(pm[r],0);
				}
				A[i]=mp0[r];
				r = mp0[r];
			}
			else
			{
				if(mp1[r]==0)
				{
					nand(pm[r],1);
				}
				A[i]=mp1[r];
				r = mp1[r];
			}
		}
		for(i=0;i<mk;i++)
		{
			cout<<pm[i]<<" "<<i<<endl;
		}
		for(i=0;i<col.size();i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
		while(q--)
		{
			int x,y;	cin>>x>>y;
			cout<<pm[A[x-1]][y-1];
		}
		cout<<endl;
		mp.clear();
		pm.clear();
		mp0.clear();
		mp1.clear();
		mk=1;
	}
}
