#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,t,a=0,i;	cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>t;
			a = a^t;
		}
		if((a==0)||(a!=0 && n%2==0))	
			cout<<"First"<<endl;
		else
			cout<<"Second"<<endl;	
	}
}
