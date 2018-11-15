#include<bits/stdc++.h>
using namespace std;
int  main()
{
	int m;	scanf("%d",&m);
	int A[m];
	int C[10001]={0};
	for(int i=0;i<m;i++)
	{
		cin>>A[i];
		C[A[i]]++;
	}
	int max=-1;
	int ans=-1;
	for(int i=0;i<=1000;i++)
	{
		if(C[i]>max)
		{
			max=C[i];
			ans=i;
		}
	}
	printf("%d",ans);
}
