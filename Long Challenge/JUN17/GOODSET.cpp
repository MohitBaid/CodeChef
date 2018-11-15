#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,m=1;;	scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("%d ",m);
			m=m+2;
		}
		printf("\n");
	}
}
