#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		set < vector <int> > s,ans;
		vector < int > v;
		set < vector <int > > :: iterator it,it2;
		vector <int> :: iterator jt;
		int n,i,j;	cin>>n;
		if(n==1)	
		{
			cout<<"1\n";
			continue;
		}
		for(i=0;i<n;i++)	
		{
			int temp;
			cin>>temp;
			v.push_back(temp);
		}
		s.insert(v);
		ans.insert(v);
		int A[1000]={0};
		int m=0,pi=5;
		while(s.size()>0)
		{
			it=s.begin();
			v=*it,m=0;
			s.erase(*it);
			for(jt=v.begin();jt!=v.end();jt++)	
			{
					A[m++]=*jt;
			}
			for(i=m-1;i>0;i--)
			{
				vector <int > v2;
				if(A[i]>0 && A[i-1]>0)
				{
					A[i]--;
					A[i-1]--;
					if(i==m-1)	
					{
						int temp=A[i+1];
						A[i+1]=1;
						for(j=0;j<=m;j++)
							v2.push_back(A[j]);
						A[i+1]=temp;	
					}
					else
					{
						A[i+1]++;
						for(j=0;j<m;j++)
							v2.push_back(A[j]);
						A[i+1]--;
					}
					A[i]++;
					A[i-1]++;
				}
				if(ans.find(v2)==ans.end())
				{
					s.insert(v2);
					ans.insert(v2);
				}
			}
		}
		cout<<ans.size()-1<<endl;
	}
}
