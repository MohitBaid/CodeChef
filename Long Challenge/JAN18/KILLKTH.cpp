#include<bits/stdc++.h>
using namespace std;
long long int A[2001000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char s[20000];	cin>>s;
	vector < char > t;
	multiset < vector < char > > se;
	multiset < vector < char > > :: iterator it;
	int i,j,m;
	for(i=0;i<strlen(s);i++)
	{
		t.clear();
		for(j=i;j<strlen(s);j++)
		{
			t.push_back(s[j]);
			se.insert(t);
		}
	}
	for(it=se.begin();it!=se.end();it++)
	{
		t=*it;
		for(i=0;i<t.size();i++)
		{
			cout<<t[i];
		}
		cout<<endl;
	}
	//cout<<str<<endl;*/
	/*int q;	cin>>q;
	int g=0;
	while(q--)
	{
		int p,m;	cin>>p>>m;
		//long long int k=(p*g)%m;
		cout<<'a'<<"\n";
		//g+=(1LL*str[k]);
	}
}
