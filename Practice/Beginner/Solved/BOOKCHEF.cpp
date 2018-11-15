#include<stdio.h>
#include<string.h>
struct p 
{
	int sp;
	int pop;
	char pos[102];
};
int main()
{
	int n,m,i,j;	scanf("%d %d",&n,&m);
	struct p post[m],temp;
	for(i=0;i<m;i++)
	{
		post[i].sp=0;
		post[i].pop=0;
	}	
	int A[n];;
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<m;i++)
	{
		int t,flag=0;		scanf("%d",&t);
		for(j=0;j<n;j++)
			if(t==A[j])
			{
				flag=1;
				break;
			}
		if(flag==1)
				post[i].sp=1;			
		scanf("%d ",&post[i].pop);
		gets(post[i].pos);
	}
	for(i=0;i<m-1;i++)
		for(j=0;j<=m-2;j++)
			{
				if(post[j].sp==post[j+1].sp)
				{
					if(post[j].pop<post[j+1].pop)
						{
								temp=post[j];
								post[j]=post[j+1];
								post[j+1]=temp;		
						}
				}
				if(post[j].sp<post[j+1].sp)
				{
							temp=post[j];
							post[j]=post[j+1];
							post[j+1]=temp;		
				}
			}
	for(i=0;i<m;i++)
		puts(post[i].pos);
	return 0;			
}
