#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;	scanf("%d",&n);
	if(n<=0)
	{
		printf("0\n");
		return 0;
	}
	int A[n],W[n],C[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		W[i]=0;
		C[i]=0;
	}
	i=0;
	int flag=0;
	int c=1;
	while(1)
	{
		if(flag==1)
			break;
		if(W[i]==1)
		{
			for(j=0;j<n;j++)
				if(W[j]==0)
					break;
			i=j;
			c++;		
		}
		W[i]=1;
		C[i]=c;
		i=A[i];	
		flag=1;
		for(j=0;j<n;j++)
			if(W[j]==0)
			{
				flag=0;
				break;
			}	
	}	
	printf("%d\n",c);
	for(i=1;i<=c;i++)
	{
		//cout<<"CCCCCC\n";
		int l=0,flag=0;
		for(j=0;j<n;j++)
			if(C[j]==i)
				break;
		while(1)
		{
			if(C[j]==i && W[j]==1)
			{
				printf("%d ",j+1);
				if(!flag)
				{
					l=j;
					flag=1;
				}
				W[j]=0;
				j=A[j];
			}
			else break;
		}
		printf("%d\n",l+1);	
	}
}
