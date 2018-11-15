#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i;	scanf("%d",&n);
				int A[n],B[n];
				for(i=0;i<n;i++)	scanf("%d",&A[i]);
				for(i=0;i<n;i++)	scanf("%d",&B[i]);
				int c1=0,c2=0;
				for(i=0;i<n;i++)
				{
						if(i%2==0)
						{
							c1+=B[i];
							c2+=A[i];
						}
						else
						{
							c1+=A[i];
							c2+=B[i];
						}
				}
				if(c1<c2)
					printf("%d\n",c1);
				else
					printf("%d\n",c2);	
		}
}

