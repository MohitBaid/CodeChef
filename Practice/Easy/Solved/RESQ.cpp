#include<bits/stdc++.h>
#define MAX 100000000
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		int ans=MAX;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				int l=i;
				int r=n/i;
				int temp=abs(l-r);
				if(temp<ans)
					ans=temp;
			}
		}
		cout<<ans<<endl;
	}
}
