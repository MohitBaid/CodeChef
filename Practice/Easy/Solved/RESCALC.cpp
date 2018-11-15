#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		int sco[n];
		for(i=0;i<n;i++)
		{
			sco[i]=0;
			int check[6]={0,0,0,0,0,0};
			int P[6]={0,0,0,0,0,0};
			int c;	scanf("%d",&c);
			sco[i]+=c;
			int t,j;
			for(j=0;j<c;j++)
			{
				scanf("%d",&t);
				check[t-1]++;
				P[t-1]=1;
			}	
			t=0;
			for(j=0;j<6;j++)
				t+=P[j];
			while(t>3)
			{
				if(t==4)		sco[i]+=1;
				else if(t==5)	sco[i]+=2;	
				else if(t==6)	sco[i]+=4;
				for(j=0;j<6;j++)
				{
					check[j]--;
					if(check[j]<=0)
						P[j]=0;
				}			
				t=0;
				for(j=0;j<6;j++)
					t+=P[j];
			}
		}	
		int max=sco[0];
		int p=1;
		for(i=1;i<n;i++)
		{
			if(sco[i]>max)
			{	
				max=sco[i];
				p=i+1;
			}	
		}
		for(i=0;i<n;i++)
		{	
			if(sco[i]==max&&p!=i+1)
			{
				printf("tie\n");
				p=-1;
				break;
			}		
		}	
		if(p==1)
			printf("chef\n");
		else if(p!=-1)
			printf("%d\n",p);	
	}
}
