#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int x1,y1,x2,y2;		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int dx=x1-x2;
		int dy=y1-y2;
		if(dx!=0&& dy!=0)
				printf("sad\n");
		else
		{
			if(dx>0)		printf("left\n");
			if(dx<0)		printf("right\n");
			if(dy>0)		printf("down\n");
			if(dy<0)		printf("up\n");		
		}		
	}
}

