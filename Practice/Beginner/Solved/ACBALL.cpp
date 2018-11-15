#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	scanf("%d",&T);
	while(T--)
	{
		char ch1[100005];	scanf("%s",ch1);
		char ch2[100005];	scanf("%s",ch2);
		for(i=0;ch1[i]!='\0';i++)
		{
			if(ch1[i]!=ch2[i])
				printf("B");
			else if(ch1[i]==ch2[i] && ch1[i]=='B')
				printf("W");
			else if(ch1[i]==ch2[i] && ch1[i]=='W')
				printf("B");		
		}
		printf("\n");
	}
}
