#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;	float y;
	scanf("%d %f",&x,&y);
	if(x%5==0)
	{
		if(x+0.5<=y)
			printf("%.2f\n",y-x-0.5);
		else
			printf("%.2f\n",y);		
	}
	else		printf("%.2f\n",y);
}
