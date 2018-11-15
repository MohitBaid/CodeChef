#include<bits/stdc++.h>
using namespace std;
set < string > se[12];
void gen(int p,string t)
{
	if(p==t.size())
	{
		se[p].insert(t);
	}
	else
	{
		se[t.size()].insert(t);
		gen(p,t+'0');
		gen(p,t+'1');
	}
}
int main()
{
	gen(11,"");
	for(int i=0;i<=11;i++)
	{
		set < string > s=se[i];
		set < string > ::iterator it;
		for(it=s.begin();it!=s.end();it++)
		{
			cout<<*it<<endl;
		}
		cout<<endl;
	}
}
