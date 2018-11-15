#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000005;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
long long int A[MAX_SIZE];
int pi[MAX_SIZE];
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
int main()
{
	seive();
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int b,a,i,j;int flag;		scanf("%lld %lld",&a,&b);
		int d=0,k;
		for(i=0;i<=b-a;i++)	
		{
			pi[i]=0;
			A[i]=a+i;
		}	
		//cout<<b-a<<endl;
		for(i=0;i<m && prime[i]<=b;i++)
		{
			long long int j=a/prime[i];
			j=j*prime[i];
			while(j<a)
				j=j+prime[i];
			for(k=j;k<=b;k=k+prime[i])
				if(A[k-a]==prime[i] && pi[k-a]==0);	
				else	
					while(A[k-a]%prime[i]==0 && A[k-a]!=1)
					{
							A[k-a]=A[k-a]/prime[i];
							pi[k-a]=1;
					}		
		}
		for(i=0;i<=b-a;i++)
			if(A[i]==i+a && A[i]!=1)
				printf("%lld\n",i+a);
	}
	return 0;
}
