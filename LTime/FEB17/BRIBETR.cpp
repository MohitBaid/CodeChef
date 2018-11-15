#include<stdio.h>
#include<math.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int h,k,i;	scanf("%d %d",&h,&k);
				int n=pow(2,h);
				int A[n];
				int B[n];
				int C[n];
				int m=1;
				int ans=0,flag=1;
				for(i=0;i<n;i++)
					scanf("%d",&A[i]);
				while(1)
				{
					m=0;
					if(A[0]>A[1])
						B[m++]=A[0];
					else
					{
							if(A[0]+k>A[1])
							{
								ans++;
								B[m++]=A[0];			
							}
							else
							{
								flag=0;
								break;	
							}
					}	
					for(i=2;i<n;i=i+2)
					{
						if(A[i]>A[i+1])	
							B[m++]=A[i];
						else
							B[m++]=A[i+1];
						printf("%d %d\n",A[i],A[i+1]);			
					}
					for(i=0;i<m;i++)
						A[i]=B[i];
					n=m;
					for(i=0;i<m;i++)
						printf("%d ",A[i]);
					printf("\n");	
					if(n==1)
						break;	
				}
				if(flag)
					printf("%d\n",ans);
				else
					printf("-1\n");		
		}

}

