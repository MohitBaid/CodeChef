#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
			int n,i;	scanf("%d",&n);
			int A[n];
			for(i=0;i<n;i++)	scanf("%d",&A[i]);	
			int ans=0,t1,t2;
			for(i=1;i<n;i++)
			{
					t1=A[i]%A[i-1];
					t2=A[i-1]%A[i];
					if(t1<t2)
						ans+=t1;
					else
						ans+=t2;	
			}
			printf("%d\n",ans);
		}
}
