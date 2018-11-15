#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;		
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		if(isprime(n))
			printf("yes\n");
		else
			printf("no\n");
	}
}
