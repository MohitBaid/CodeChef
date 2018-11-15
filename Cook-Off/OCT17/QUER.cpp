#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int y,i,ans=0,lim;	cin>>y;
		if(y>700)	lim=700;
		else		lim=y;
		for(i=1;i<=lim;i++)
		{
			y-=i;
			if(y)
			{
				long long int temp=sqrt(y);
				ans+=temp;
			}
			y+=i;
			//cout<<ans<<endl;	
		}
		cout<<ans<<endl;
	}
}
