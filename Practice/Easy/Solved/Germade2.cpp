#include<stdio.h>
int main()
{
	int T;		scanf("%d",&T);	
	while(T--)
	{
		int o1,o2,i,j;	scanf("%d %d",&o1,&o2);
		int A[o1*o2];
		for(i=0;i<o1*o2;i++)
			scanf("%d",&A[i]);
		int k=0,flag=1,m=o2;
		if(o2>100)
			m=100;	
		for(i=0;i<=m+1;i++)
		{
			int c=0;int co=1,k=0;
			for(j=i;co<=(o1*o2);co++,j++)
			{
				
				if(j==o1*o2)			j=0;					
				if(A[j]==1)			c++;
				else				c--;
				
				if(co%o2==0 )
				{
					if(c>0)	{			k++;			/*printf("Increamenting K\n");*/		}
					else	{			k--;			/*printf("Decreamenting K\n");*/		}
					c=0;
					//printf("\n\n");			
				}						
			}
			
			/*printf("--------%d-------\n",k);*/
			if(k>0)
			{
				flag=0;
				break;
			}	
		}
		if(!flag)
			printf("1\n");
		else
			printf("0\n");				
	}
	
}
