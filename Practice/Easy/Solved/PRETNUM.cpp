#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
long long int A[MAX_SIZE];
long long int B[MAX_SIZE];
int m;
void seive()
{
    isprime[0] = isprime[1] = 1 ;
    for (int i=2; i<MAX_SIZE ; i++)
    {
	    if (!isprime[i])
        {
            prime[m++]=i;
            SPF[i] = i;
        }
        for (int j=0;j<m && i*prime[j]<MAX_SIZE && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=1;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}
int iprime(long long int a)
{
	for(int i=2;i*i<=a;i++)
		if(a%i==0)
		{	
			//cout<<" GGGGG  " << a <<" GGGG "<<endl;
			return 0;
		}
	return 1;		
}
int main()
{
	seive();
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,i,k,j;	scanf("%lld %lld",&a,&b);
		if(a==1)	a++;
		int d=0;
		for(i=0;i<=b-a;i++)	
		{
			A[i]=a+i;
			B[i]=1;
		}	
		for(i=0;i<m && prime[i]<=b;i++)
		{
			long long int j=a/prime[i];
			j=j*prime[i];
			while(j<a)
				j=j+prime[i];
			for(k=j;k<=b;k=k+prime[i])
			{
				while(A[k-a]%prime[i]==0 && A[k-a]!=1)
				{
					d++;
					A[k-a]=A[k-a]/prime[i];
				}
				if(d!=0)
				{
					B[k-a]=B[k-a]*(d+1);
					d=0;
				}
			}	
			//printf("FFFFF   %d\n",i);
		}
		for(i=0;i<=b-a;i++)
			if(A[i]!=1)
				B[i]=B[i]*(2);
		long long ans=0;
		for(i=0;i<=b-a;i++)
			if(iprime(B[i]))
			{
				ans++;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
