#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i; double c,d,s,k=-1;	cin>>n;
		double A[n];
		for(i=0;i<n;i++)	cin>>A[i];
		cin>>c>>d>>s;
		for(i=0;i<n;i++)	if(k<A[i])	k=A[i];
		double ans=(c-1.00)*k;
		cout<<setprecision(7)<<fixed<<ans<<endl;
	}
}
