#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int l,d,t,y,f,g;	cin>>l>>d>>t;
		double k=acos(d*1.00/l);
		k=k*t;
		double a=cos(k);
		double temp=a;
		int c=0;
		while(temp!=0)
		{
			temp=temp*10;
			c++;
			temp-=(int)temp;
		}
		cout<<a<<" "<<c<<endl;

	}
}
