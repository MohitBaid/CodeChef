#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,i,j;	cin>>a>>b;
	int ans=0;
	for(i=1;i<=a;i++)
	{
		int temp=2*i;
		for(j=1;j*j<=b+1;j++)
		{
			if(j*(j+temp)>b)
				break;
		}
		//cout<<j-1<<endl;
		ans+=(j-1);
	}
	cout<<ans<<endl;
}
