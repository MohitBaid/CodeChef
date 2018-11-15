#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T,i;	cin>>T;
	vector < pair < int,int > > V;
	while(T--)
	{
		int n,k;	cin>>n>>k;
		int p =0;
		while(n%2 == 0)
		{
			p++;
			n = n/2;
		}
		if(p!=0)
		{
			V.push_back(make_pair(2,p));
		}
		for(i=3;i<=ceil(sqrt(n));i++)
		{
			p=0;
			while(n%i==0)
			{
				p++;
				n = n/i;
			}
			if(p!=0)
			{
				V.push_back(make_pair(i,p));
			}
		}
		if(n>2)
		{
				V.push_back(make_pair(n,1));
		}
		cout<<V.size()<<endl;
		for(i=0;i<V.size();i++)
		{
			cout<<V[i].first<<" "<<V[i].second<<endl;
		}
		V.clear();
	}
}
