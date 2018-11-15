#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		long long int mod=1000000007;
		if(n==1)
		{
			long long int a;
			cin>>a;
			cout<<"2\n";
			printf("%lld 0 1\n",mod-a);
		}
		if(n==2)
		{
			long long int a,b;
			cin>>a>>b;
			cout<<"4\n";
			long long int last=((a-b)*(a-b))%mod;
			long long int mid=(2*(a+b))%mod;
			mid=mid*-1;
			if(mid<0)
			{
				int f=mid/mod;
				mid+=(-1*f+2)*mod;
				mid=mid%mod;
			}
			printf("%lld 0 %lld 0 1\n",last,mid);		
		}
		if(n==3)
		{
			long long int a,b,c;	cin>>a>>b>>c;
			cout<<"8\n";
			double f1=(sqrt(a)+sqrt(b)+sqrt(c))*(sqrt(a)+sqrt(b)+sqrt(c));
			double f2=(sqrt(a)-sqrt(b)+sqrt(c))*(sqrt(a)-sqrt(b)+sqrt(c));
			double f3=(sqrt(a)+sqrt(b)-sqrt(c))*(sqrt(a)+sqrt(b)-sqrt(c));
			double f4=(sqrt(a)-sqrt(b)-sqrt(c))*(sqrt(a)-sqrt(b)-sqrt(c));
			long long int temp=(a*a+b*b+c*c-2*(a*c+b*c+a*b))*(a*a+b*b+c*c-2*(a*c+b*c+b*a));
			printf("%lld 0",temp%mod);
			temp=temp*(1.0/f1+1.0/f2+1.0/f3+1.0/f4);
			temp=temp*-1;
			if(temp<0)
			{
				long long int f=temp/mod;
				temp+=(-1*f+2)*mod;
				temp=temp%mod;
			}
			printf(" %lld 0",temp);
			temp=6*(a*a+b*b+c*c) + 4*(a*b+a*c+b*c);
			temp=temp%mod;
			printf(" %lld 0",temp);
			temp=4*(a+b+c);
			temp=temp*-1;
			if(temp<0)
			{
				long long int f=temp/mod;
				temp+=(-1*f+2)*mod;
				temp=temp%mod;
			}
			printf(" %lld 0 1\n",temp);
		}
	}
}
