#include<stdio.h>
#include<string.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
			int n,m,i,j;	scanf("%d %d",&n,&m);
			char ch [5][5]; 
			int ans[n];
			for(j=0;j<n;j++)
			{
					int flag=0;
					for(i=0;i<4;i++)
					{
							scanf("%s",ch[i]);
							if(strcmp(ch[i],"0000")!=0)
									flag=1;			
					}
					if(flag)			ans[j]=1;
					else				ans[j]=0;	
			}
			while(m--)
			{
				int p,l,r;	scanf("%d %d",&p,&l);
				if(p==1)
				{
					scanf("%d",&r);
					int flag=1;
					for(i=l-1;i<r;i++)
					{
							if(ans[i]==1)
							{
								flag=0;
								break;
							}
					}
						if(flag)
								printf("Lotsy\n");
						else
								printf("Pishty\n");	
				}
				else
				{
					int flag=0;
					for(i=0;i<4;i++)
					{
							scanf("%s",ch[i]);
							if(strcmp(ch[i],"0000")!=0)
									flag=1;			
					}
					if(flag)			ans[l-1]=1;
					else				ans[l-1]=0;
				}	
			}
	}	
}
