#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i,j,temp,c=0;	scanf("%d",&n);
				for(i=0;i<n;i++)
					for(j=0;j<n;j++)
						{
							scanf("%d",&temp);
							if(!temp)
								c++;
						}
				int m=2,flag=0;		
				for(i=n-1;i>=0;i--)
				{
						c=c-m;
						if(c<0)
						{
							flag=1;	
							break;
						}
						m=m+2;	
				}
				if(flag)
					printf("%d\n",i);
				else
					printf("0\n");			
		}
}
