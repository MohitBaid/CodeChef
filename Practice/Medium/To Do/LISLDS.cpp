#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,a,b,i,j;
		cin>>n>>a>>b;
		if(n>=a+b-1 && n <=a*b)
		{
			for(i=0;i<=a;i++)
			{
				for(j=min(n,(i+1)*b);j>(i*b);j--)
					cout<<j<<" ";
			}
			cout<<endl;
		}
		else	cout<<"-1\n";
	}
}
