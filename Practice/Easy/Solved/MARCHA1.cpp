#include<stdio.h>
int check(int A[],int i,int n,int s,int m)
{
		if(s==m)		return 1;
		if(s>m)			return 0;	
		if(i==n)		return 0;	
		return check(A,i+1,n,s+A[i],m) + check(A,i+1,n,s,m);	
}
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,m,i;	scanf("%d %d",&n,&m);
				int A[n];
				for(i=0;i<n;i++)
					scanf("%d",&A[i]);
				if(check(A,0,n,0,m)!=0)
					printf("Yes\n");
				else
					printf("No\n");	
		}
}
