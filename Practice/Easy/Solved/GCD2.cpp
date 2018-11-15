#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int a,x=0,i;char b[255];
				cin>>a>>b;
				if(a==0)
					printf("%s\n",b);
				else
				{	
					for(i=0;b[i]!='\0';i++)
							x=(x*10+((int)b[i] -48))%a;
					printf("%d\n",__gcd(x,a));
				}
		}
}
