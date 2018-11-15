#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,j;	scanf("%d",&n);
		int A[n];
		for(i=0;i<n;i++)	A[i]=i+1;
		printf("%d\n",n);
		int p=0;
		for(i=0;i<n;i++)
		{
			printf("%d\n",n);
			for(j=0;j<n;j++,p=(p+1)%n)
				printf("%d %d %d\n",j+1,A[p],A[(p+1)%n]);
			p=(p+1)%n;	
		}
	}
}
