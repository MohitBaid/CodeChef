#include<bits/stdc++.h>
using namespace std;
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
			long long int n,m,i=1;	cin>>n>>m;
			long long int m1=sqrt(2*m)-2;
			int ans=-1;
			for(i=m1;i<=n;i++)
			{
				long long int temp=1LL*i*(i+1);
				temp=temp/2;
				//cout<<i<<" "<<temp<<endl;
				if(temp>=m)
				{
					ans=i;
					break;
				}
			}
			cout<<ans<<endl;
		}
}
