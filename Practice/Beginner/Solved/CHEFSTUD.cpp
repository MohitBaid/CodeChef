#include <stdio.h>
 
int main()
{
    int T;	scanf("%d",&T);
	while(T--)
	{
    	char ch[100005];		scanf("%s",ch);
    	int c=0,i;
        for(i=0;ch[i]!='\0';i++)
            if(ch[i]=='>'&&ch[i+1]=='<'&&ch[i+2]=='>')
           			c++;
        printf("%d\n",c);
    }
    return 0;
}
