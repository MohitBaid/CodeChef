#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int A[26],i,ans=0,F[26]={0};	
		char ch[1000000];
		for(i=0;i<26;i++)	
		{
			cin>>A[i];
			ans+=A[i];
		}
		cin>>ch;
		for(i=0;ch[i]!='\0';i++)
		{
			if(F[ch[i]-'a']==0)
			{
				ans-=A[ch[i]-'a'];
				F[ch[i]-'a']=1;
			}
		}
		cout<<ans<<endl;
	}
}
