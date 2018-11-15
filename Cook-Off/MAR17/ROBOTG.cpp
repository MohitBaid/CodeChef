#include<stdio.h>
int main()
{
		int T,i,j,k;	scanf("%d",&T);
		while(T--)
		{
				int n,m,l;	scanf("%d %d",&n,&m);
				char ch[12];	scanf("%s",ch);
				for(l=0;ch[l]!='\0';l++);
				int flag=0;
				for(i=0;i<m;i++)
				{
						for(j=0;j<n;j++)
						{
								int xi=i;
								int yi=j;
								flag=1;
								for(k=l;k>=0;k--)				
								{
										if(ch[k]=='D')
												yi++;
										if(ch[k]=='U')
												yi--;
										if(ch[k]=='L')
												xi--;
										if(ch[k]=='R')
												xi++;					
										if(yi<0 || yi >=n)
										{
												flag=0;
												break;
										}
										if(xi<0 || xi >=m)
										{
												flag=0;
												break;
										}		
								}
								if(flag)
									break;
						}
						if(flag)
							break;
				}	
				if(flag)
					printf("safe\n");
				else
					printf("unsafe\n");					
		}
		
}
