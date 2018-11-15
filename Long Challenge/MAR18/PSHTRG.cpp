#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int n,q,i;	cin>>n>>q;
	int A[n];
	for(i=0;i<n;i++)	cin>>A[i];
	while(q--)
	{
		int ch;	cin>>ch;
		if(ch==1)
		{
			int x,v;	cin>>x>>v;
			A[x-1]=v;
		}
		else
		{
			multiset < int > s;
			multiset < int > :: iterator it;
			int l,r,B[n],m=0;	cin>>l>>r;
			for(i=l-1;i<r;i++)	s.insert(A[i]);
			while(s.size()>0)
			{
				int val=*(s.begin());
				B[m++]=val;
				s.erase(s.begin());
			}
			//for(i=0;i<m;i++)	cout<<B[i]<<" ";	cout<<endl;
			int k=m-3;
			while(k>=0 && (B[k]+B[k+1])<= B[k+2])	k--;
			if(k>=0)	
			{
				int ans=B[k]+B[k+1]+B[k+2];
				cout<<ans<<endl;
			}
			else		cout<<"0\n";
		}
	}
}
