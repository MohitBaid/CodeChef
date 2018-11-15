#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,temp;	scanf("%d",&n);
		map <int ,int > mp;
		multiset <int> s;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			mp[temp]++;
			if(mp[temp]==2)
			{
				s.insert(temp);
				mp[temp]=0;
			}
		}
		if(s.size()<2)
			printf("-1\n");
		else
		{
			multiset <int> :: iterator it;
			it=s.end();
			int l=*(--it);
			int b=*(--it);
			printf("%d\n",l*b);
		}	
	}
}
