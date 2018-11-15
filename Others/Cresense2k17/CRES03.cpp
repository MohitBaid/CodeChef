#include<stdio.h>
int main()
{
		int n;	scanf("%d",&n);
		char ch[n+2];
		scanf("%s",ch);
		int k,i;	scanf("%d",&k);
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]>=97 && ch[i]<=122)
			{
				int d=(int)ch[i];
				d=d+(k%26);
				if(d>122)
					d=(d%123+97)%123;
				printf("%c",(char)d);
			}	
			else if(ch[i]>=65 && ch[i]<=90)
			{
				int d=(int)ch[i];
				d=d+(k%26);
				if(d>90)
					d=(d%91+65)%91;
				printf("%c",(char)d);
			}	
			/*else if(ch[i]>=48 && ch[i]<=57)
			{
				int d=(int)ch[i];
				d=d+k;
				if(d>57)
					d=(d%58+48)%58;
				printf("%c",(char)d);
			}*/
			
			
			else
				printf("%c",ch[i]);	
		}	
		return 0;
}
