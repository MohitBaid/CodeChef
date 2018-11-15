#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,j,res=0,m,ctr=0;	scanf("%d",&n);
		long long int A[n],M[n];
		int C[n]; 
		long long int s=0;
		int flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
			M[i]=i;
			C[i]=1;
			s+=A[i]%n;
			if(A[i]!=A[i-1]&&i!=0)
				flag=1;
		}	
		if(flag==0)
			printf("%d\n",n);
		else	if(s>n)
			printf("%d\n",s/n+s%n);	
		/*else{
		m=n;	
			if(n>=10000)
			m=m/100+n%100;			
		for(j=0;j<=m;j++)
		{
			for(i=0;i<n;i++)
			{
				M[i]=M[i]+(A[M[i]]+1);
				if(M[i]>=n)
					M[i]=M[i]%n;
				if(M[i]==i&&C[i]==1)
				{
					res++;
					C[i]=0;
				}				
			}
		}
		printf("%d\n",res);	
		}*/	
	}
	return 0;
}
