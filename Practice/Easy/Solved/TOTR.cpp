#include<stdio.h>
int main()
{
		int T,i,j;	char M[28];
		scanf("%d %s",&T,M);
		while(T--)
		{
				char ch[120];	scanf("%s",ch);
				for(i=0;ch[i]!='\0';i++)
				{
					if(ch[i]>=97 && ch[i]<=122)
					{
						int d=ch[i]-97;
						printf("%c",M[d]);
					}
					else if(ch[i]>=65 && ch[i]<=90)
					{
						int d=ch[i]-65;
						printf("%c",(int)M[d]-32);	
					}	
					else if(ch[i]=='_')
						printf(" ");
					else
						printf("%c",ch[i]);	
				}
				printf("\n");		
		}
}
