#include<stdio.h>
#include<stdlib.h>
struct num
{
	int k;
	int l;
	int r;
	int no;
};
int A[100003];
struct num r[100000];
int cmpfunc(const void *p, const void *q) 
{
    long long int l = ((struct num *)p)->k;
    long long int r = ((struct num *)q)->k; 
    if(l>r)
    	return -1;
    else if(l<r)
		return 1;
	else
		return 0;		
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{	
		int n,m,i;	scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		A[n]=-1;	
		int c=0,f=0;	
		for(i=0;i<n;i++)
		{
			if(A[i]==A[i+1])
			{
				if(c==0)	c=2;
				else		c++;
			}
			else
			{
				if(c!=0)
				{
					r[f].k=c;
					r[f].no=A[i];
					r[f].l=i+1-c+1;
					r[f].r=i+1;	
					f++;
					c=0;
				}
				else
				{
					r[f].k=c+1;
					r[f].no=A[i];
					r[f].l=i+1-c;
					r[f].r=i+1;	
					f++;
					c=0;
				}	
			}		
		}
		qsort(r,f,sizeof(struct num),cmpfunc);
		/*for(i=0;i<f;i++)
			printf("%d -- %d %d --   >%d\n",r[i].no,r[i].l,r[i].r,r[i].k);*/
		while(m--)
		{
			int lo,ro,ko;	scanf("%d %d %d",&lo,&ro,&ko);
			int flag=0,pos=-1,ans=0;
			for(i=0;i<f;i++)	
			{
				if(r[i].k>=ko)
				{
					int lt,rt;
					if(r[i].l<lo)
					{
						if(r[i].r<lo)
						{
							lt=-1;
							rt=-1;
						}
						else
						{
							lt=lo;
							rt=r[i].r;
						}
					}
					else
					{
						if(r[i].l>ro)
						{
							lt=-1;
							rt=-1;
						}
						else
						{
							if(r[i].r<=ro)
							{
								lt=r[i].l;
								rt=r[i].r;
							}
							else
							{
								lt=r[i].l;
								rt=ro;
							}
						}	
					}
					if(rt-lt+1>=ko  && rt!=-1)  	ans++;
				}
				if(r[i].k<ko)	break;			
			}
			printf("%d\n",ans);					
		}
	}
}
