#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int a,b;	cin>>a>>b;
		int i=1;
		while(1)
		{
			if(i%2)
				a-=i;
			else
				b-=i;
			if(a<0)
			{			
				printf("Bob\n");
				break;
			}
			if(b<0)
			{
				printf("Limak\n");
				break;
			}
			i++;
		}
	}
}
