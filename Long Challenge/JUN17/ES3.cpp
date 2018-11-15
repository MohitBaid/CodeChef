#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,ans=0,i,t1,t2;
	scanf("%lf",&n);
	int k=0;
	for(i=1;i<=n;i=i+1)
	{
		if(i>=2)		ans+=floor(exp(1)*i)-ans;
		else		ans+=floor(exp(1)*i);
		if(i==1)
		{
			t1=ans;
			//printf("%.0lf %.0lf\n",i,ans);
		}
		else
		{
			t2=ans;
			//if(i>=530)
			{
				if(t2-t1==3)
					printf("%.0lf ",t2-t1);	
				else
					printf("2  --- %.0lf\n",i);
			}
			t1=t2;
			k++;
		}
		/*if(k==7)
		{
			printf("\n");
			k=0;
		}*/
		
	}
	//printf("%.0lf",ans);
}
 
