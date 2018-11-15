#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	int n,m,p,k,i;	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&n,&m,&p,&k);
		float pr=0.0;
		if(p!=0)
		{		
			if(m%2==1&&n%2==1)
				printf("0.000000\n");
			else if(m%2==0&&n%2==0)
				printf("1.000000\n");		
			else
			{
				if(k<=1000)
				{
				
					float ans=0.00000,x=1.0000000;	
					for(i=0;i<p;i++)	
					{
						ans+=x;
						x=x*(k-i)/((i+1));
					}
					for(i=0;i<k;i++)
						ans=ans/2;
					printf("%f\n",1-ans);
				}
				else
				{
					int ind=0;	
					long long int pow=1;			
					float ans=0.00000,x=1.0000000;
					for(i=0;i<p;i++)	
					{
						ans+=x;	
						if(ans>1)
						{
							while(ans/pow>1)
							{
								pow=pow*2;
								ind++;
							}
							ans=ans/pow;
							x=x/pow;
							pow=1;
						}
						x=(x*(k-i))/(i+1);
					}
					//cout<<ans<<" "<<ind<<endl;
					for(i=k;i<=ind;i++)
							ans=ans*2;
					for(i=ind;i<=k;i++)
							ans=ans/2;					
					cout<<fixed<<setprecision(6)<<1.00-ans<<endl;			
				}
			}	
		}
		else		printf("1.000000\n");		
	}		
}	
