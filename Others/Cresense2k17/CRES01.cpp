#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i;	scanf("%d",&n);
				int A[n];
				for(i=0;i<n;i++)
					scanf("%d",&A[i]);
				int b=A[0],s=0;	
				for(i=0;i<n;i++)
				{
					if(A[i]>=b)
						b=A[i];
					s=s+(b-A[i]);		
				}	
				printf("%d\n",s);
		}
}
