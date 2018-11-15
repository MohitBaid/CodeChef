#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char ch1[4][11];
		char ch2[4][11];
		scanf("%s %s %s %s",ch1[0],ch1[1],ch1[2],ch1[3]);
		scanf("%s %s %s %s",ch2[0],ch2[1],ch2[2],ch2[3]);
		//printf("%s %s %s %s",ch2[0],ch2[1],ch2[2],ch2[3]);
		int ans=0,i,j;
		for(i=0;i<4;i++)
		{
			int t=0;
			for(j=0;j<4;j++)
			{
				if(strcmp(ch1[i],ch2[j])==0)
				{
					t++;
					break;
				}
			}
			if(t)
				ans++;
		}
		if(ans>=2)
			printf("similar\n");
		else
			printf("dissimilar\n");	
	}
}
