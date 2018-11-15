#include<bits/stdc++.h>
int validate(char ch[][50],int n)
{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ch[i][j]=='G')
				{
						if(i+1<n && ch[i+1][j]!='.') 
									return 0;		
						if(j-1>=0 && ch[i][j-1]!='.' )
									return 0;
						if(j+1<n && ch[i][j+1]!='.')
									return 0;
						if(i-1>=0 && ch[i-1][j]!='.')
									return 0;								
				}		
				if(ch[i][j]=='B')
				{
						if(i+1<n && ch[i+1][j]=='P') 
									return 0;		
						if(j-1>=0 && ch[i][j-1]=='P' )
									return 0;
						if(j+1<n && ch[i][j+1]=='P')
									return 0;
						if(i-1>=0 && ch[i-1][j]=='P')
									return 0;		
						if(i+1<n && ch[i+1][j]=='G') 
									return 0;		
						if(j-1>=0 && ch[i][j-1]=='G' )
									return 0;
						if(j+1<n && ch[i][j+1]=='G')
									return 0;
						if(i-1>=0 && ch[i-1][j]=='G')
									return 0;									
				}	
				if(ch[i][j]=='P')
				{
						if(i+1<n && ch[i+1][j]=='B') 
									return 0;		
						if(j-1>=0 && ch[i][j-1]=='B' )
									return 0;
						if(j+1<n && ch[i][j+1]=='B')
									return 0;
						if(i-1>=0 && ch[i-1][j]=='B')
									return 0;		
						if(i+1<n && ch[i+1][j]=='G') 
									return 0;		
						if(j-1>=0 && ch[i][j-1]=='G' )
									return 0;
						if(j+1<n && ch[i][j+1]=='G')
									return 0;
						if(i-1>=0 && ch[i-1][j]=='G')
									return 0;									
				}				
			}
		}
		return 1;
}
int check(char ch[][50],int c,int n)
{
		int i,j;
		if(c>0)
		{
			int ans=0;
			int f=c;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(ch[i][j]=='?' &&f==c)
					{
							char ch2[50][50],ch3[50][50],ch4[50][50];
							for(int k=0;k<n;k++)
								for(int y=0;y<=n;y++)
									ch2[k][y]=ch[k][y];		
							ch2[i][j]='B';
								ans+= check(ch2,c-1,n);
							for(int k=0;k<n;k++)
								for(int y=0;y<=n;y++)
									ch3[k][y]=ch[k][y];		
							ch3[i][j]='G';
								ans+= check(ch3,c-1,n);
							for(int k=0;k<n;k++)
								for(int y=0;y<=n;y++)
									ch3[k][y]=ch[k][y];		
							ch3[i][j]='P';
								ans+= check(ch3,c-1,n);			
							c--;	
					}	
				}
			}
			return ans;
		
		}
		if(c==0)
		{
			int ans=0;
			ans=validate(ch,n);
			return ans;			
		}
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
			int n,i,j;	scanf("%d",&n);
			char ch[50][50]; 
			for(i=0;i<n;i++)
				scanf("%s",ch[i]);
			int ans=0,c=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(ch[i][j]=='?')
						c++;
				}
			}
			if(c==0)
			{	
				int ans=0;
				ans=validate(ch,n);
				printf("%d\n",ans);			
			}
			else
			{
				ans=check(ch,c,n);
				printf("%d\n",ans);	
			}
	}
}
