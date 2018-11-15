//https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
#include<bits/stdc++.h>
#define PI 3.142
using namespace std;
const long long int MAX_SIZE = 20000001;
vector<long long int>isprime(MAX_SIZE , true);
vector<long long int>prime;
vector<long long int>SPF(MAX_SIZE);
void manipulated_seive(long long int N)
{
    isprime[0] = isprime[1] = false ;
    for (long long int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (long long int j=0;j < prime.size() && i*prime[j] < N && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}
long long int cal(long long int n)
{
	stack < long long int > q; 
	int p=0;
	int si=-1;
	long long int k=1,ans=0; 
	while(1)
	{
		if((n/k)>=prime[p]*prime[p])
		{
			k=k*prime[p]*prime[p];
			q.push(p);
			p++;
			si=si*-1;
			ans+=(si*((n-1)/k));
		}
		else
		{
			if(k==1)	break;
			k=k/((prime[q.top()])*prime[q.top()]);
			si=si*-1;
			p=q.top()+1;
			q.pop();
		}
	}
	return ans;
}
int sqfree(long long int n)
{
	int i;
	for(i=0;i<prime.size();i++)
		if(n%prime[i]==0)
			if((n/prime[i])%prime[i]==0)
				return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	manipulated_seive(20000000);
	int T;		T=1;
	while(T--)
	{
		long long int n,m,i;	cin>>n;
		double k=PI*PI/(PI*PI-6);
		m=n*k;
		long long int k1=cal(m);
		long long int diff=n-k1;
		if(abs(diff)>7)
		{
			while(abs(diff)>7)
			{
				m=m+(long long int )((diff-7)*(2.55));
				k1=cal(m);
				diff=n-k1;
                //cout<<k1<<" "<<m<<endl;			
			}
		}
		if(k1<n)
		{
    		for(i=m;;i++)
    		{
	    		if(sqfree(i))
	    			k1++;
		    	if(k1==n)
			    {
				    break;
			    }	
	    	}
		}
		else if(k1>n)
		{
		    for(i=m;;i++)
    		{
	    		if(sqfree(i))
	    			k1--;
		    	if(k1==n)
			    {
				    break;
			    }	
	    	}
		}
		else i=m;
		cout<<i<<endl;
	}
}
