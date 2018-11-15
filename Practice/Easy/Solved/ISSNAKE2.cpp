#include<bits/stdc++.h>
using namespace std;
int check(char A[],char B[],int n)
{
		int p1,p2,i;
		int m1[n],m2[n];
		for(i=0;i<n;i++)
			m1[i]=m2[i]=1;
		for(i=0;i<n;i++)
		{
			if(A[i]=='#')
			{
				p1=i;
				p2=1;
				m2[p1]=0;
				break;
			}	
		}
		if(i==n)	return 0;
		else
		{	
			int flag=1;
			while(p1<n)
			{
				if(p2==0)
				{
					if(B[p1]=='#' && m2[p1]==1)
					{
						p2=1;
						m2[p1]=0;
					}
					else if(p1+1!=n && A[p1+1]=='#' && m1[p1+1]==1)
					{
						p1=p1+1;
						m1[p1]=0;
					}
					else
						break;					
				}
				if(p2==1)
				{
					if(A[p1]=='#' && m1[p1]==1)
					{
						p2=0;
						m1[p1]=0;
					}
					else if(p1+1!=n&& B[p1+1]=='#' && m2[p1+1]==1)
					{
						p1=p1+1;
						m2[p1]=0;
					}
					else
						break;	
				}
			}
			flag=0;
			for(i=0;i<n;i++)
			{
				if((A[i]=='#' && m1[i]==1) || (B[i]=='#' && m2[i]==1) )
				{
					flag=1;
					break;
				}	
			}
			if(flag==1)			return 0;
			if(flag==0)			return 1;
		}
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		char A[n+1],B[n+1],M[n+1],N[n+1];
		scanf("%s",A);
		scanf("%s",B);
		for(i=0;i<n;i++)
		{
			M[n-i-1]=A[i];
			N[n-i-1]=B[i];
		}
		if(check(A,B,n))
			printf("yes\n");
		else
		{
			if(check(B,A,n))
				printf("yes\n");
			else
			{
				if(check(M,N,n))
					printf("yes\n");
				else
				{
					if(check(N,M,n))
						printf("yes\n");
					else
						printf("no\n");	
				}		
			}	
		}			
	}
}
