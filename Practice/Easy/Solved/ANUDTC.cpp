#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		if(360%n==0)		printf("y ");
		else 				printf("n ");		
		if(n<=360)			printf("y ");
		else 				printf("n ");		
		if(n<=26)		printf("y ");
		else 				printf("n ");		
	}
}
