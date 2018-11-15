#include<stdio.h>
int main()
{
		int n;	scanf("%d",&n);
		while(n--)
		{
			char ch[100000+2];	scanf("%s",ch);
			int i;
			int A[26];
			for(i=0;i<26;i++)
				A[i]=0;
			for(i=0;ch[i]!='\0';i++)
			{
				if(ch[i]<=90)
					A[ch[i]-65]++;
				else
					A[ch[i]-97]++;		
			}
			int p=i;
			int flag=1;
			int c=0;
			//for(i=0;i<26;i++)
			//	printf("%d ",A[i]);
			//printf("\n");	
			for(i=0;i<26;i++)
			{
					if(A[i]%2)
							c++;
					if(!p%2)
					{
						if(c==1)
						{
							flag=0;
							break;
						}
					}
					else
					{
						if(c==2)
						{
							flag=0;
							break;	
						}								
					}
					//printf("%d ",c);			
			}
			if(flag)
				printf("Yes\n");
			else
				printf("No\n");	
				
		}
}
