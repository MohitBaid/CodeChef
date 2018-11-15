#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct pos
{
	int x;
	int y;
	int score;
};
int main()
{
		int T,i,j,k;	scanf("%d",&T);
		while(T--)
		{
				int n,m,l,ans=0;	scanf("%d %d",&l,&n);
				char ch[l+2];		scanf("%s",ch);
				int flag=0,c2=0;
				char grid[n+1][n+1];
				int l1=l;
				for(i=0;i<n;i++)
					scanf("%s",grid[i]);
				struct pos p[l];
				int x=0,y=0;
				for(i=0;ch[i]!='\0';i++)
				{
					if(ch[i]=='L')
					{
						printf("LL\n");
						int flag=1;
						x--;
						for(j=0;j<m;j++)
						{
							if(p[j].x==x&&p[j].y==y)
							{
								flag=0;
								break;
							}
						}
						if(flag)
						{
							p[m].x=x;
							p[m].y=y;
							p[m].score=i+1;
							m++;
						}
						else
						{
							p[j].score=i+1;	
						}
					}
					if(ch[i]=='R')
					{
						printf("RR\n");
						int flag=1;
						x++;
						for(j=0;j<m;j++)
						{
							if(p[j].x==x&&p[j].y==y)
							{
								flag=0;
								break;
							}
						}
						if(flag)
						{
							p[m].x=x;
							p[m].y=y;
							p[m].score=i+1;
							m++;
						}
						else
						{
							p[j].score=i+1;	
						}
					}
					if(ch[i]=='D')
					{
						printf("DD\n");
						int flag=1;
						y++;
						for(j=0;j<m;j++)
						{
							if(p[j].x==x&&p[j].y==y)
							{
								flag=0;
								break;
							}
						}
						if(flag)
						{
							p[m].x=x;
							p[m].y=y;
							p[m].score=i+1;
							m++;
						}
						else
						{
							p[j].score=i+1;	
						}
					}
					if(ch[i]=='U')
					{
						printf("UU\n");
						int flag=1;
						y--;
						for(j=0;j<m;j++)
						{
							if(p[j].x==x&&p[j].y==y)
							{
								flag=0;
								break;
							}
						}
						if(flag)
						{
							p[m].x=x;
							p[m].y=y;
							p[m].score=i+1;
							m++;
						}
						else
						{
							p[j].score=i+1;	
						}
					}
				}
				for(i=0;i<m;i++)
					cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].score<<endl;
				for(i=0;i<n;i++)
				{
						for(j=0;j<n;j++)
						{
								if(grid[i][j]=='.')
								{
									int xi=i;
									int yi=j;
									int c=0;
									for(k=0;k<m;k++)				
									{
										xi+=p[k].x;
										yi+=p[k].y;				
										if(yi<0 || yi >=n)
												break;
										if(xi<0 || xi >=n)
												break;
										if(grid[xi][yi]=='#')
												break;	
										c=p[k].score;	
									}
									ans=(ans^c);
								}
						}
				}	
					printf("%d\n",ans);
		}
}
