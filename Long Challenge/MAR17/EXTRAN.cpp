#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i;	scanf("%d",&n);
				int A[n];
				for(i=0;i<n;i++)	scanf("%d",&A[i]);
				std::sort(A,A+n);
				for(i=1;i<n;i++)
					if(A[i]-A[i-1]!=1)	
						break;
				if(i==n-1)
					printf("%d\n",A[i]);
				else		
					printf("%d\n",A[i-1]);	
							
		}	
}
