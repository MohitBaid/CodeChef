#include<stdio.h>
int main()
{
	int T;		scanf("%d",&T);	
	while(T--)
	{
		int o1,o2,i,j;	scanf("%d %d",&o1,&o2);
		int A[o1*o2+(o2)];
		for(i=0;i<o1*o2;i++)
				scanf("%d",&A[i]);	
		for(i=0;i<o2;i++)
				A[i+o1*o2]=A[i];
		int sum=0,flag=1;
		int k[o2];				
		for(i=0;i<o2;i++)
		{
				sum+=A[i];
				k[i]=0;
		}			
		int m=0;
		for(j=o2;j<(o1*o2)+(o2);j++)
		{
			if(sum>=(o2/2)+1)
				k[m++]++;
			sum=sum-A[j-o2]+A[j];
			m=m%o2;	
		}
		if(sum>=(o2/2)+1)
				k[m++]++;
		for(i=0;i<o2;i++)
		{
			if(k[i]>=((o1/2)+1))
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
