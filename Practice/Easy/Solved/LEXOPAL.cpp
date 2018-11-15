#include<stdio.h>
#include<string.h>
int main()
{
	int T,i,j;scanf("%d",&T);
	while(T--)
	{
		char str[12345];
		scanf("%s",str);
		int l=strlen(str);
		j=l-1;
		int flag=1;
		for(i=0;i<l/2;i++)
		{
			if(str[i]=='.')
			{
				//printf("UUUUUUUUUUUUUUUUUUU1111\n");
				if(str[j]=='.')
				{
					//printf("UUUUUUUUUUUUUUUUUUU11112222\n");
					str[i]='a';
					str[j]='a';
				}
				else
					str[i]=str[j];	
			}
			else
			{
				//printf("UUUUUUUUUUUUUUUUUUU2222\n");
				if(str[j]=='.')
				{
					//printf("UUUUUUUUUUUUUUUUUUU22221111\n");
					str[j]=str[i];
				}	
				else if(str[i]!=str[j])
					{
						//printf("UUUUUUUUUUUUUUUUUUU22222222\n");
						flag=0;
						break;
					}	
			}
			j--;
		}
		if(str[l/2]=='.')
			str[l/2]='a'; 
		if(flag==1)
		{
			printf("%s",str);
			printf("\n");
		}
		else
			printf("-1\n");	
	}
}
