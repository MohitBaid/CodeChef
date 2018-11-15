#include<bits/stdc++.h>
using namespace std;
int fac[100005][200];
int m=168;
int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
int isgood(int A,int f)
{
	int flag=1;
	for(int i=0;i<m;i++)
	{
		int d=0;
		if(A%prime[i]==0)
		{
			while(A%prime[i]==0)
			{
				d++;
				A=A/prime[i];
			}
		}
		if(d>1)			flag=0;
		fac[f][i]=d;
		d=0;	
	}
	return flag;
}
long long int cal(int A[],int n)
{
	long long int ans=n,l,temp;
	int p=0,i,j,last=-1;
	for(i=1;i<n;i++)
	{
		int flag=0;
		for(j=0;j<m;j++)
		{
			if(fac[p][j]==fac[i][j]&&fac[p][j]!=0)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			for(j=0;j<m;j++)
				fac[p][j]+=fac[i][j];	
		}	
		else
		{
			l=i-p;
			if(l>1)		temp=l*(l-1);
			else		temp=0;
			ans=ans+(temp/2);
			if(last>p)
			{
				l=last-p+1;
				if(l>1)		temp=l*(l-1);
				else		temp=0;
				ans=ans-(temp/2);
			}
			last=i-1;
			while(__gcd(A[i],A[p])==1)
				p++;
			p++;
			i=p;	
		}
	}
	l=i-p;
	if(l>1)		temp=l*(l-1);
	else		temp=0;
	ans=ans+(temp/2);
	if(last>p)
	{
		l=last-p+1;
		if(l>1)		temp=l*(l-1);
		else		temp=0;
		ans=ans-(temp/2);
	}
	return ans;
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,j,k,temp;				scanf("%d",&n);
		long long int ans=0;
		int A[n],G[n],B[n],m2=0;
		for(i=0;i<n;i++)		
		{
			scanf("%d",&A[i]);
			G[i]=isgood(A[i],i);
		}
		for(i=0;i<n;i++)
		{
			if(G[i]==0)
			{
				ans+=cal(B,m2);
				m2=0;
			}
			else		B[m2++]=A[i];
		}
		ans+=cal(B,m2);
		printf("%lld\n",ans);
	}
}
