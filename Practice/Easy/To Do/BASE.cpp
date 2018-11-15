#include<stdio.h>
long long int pow(int n)
{
	if(n==0)
		return 1;
	else if(n==1)
		return 2;
	else if(n==2)
		return 4; 					
	long long int m=pow(n/2);
	//printf("%d------> %d\n",n/2,m);
	 m=(m*m);
	 if(n%2!=0)
			m=(m*2);
	return m;		
}
int main()
{
	long long int n=1000000000000,m=0,A[42],ans;
	int c=0,i;
	for(i=1;i<=43;i++)
	{
		 m=pow(i);
		 A[i-1]=m;
	}
	int t;	scanf("%d",&t);
	while(t--)
	{
			scanf("%lld",&n);
			ans=n/2;
			if(n%2)		ans++;
			for(i=0;;i++)
				if((A[i]<n/2)||(A[i]==n/2&&n%2))
					ans++;	
				else
					break;	
			printf("%lld\n",ans);			
	}	
	
}
