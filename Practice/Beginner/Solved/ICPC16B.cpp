#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,temp,c0=0,c1=0,c2=0,d=0;	scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&temp);
			if(temp==0)
				c0++;
			else if(temp==1)
				c1++;
			else if(temp==-1)
				c2++;
			else
				d++;			
		}
		if(d>1 || (d && c2) || (c2>1 && c1==0) )
			printf("no\n");
		else
			printf("yes\n");
	}
}
