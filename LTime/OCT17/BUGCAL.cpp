#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int a,b,i;	cin>>a>>b;
		int A[10]={0},B[10]={0};
		int m=9;
		if(a<10 && b<10)
		{
			int s=a+b;
			if(s>=10)	s=s-10;
			cout<<s<<endl;
			continue;
		}
		while(a)
		{
			A[m--]=a%10;
			a=a/10;
		}
		m=9;
		while(b)
		{
			B[m--]=b%10;
			b=b/10;
		}
		int S[10]={0};
		for(i=0;i<10;i++)
		{
			S[i]=(A[i]+B[i])%10;
		}
		for(i=0;i<10;i++)	if(S[i]!=0)	break;
		for(;i<10;i++)		cout<<S[i];
		cout<<endl;
	}
}
