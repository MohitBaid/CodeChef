#include<bits/stdc++.h>
using namespace std;
int maxi(int n)
{
	int d = 0;
	while(n>0)
	{
		d = max(d,n%10);
		n = n/10;
	}
	return d;
}
int main()
{
	int n = 1;
	while(n<=300000000)
	{
		int n1 = n;
		int d=0,t=0;
		while(n1>0)
		{
			int k = n1%10;
			d++;
			if(k==2)	
				t++;
			n1 = n1/10;	
		}
		if(t==d)
			cout<<n<<" ";
		d = maxi(n);
		n = n+d;
	}
}
