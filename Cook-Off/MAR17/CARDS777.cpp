#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
			int r,b,p;	scanf("%d %d %d",&r,&b,&p);
			float ans=(r*p+b*(r+b-p));
			ans=ans/(r+b);
			printf("%f\n",ans);
		}
}
