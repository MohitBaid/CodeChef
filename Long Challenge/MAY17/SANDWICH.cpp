#include<bits/stdc++.h>
using namespace std;
long long int inv(long long int a,int m)
{
	a=a%m;
	int i;
	for(i=1;i<m;i++)
		if((a*i)%m == 1)
			return i; 	
	return -1;		
}

//modular inverse and extended euclid from geeksforgeeks
int extended_euclid(int a, int b, int &x, int &y) 
{  
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
	int q = a/b;
	int t = b; b = a%b; a = t;
	t = xx; xx = x-q*xx; x = t;
	t = yy; yy = y-q*yy; y = t;
    }
    return a;
}
int mod_inverse(int a, int n) 
{
    int x, y;
    int d = extended_euclid(a, n, x, y);
    if (d > 1) return -1;
    return x%n;
}
long long int nCrlucasgen(long long int a,long long int b,long long int M)
{
	long long int ans=1;
	long long int temp;
	long long int n[100]={0},r[100]={0},k[100]={0};
	int nc=0,rc=0,kc=0,i;
	for(i=2;i*i<=M;i++)
	{
		if(M%i==0)
			break;
	}
	int p=0;
	while(M>0)
	{
		M=M/i;
		p++;
	}
	M=i;
	temp=a;
	while(temp>0)
	{
		n[nc++]=temp%M;
		temp=temp/M;
	}
	temp=b;
	while(temp>0)
	{
		r[rc++]=temp%M;
		temp=temp/M;
	}
	temp=a-b;
	while(temp>0)
	{
		k[kc++]=temp%M;
		temp=temp/M;
	}
	int d=max(nc,max(rc,kc));
	long long int N=0,K=0,R=0;
	int pow=1;
	for(i=0;i<p;i++)
	{
		N+=n[i]*pow;
		K+=k[i]*pow;
		R+=r[i]*pow;
		pow=pow*p;	
	}
	long long int pow2=1;	
	for(i=0;i<d;i++)
	{
		for(i=1;i<N;i++)
			ans=ans*i%M;
		for(i=1;i<K;i++)
			ans=ans*inv(i,M)%M;
		for(i=1;i<R;i++)
			ans=ans*inv(i,M)%M;		
		N=N-n[i]*pow2+n[p+1]*pow;	
		K=K-k[i]*pow2+k[p+1]*pow;
		R=R-r[i]*pow2+r[p+1]*pow;
		pow=pow*p;
		pow2=pow2*p;
	}
	return ans;
}
int power(int x, int y,long long int M)
{
    if (y == 0)
        return 1;
    long long int temp=power(x, y/2,M);
	if (y%2 == 0)
	    return   temp*(temp%M)%M;
    else
        return x*(temp*(temp%M)%M)%M;
}
long long int nCr(long long int n,long long int r,long long int M)
{
		if(r>n)				return 0;
		if(r==0)			return 1;
		if(r>n/2)			r=n-r;
		map <int,int > mp;
		int i;
		long long int ans=1,mod=M;
		for(i=1;i<=r;i++)
		{
			ans=ans*(n-i+1);
			ans=ans*inv(i,M);
			ans=ans%M;
		}
		return ans;
}
long long int nCrlucas(long long int a,long long int b,long long int M)
{
	long long int ans=1;
	while(a>0 && b>0)
	{	
		ans=(ans*nCr(a%M,b%M,M))%M;
		a=a/M;
		b=b/M;
	}
	return ans;
}
int isprime(int M)
{
	int i;
	for(i=2;i*i<=M;i++)
		if(M%i==0)
			return 0;
	return 1;		
}
long long int getfacfac(long long int n,long long int M,long long int fact[])
{
	int p=1,i;
	for(i=2;i<M;i++)
		if(M%i==0)
			break;
	p=i;			
	if(n==0|n==1)			return 1;
	else if(n<M)			return fact[n] * getfacfac(n/p,M,fact)%M;
	else
	{
		long long int a=fact[M-1];
		long long int b=fact[n%M];
		long long int c=getfacfac(n/p,M,fact);
		return power(a,n/M,M)*b*c%M;
	}	
}
int fact_mod(int n, int p, long long int fact[]) 
{
    if (n == 0) return  0;
    int e= fact_mod(n / p, p, fact);
    e += n / p;
    return e;
}
long long int nCreu(long long int n,long long int r,long long int M)
{
	long long int fact[M+1],i;
	fact[0]=1;
	for(i=1;i<=M;i++)
		if(__gcd(i,M)==0)	
				fact[i]=fact[i-1]*i%M;
		else
				fact[i]=fact[i-1];		
	long long int mod=M;
	int b=0;
	int p=1;
	for(i=2;i<=M;i++)
		if(M%i==0)
			break;
	p=i;		
	while(mod>0)
	{
		b++;
		mod=mod/p;
	}
	b--;
	//cout<<b<<"BB"<<p<<" "<<endl;
	while(b>0)
	{
		//cout<<n1<<" "<<<<p<<" "<<e1<<endl;
		long long int n1=n,e1=0;
		long long int r1=r,e2=0;
		long long int nr1=n-r,e3=0;
		e1=fact_mod(n,p,fact);
		e2=fact_mod(r,p,fact);
		e3=fact_mod(n-r,p,fact);
		if(e1>=e2+e3+p)	return 0;
		if(e1>=e2+e3+b)	break;
		b--;
	}
	cout<<b<<"BBB"<<endl;
	cout<<n<<" "<<r<<" "<<endl;
	long long int N=getfacfac(n,M,fact);	
	long long int R=getfacfac(r,M,fact);
	long long int NR=getfacfac(n-r,M,fact);
	cout<<N<<" "<<R<<" "<<endl;
	long long int ans=(long long int)pow(p,b)%M;
	ans=ans*N%M;
	ans=ans*mod_inverse(R,M)%M;
	ans=ans*mod_inverse(NR,M)%M;	
	return ans;
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
			long long int n,k,M,ans=0;	scanf("%lld %lld %lld",&n,&k,&M);
			long long int min=ceil(n*1.0/k);
			long long int t=min*k;			t=t-n;
			long long int a=t+min-1;
			long long int b=min-1;
			long long int pro=M;
			long long int tem=1;
			int factor[100000]={0};
			int i,flag=0,ptr=0;
			while(M>1)
			{
				flag=0;
				while(M%2==0)
				{
					M=M/2;
					flag=1;
					tem=tem*2;
				}
				if(flag)
				{
					factor[ptr++]=tem;
					flag=0;	
					tem=1;
				}
				int n=M;
				for(i=3;i<=n;i=i+2)
				{
					flag=0;
					while(M%i==0)
					{
						M=M/i;
						flag=1;
						tem=tem*i;
					}
					if(flag)
					{
						factor[ptr++]=tem;
						flag=0;
						tem=1;
					}
				}	
			}
			for(i=0;i<ptr;i++)
			{
					long long int r;
					if(!isprime(factor[i]))
						r=nCreu(a,b,factor[i]);
					else	
						r=nCrlucas(a,b,factor[i]);
					long long int p=pro/factor[i];
					//cout<<factor[i]<<endl;
					cout<<r<<" "<<p<<" "<<inv(p,factor[i])<<" "<<factor[i]<<endl;;
					ans+=r*p*inv(p,factor[i]);
			}
			cout<<min<<" "<<ans%pro<<endl;
	}
}
