#include<bits/stdc++.h>
using namespace std;
set < string > bit;
void generate(string str,int n)
{
	if (str.size()==n)
	{
		bit.insert(str);
	}
	else
	{
		generate(str+'0',n);
		generate(str+'1',n);
	}
}
int main()
{
	int n,i;		cin>>n;
	string str;
	generate(str,n);
	set < string > ::iterator it;
	for(it=bit.begin();it!=bit.end();it++)
	{
		str=*it;
		for(i=0;i<str.size();i++)
			cout<<str[i];
		cout<<endl;	
	}
}
