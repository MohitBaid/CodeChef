//https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

#include<bits/stdc++.h>
using namespace std;
#define MOD 163577857
#define int long long int  
int A[10050];
int B[10050];
int P[10000];
int power(int x, int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;
}
void Pascal(int n)
{
	int i;
	P[0]=1;
	for(i=1;i<n;i++)
	{
		P[i]=((P[i-1]%MOD*(n-i)%MOD)%MOD*power(i,MOD-2,MOD))%MOD;
		P[i]%=MOD;
	}
}
void compute(int l)
{
	int m,k;
	for(m=1;m<l;m++)
	{
		A[m]=A[m-1];
		for(k=m-1;k>=1;k--)
		{
			A[k]=A[k-1]+A[k]*B[m];
			A[k]%=MOD;
		}
		A[0]=A[0]*B[m];
		A[0]%=MOD;
	}
}
void gene(int n)
{
	for(int i=1;i<=n;i++)
		B[i]=i,A[i]=0;	
}
void reverse(int n)
{
	for(int i=0;i<n/2;i++)
	{
		swap(A[i],A[n-i-1]);
	}
}
void print(int n,int k)
{
	for(int i=0;i<=n;i++)	
		cout<<A[i]<<" ";
	cout<<endl;
	for(int i=0;i<=k;i++)	
		cout<<P[i]<<" ";
	cout<<endl;
}
int compute(int n,int k)
{
	int i,ans=0;
	for(i=0;i<=k;i++)
	{
		ans+=A[i+1]*P[i];
		ans%=MOD;
	}
	return ans%MOD;
}
void reset(int n,int k)
{
	int i;
	for(i=0;i<=n;i++)	A[i]=0;
	for(i=0;i<=k;i++)	P[i]=0;
}
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,k;	cin>>n>>k;
		A[0]=1;
		A[1]=1;
		n++;
		gene(n);	
		compute(n);
		reverse(n);
		Pascal(k);
		cout<<compute(n,k)<<endl;;
		reset(n,k);
	}
}
