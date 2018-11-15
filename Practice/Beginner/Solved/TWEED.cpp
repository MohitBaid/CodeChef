#include<stdio.h>
#include<string.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i;
				char p[5];	scanf("%d %s",&n,p);
				int A[n];
				for(i=0;i<n;i++)
					scanf("%d",&A[i]);
				if(n==1)
				{
						if(A[0]%2==0 && strcmp("Dee",p)==0)
							printf("Dee\n");
						else
							printf("Dum\n");	
				}
				else
					printf("Dum\n");			
		}
}
