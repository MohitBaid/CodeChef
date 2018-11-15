#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char ch[50]; int temp,b,i,m,e,r;
		for(i=0;i<4;i++)
		{
			scanf("%s %d",ch,&temp);
			if(strcmp(ch,"Barcelona")==0)
					b=temp;
			if(strcmp(ch,"Malaga")==0)
					m=temp;
			if(strcmp(ch,"RealMadrid")==0)
					r=temp;
			if(strcmp(ch,"Eibar")==0)
					e=temp;
		}
		if(b>e && r<m)		printf("Barcelona\n");
		else				printf("RealMadrid\n");
	}
}

