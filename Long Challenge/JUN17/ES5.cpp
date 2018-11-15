#include<bits/stdc++.h>
using namespace std;
int main()
{
	double i,j,temp;
	int n=10;
	for(i=39,j=0;j<=n;i=i+71,j++)
	{
		temp=floor(exp(1)*i);
		printf("%.0lf %.0lf\n",i,temp);
	}
}
