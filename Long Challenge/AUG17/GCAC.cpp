#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,m,i,ans=0,j;	cin>>n>>m;
		long long int sal=0;
		int A[n],B[m],C[m],D[m];
		for(i=0;i<n;i++)	cin>>A[i];
		for(i=0;i<m;i++)	cin>>B[i]>>C[i],D[i]=0;
		char ch[n][m+2];
		for(i=0;i<n;i++)	cin>>ch[i]; 
		for(i=0;i<n;i++)
		{
			priority_queue <int > pq;
			for(j=0;j<m;j++)
			{
				if(ch[i][j]=='1')
				{
					if(C[j] && B[j]>A[i])	pq.push(B[j]);
				}
			}
			if(pq.size())
			{
				int temp=pq.top();
				for(j=0;j<m;j++)
					if(B[j]==temp)
					{
						C[j]--;
						D[j]++;
						ans++;
						sal+=B[j];
						//cout<<"stu "<<i+1<<":"<<B[j]<<endl;
					}
			}
		}
		cout<<ans<<" "<<sal<<" ";
		ans=m;
		for(i=0;i<m;i++)
			if(D[i])
				ans--;
		cout<<ans<<endl;		
	}
}
