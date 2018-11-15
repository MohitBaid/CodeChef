#include<bits/stdc++.h>
using namespace std;
//modular inverse and extended euclid from geeksforgeeks
// C function for extended Euclidean Algorithm
long long int gcdExtended(long long int a, long long int b,long long int *x,long long int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    long long int x1, y1; // To store results of recursive call
    long long int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
// Function to find modulo inverse of a
long long int modInverse(long long int a,long long int m)
{
    long long int x, y;
    long long int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        long long int res = (x%m + m) % m;
        return res;
    }
} 
long long int nCr(long long int n,long long int r,long long int M)
{
		if(r>n)				return 0;
		if(r==0)			return 1;
		if(r>n/2)			r=n-r;
		long long int ans=1;
		for(int i=1;i<=r;i++)
		{
			ans=ans*(n-i+1);
			ans=ans/i;
			ans=ans%M;
		}
		return ans;
}
/*int power(int x, int y,long long int M)
{
    if (y == 0)
        return 1;
    int temp=power(x, y/2,M);
	if (y%2 == 0)
	    return   temp*(temp%M)%M;
    else
        return x*(temp*(temp%M)%M)%M;
}*/
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		long long int num=1LL*nCr(2*(n-1),n-1,1000000007)/n;
		long long int deno=0,a=0,b=1;
		if(n==1)	deno=0;
		else if(n==2)	deno=1;
		else	for(i=3;i<=n;i++)	deno=2*(a+b),a=b,b=deno;
		long long int g=__gcd(num,deno);
		num=num/g;
		deno=deno/g;
		num=modInverse(num,1000000007);
		long long int ans1=(1LL*num*deno)%1000000007;
		
		
		num=1LL*nCr(2*(n-1),n-1,1000000009)/n;
		deno=0,a=0,b=1;
		if(n==1)	deno=0;
		else if(n==2)	deno=1;
		else	for(i=3;i<=n;i++)	deno=2*(a+b),a=b,b=deno;
		g=__gcd(num,deno);
		num=num/g;
		deno=deno/g;
		num=modInverse(num,1000000009);
		long long int ans2=(1LL*num*deno)%1000000009;	
		printf("%lld %lld\n",ans1,ans2);
	}
}
