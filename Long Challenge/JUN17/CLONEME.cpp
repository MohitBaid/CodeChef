#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;		scanf("%d",&T);
	while(T--)
	{
		int n,q,i;	scanf("%d %d",&n,&q);
		int A[n];
		for(i=0;i<n;i++)		scanf("%d",&A[i]);
		while(q--)
		{
			int a,b,c,d;	scanf("%d %d %d %d",&a,&b,&c,&d);
			int B[b-a+1],C[b-a+1];
			a--;	b--;	c--;	d--;
			for(i=a;i<=b;i++)	B[i-a]=A[i];    sort(B,B+b-a+1);
			for(i=c;i<=d;i++)	C[i-c]=A[i];    sort(C,C+b-a+1);
			int flag=1,ctr=0;
			for(i=0;i<=b-a;i++)
			{
				if(B[i]!=C[i])
				{
					ctr++;
					if(ctr==2)
					{
						flag=0;
						break; 
					}
				}		
			}
			if(flag)
				printf("YES\n");
			else
				printf("NO\n");	
		}
	}
}
