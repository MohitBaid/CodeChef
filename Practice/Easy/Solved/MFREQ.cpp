#include<stdio.h>
int main()
{
	int n,m,i;	scanf("%d %d",&n,&m);
	int A[n];
	for(i=0;i<n;i++)		scanf("%d",&A[i]);
	while(m--)
	{
		int l,r,k;		scanf("%d %d %d",&l,&r,&k);
		l--;	r--;
		int c=0,flag=1;
		if(k>=(r-l+1)/2)
		{
			for(i=l;i<=r;i++)
			{
				if(A[i]==A[i+1])
				{
					if(c==0)
						c=2;
					else	
						c++;
				}
				else	c=0;		
				if(c>=k)
				{
					printf("%d\n",A[i]);
					flag=0;	
					break;
				}			
			}		
			if(flag)
				printf("-1\n");
		}
		else
			printf("-1\n");			
	}
}	
