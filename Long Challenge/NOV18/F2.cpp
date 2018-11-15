#include<bits/stdc++.h>
using namespace std;
set < string > st;
int v[1001][1001];
void gen(string a, int n)
{
	if(a.size()==n)
		st.insert(a);
	else
	{
		gen(a+'0',n);
		gen(a+'1',n);
	}	
}
int main()
{
	int n,i,j;	cin>>n;
	int A[n+1][101];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=100;j++)			A[i][j]=0;
		
		int p;	cin>>p;
		
		if(p==0)	A[i][i]=(A[i][i]+1)%2;
		else
		{
			for(j=0;j<p;j++)
			{
				int k; cin>>k;
				for(int j1=1;j1<=100;j1++)
				{
					A[i][j1] = (A[i][j1]+A[k][j1])%2;
				}
			}
		}
	}
	int q;	cin>>q;
	while(q--)
	{
		int k; 	cin>>k;
		gen("",k);
		int ans = 0;
		int A1[k];
		for(i=0;i<k;i++)	cin>>A1[i];
		for(set < string > :: iterator it = st.begin();it!=st.end();it++)
		{
			int B[101]={0};
			string s = (*it);
			int f1=0,f2=1;
			for(i=0;i<s.size();i++)
			{
				if(s[i]=='0')
				{
					f1=1;
					for(j=1;j<=100;j++)
					{
						B[j]=(B[j]+A[A1[i]][j])%2;
					}
				}
			}
			for(i=1;i<=100;i++)
			{
				if(B[i]!=0)
				{
					f2=0;
					break;
				}
			}
			if(f1==1 && f2==1)
			{
				//cout<<s<<endl;
				ans = 1;
				break;
			}
		}
		st.clear();
		cout<<ans;
	}
	cout<<endl;
}
