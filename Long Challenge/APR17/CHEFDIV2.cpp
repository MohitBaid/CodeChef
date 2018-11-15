#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
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
	long long int a,b,i,k,j;	scanf("%lld %lld",&a,&b);
	long long int A[b-a+1];
	long long int P[b-a+1][100];
	int pi[b-a+1];
	int d=0;
	for(i=0;i<=b-a;i++)	
	{
		pi[i]=0;
		A[i]=a+i;
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
					P[k-a][pi[k-a]++]=d;
					d=0;
				}
			}	
	}
	long long ans=0;
	for(i=0;i<=b-a;i++)
	{
			priority_queue<int> pq;
			int temp=1;
			if(A[i]!=1)
				P[i][pi[i]++]=1;
			for(int j=0;j<pi[i] && P[i][j]>0;j++)
			{
    			temp=temp*(P[i][j]+1);
    			pq.push(P[i][j]);
    		}
    		ans+=temp-1;
			while(pq.size()!=0)
    		{	
    			int d=pq.top();
    			pq.pop();
    			temp=temp/(d+1);
    			temp=temp*(d);
    			ans+=temp;
    			if(d>1)
				pq.push(d-1);
    		}	
	}
	printf("%lld\n",ans);
	return 0;
}
