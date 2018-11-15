#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()

{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i,j,d,ans=0;	scanf("%d",&n);
				int A[n][n];
				for(i=0;i<n;i++)
					for(j=0;j<n;j++)
						scanf("%d",&A[i][j]);
				int t[n];			
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						t[j]=A[i][j];
					}
					sort(t,t+n);
					d=0;
					for(j=1;j<n;j++)
					{
						if(t[j]!=t[j-1])
							d++;
					}
					if(d>=2)
						ans++;
				}	
				if(ans>2)	
				printf("%d\n",ans);
				else printf("0\n");
		}
}
