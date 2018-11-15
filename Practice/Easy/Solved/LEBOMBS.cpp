#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		string s;	cin>>s;
		int A[1005],ans=0;
		for(i=0;i<n;i++)	A[i]=1;
		for(i=0;s[i]!='\0';i++)
			if(s[i]=='1')
			{
				A[i]=0;
				if(i-1>=0)		A[i-1]=0;
				if(i+1<n)	A[i+1]=0;
			}
		for(i=0;i<n;i++)	ans+=A[i];
		cout<<ans<<endl;		
	}
}
