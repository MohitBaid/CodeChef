#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000005;
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
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,temp,j;		scanf("%d",&n);		
		map <int,int> mp;
		for(i=1;i<=n;i++)
		{	
			scanf("%d",&temp);
			for(j=0;j<m && prime[j]<=temp;j++)
			{
				if(temp%prime[j]==0)
					while(temp%prime[j]==0)
					{
							temp=temp/prime[j];
							mp[prime[j]]++;
					}	
			}
		}
		map <int,int> :: iterator it;
		long long int ans=1;
		for(it=mp.begin();it!=mp.end();it++)
			ans=ans* (it ->second +1);
		printf("%lld\n",ans);	
	}
	return 0;
}
