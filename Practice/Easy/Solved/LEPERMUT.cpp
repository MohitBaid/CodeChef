#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i,j;	scanf("%d",&n);
				int A[n];
				for(i=0;i<n;i++)	scanf("%d",&A[i]);
				int inv=0;
				for(i=0;i<n-1;i++)
					if(A[i]>A[i+1])	
						inv++;
				for(i=0;i<n-1;i++)
					for(j=i+1;j<n;j++)
						if(A[i]>A[j])
							inv--;
				if(inv==0)
					printf("YES\n");
				else
					printf("NO\n");						
		}
}
