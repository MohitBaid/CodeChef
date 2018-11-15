#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T,i,j;	cin>>T;
	while(T--)
	{
		string s;	cin>>s;
		string s2;
		long long int flag=0,c=0;
		long long int A[26]={0};
		long long int C[s.size()];
		long long int temp=0;
		for(i=1;s[i]!='\0';i++)
		{
			if(s[i]!=s[i-1]) 
			{
				s2=s2+s[i-1];
				C[c++]=temp+1;
				temp=0;
			}
			else		temp++;
		}
		s2=s2+s[i-1];
		C[c++]=temp+1;
		long long int ans=0;
		s2=s2+'\0';
		//cout<<s2<<endl;
		//for(i=0;i<c;i++)	cout<<C[i]<<" ";	cout<<endl;
		for(i=0;i<c;i++)
		{
			if(i+2<c && s2[i]==s2[i+2])
				ans++;
			ans+=(C[i]*(C[i]-1))/(1LL*2);
			//cout<<ans<<endl;	
		}
		cout<<ans<<endl;
		
	}
}
