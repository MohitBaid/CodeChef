#include <bits/stdc++.h>
using namespace std;
long long int prime[100001],cnt=0,pr[100001];
set<long long int> sss;
set<long long int> ::iterator it;
void combinationUtil(long long int arr[],long long int n,long long int r,long long int index,long long int data[],long long int i);
void printCombination(long long int arr[],long long int n,long long int r)
{
    long long int data[r];
    combinationUtil(arr, n, r, 0*1ll, data, 0*1ll);
}
 
/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(long long int arr[], long long int n, long long int r, long long int index, long long int data[], long long int i)
{
    // Current cobination is ready, print it
    if (index == r)
    {
        long long int k=1;
        for (int j=0; j<r; j++)
            k*=data[j];
        sss.insert(k);
        return;
    }
 
    // When no more elements are there to put in data[]
    if (i >= n)
        return;
 
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1);
}
void sieve()
{
    long long int i,j;
    for(i=2;i<100001;i++)
    {
        pr[i]=1;
    }
    for(i=2;i<100001;i++)
    {
        if(pr[i]==1)
        for(j=i;j<100001;j+=i)
        pr[i]=0;
    }
    for(i=2;i<100001;i++)
    {
        if(pr[i])
        prime[cnt++]=i;
    }
}
 
int main() {
    sieve();
	long long int q,l,r,i,j,k,n,g,z;
	cin>>n;
	long long int blocks=ceil((n*1.0)/1000);
	long long int a[n],b[blocks][100001];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<blocks;i++)
	{
	    for(j=0;j<100001;j++)
	    b[i][j]=0;
	}
	for(i=0;i<n;i++)
	{
	    z=a[i];
	    k=0;
	    for(j=2;j*j<=z;j++)
	    {
	        if(z%j==0&&z!=j)
	        {
	            b[i/1000][z/j]++;
	            b[i/1000][j]++;
	        }
	        if(z==j)
	        {
	            b[i/1000][j]++;
	        }
	    }
	}
	cin>>q;
	long long int comb[100000],c=0;
	while(q--)
	{
	    cin>>k;
	    if(k==1)
	    {
	        cin>>l>>r;
	        z=a[l-1];
	        i=l-1;
	        for(j=2;j*j<=z;j++)
    	    {
    	        if(z%j==0&&z!=j)
    	        {
    	            b[i/1000][z/j]--;
    	            b[i/1000][j]--;
    	        }
    	        if(z==j)
    	        {
    	            b[i/1000][j]--;
    	        }
    	    }
	        a[l-1]=r;
	        z=a[l-1];
	        for(j=2;j*j<=z;j++)
    	    {
    	        if(z%j==0&&z!=j)
    	        {
    	            b[i/1000][z/j]++;
    	            b[i/1000][j]++;
    	        }
    	        if(z==j)
    	        {
    	            b[i/1000][j]++;
    	        }
    	    }
	        
	    }
	    else
	    {
	        long long int ans=0;
	        cin>>l>>r>>g;
	        z=g;
	        if(g==1)
	        cout<<r-l+1<<endl;
	        else if(r/1000 - l/1000==0)
	        {
	            for(i=l-1;i<r;i++)
	            {
	                if(__gcd(g,a[i])==1)
	                ans++;
	            }
	            cout<<ans<<endl;
	        }
	        else{
	            l--;
    	        for(i=0;i<cnt;i++)
    	        {
    	            if(z<prime[i])
    	            break;
    	            if(z%prime[i]==0)
    	            {
    	                comb[c++]=(prime[i]);
    	                while(z%prime[i]==0)
    	                z/=prime[i];
    	            }
    	            if(pr[z])
    	            {
    	                comb[c++]=(z);
    	                z=1;
    	            }
    	        }
    	        while(l%1000!=0)
    	        if(__gcd(a[l++],g)==1)
    	        ans++;
    	        while(r%1000!=0)
    	        if(__gcd(a[r--],g)==1)
    	        ans++;
    	        if(r>l)
    	        for(i=1;i<=c;i++)
    	        {
    	            printCombination(comb, n, i);
    	            if(i%2)
    	            {
    	                for(j=l;j<r;j++)
    	                {
    	                    for(it=sss.begin();it!=sss.end();it++)
    	                    if(*it<100001)
    	                    ans+=b[j][*it];
    	                    sss.clear();
    	                }
    	            }
    	            else
    	            {
    	                for(j=l;j<r;j++)
    	                {
    	                    for(it=sss.begin();it!=sss.end();it++)
    	                    if(*it<100001)
    	                    ans-=b[j][*it];
    	                    sss.clear();
    	                }
    	            }
    	            sss.clear();
    	        }
    	        c=0;
    	        cout<<ans<<endl;
	        }
	    }
	}
	return 0;
}
