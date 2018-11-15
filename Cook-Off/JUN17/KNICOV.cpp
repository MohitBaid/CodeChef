#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int T;	scanf("%d",&T);
	int A[151];
	A[1]=3;
	A[2]=4;A[3]=4;A[4]=4;A[5]=5;A[6]=6;
	for(int i=7;i<=150;i++)
		A[i]=A[i-5]+A[5];
	while(T--)
	{
		int n,m;	scanf("%d %d",&n,&m);
		if(n==1)	printf("%d\n",m);
		else if(n==2)
		{
			int q=m/6;
			int r=m%6;
			int ans=4*q;
			if(r==1)			ans+=2;
			else if(r!=0)		ans+=4;
			printf("%d\n",ans);
		}
		else
		{
			int q=m/6;
			int r=m%6;
			int ans=4*q;
			if(q==0)
			{
				if(r==1)			ans+=3;
				else if(r!=0)		ans+=4;
			}
			else
			{
				if(r==1)			ans+=2;
				else if(r!=0)		ans+=4;
			}
			printf("%d\n",ans);
		}

	}	
}
