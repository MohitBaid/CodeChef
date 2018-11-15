#include<stdio.h>
#include<string.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char S[101];int i,flag=1,t=0;int A[26];
		scanf("%s",S);
		if(S[0]==S[1])
			flag=0;					
		for(i=2;i<strlen(S);i++)
		{
			if(S[i]!=S[i-2])
				{
					flag=0;
					break;
				}	
		}	
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");	
	}
		return 0;
}	
