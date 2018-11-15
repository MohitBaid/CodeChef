#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;	scanf("%d %d %d",&a,&b,&c);
		multiset <int> mp;
		mp.insert(a);
		mp.insert(b);
		mp.insert(c);
		multiset <int> :: iterator it;
		it=mp.begin();
		it++;
		printf("%d\n",*it);
	}
}
