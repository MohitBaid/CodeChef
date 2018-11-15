#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,t,i;	scanf("%d",&n);
		int flag1=0,flag2=0;
		float avg=0.0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			avg+=t;
			if(t==5)		flag1=1;
			if(t==2)		flag2=1;		
		}
		avg=(avg*1.0)/n;
		if(!flag2 && flag1 && avg >= 4.0)
				printf("Yes\n");
		else	printf("No\n");		
	}	
}
