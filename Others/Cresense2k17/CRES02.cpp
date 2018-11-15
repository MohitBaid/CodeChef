#include<stdio.h>
int main()
{
		int n,i;	scanf("%d",&n);
		int A[n];
		for(i=0;i<n;i++)	
					scanf("%d",&A[i]);
		int Q;	scanf("%d",&Q);
		while(Q--)
		{
			char c;	scanf("%c",&c);
			if(c=='U')
			{
					int l,v;	scanf("%d %d",&l,&v);
					A[l-1]=v;		
			}
			else if(c=='A')
			{
					int l,r,sum=0;	scanf("%d %d",&l,&r);
					for(i=l-1;i<r;i++)
						sum+=A[i];
					printf("%d\n",sum);	
			}
			else if(c=='M')
			{
					int l,r,max=-1;	scanf("%d %d",&l,&r);
					for(i=l-1;i<r;i++)
							if(A[i]>max)
								max=A[i];
					printf("%d\n",max);			
			}
			else if(c=='m')
			{
					int l,r,min=A[l-1];	scanf("%d %d",&l,&r);
					for(i=l-1;i<r;i++)
							if(A[i]<min)
								min=A[i];
					printf("%d\n",min);			
			}
			else if(c=='S')
			{
					int l,r,max=-1;	scanf("%d %d",&l,&r);
					if(r-l)
					for(i=l-1;i<r;i++)
							if(A[i]>max)
								max=A[i];
					printf("%d\n",max);			
			}
			
				
		}			
}
