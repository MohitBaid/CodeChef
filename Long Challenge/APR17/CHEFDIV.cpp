#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 10001;
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	seive();
	long long int a,b,i,ans=0;	cin>>a>>b;
    int P[m],j;
	if(a!=b)
	{
		for(i=a;i<=b;i++)
    	{
    		long long int x=i;
    		int d=0;
    		int g=0;
    		int pi=0;
    		while (x != 1&&d<m)
    		{
				while(d<m && x%prime[d]==0)
				{	 
					g++;
					x=x/prime[d];
       			}
       			if(g)
       			{
					P[pi++]=g;
       				g=0;
       			}
       			d++;
    		}
    		if(x!=1)
    			P[pi++]=1;
			priority_queue<int> pq;
			int temp=1;
			for(int j=0;j<pi && P[j]>0;j++)
			{
    			temp=temp*(P[j]+1);
    			pq.push(P[j]);
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
	}
	else
	{
		long long int x=a;
    	int d=0;
    	int g=0;
    	int pi=0;
    	for(i=2;i<=1000002 && x!=1;i++)
    	{
    		if(x%i==0)
    		{
    			while(x%i==0)
    			{	 
					g++;
					x=x/i;
       			}
       			if(g)
       			{
					P[pi++]=g;
       				g=0;
       			}	
    		}	
    	}
    	if(x!=1)
    		P[pi++]=1;
		priority_queue<int> pq;
		int temp=1;
		for(int j=0;j<pi && P[j]>0;j++)
		{
    		temp=temp*(P[j]+1);
    		pq.push(P[j]);
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
		printf("%lld\n",ans);		
	}
	return 0;
}
