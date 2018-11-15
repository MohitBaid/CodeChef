#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,k,i,j;	cin>>n>>k;
		char ch[n+2],ch1[n+2];
		cin>>ch;
		int A[n];
		int b=0;
		long long int c=0,m=0;
		long long int ans=0;
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]=='a'||ch[i]=='b')
				ch1[m++]=ch[i];
			if(ch[i]=='b')
				b++;	
		}
		ch1[m]='\0';
		for(j=0;j<m;j++)
			if(ch1[j]=='b')
					c++;
		c=c*k;
		for(i=0;i<m;i++)
		{
			if(ch1[i]=='a')
			{
				ans+=(c*k-   b*(k*(k-1)/2) );
				//cout<<ans<<endl;
			}
			else if(ch1[i]=='b')
				c--;		
		}
		cout<<ans<<endl;
	}
}
