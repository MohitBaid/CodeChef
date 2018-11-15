#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
		int Q;	scanf("%d",&Q);
		while(Q--)
		{
				int a,b;	scanf("%d %d",&a,&b);
				if(abs(a-b)>=4)
					printf("NO\n");
				else
				{	
					if(a%2==0 && b%2==0)
						printf("YES\n");
					else if(abs(a-b)==2)
						printf("YES\n");
					else if(abs(a-b)==1)
					{
						if(a>b && a%2==0)		
							printf("YES\n");
						else if(b>a && b%2==0)		
							printf("YES\n");
						else
							printf("NO\n");
					}
					else
						printf("NO\n");	
				}
	}
			
}
