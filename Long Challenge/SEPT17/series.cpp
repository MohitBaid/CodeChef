#include<bits/stdc++.h>
using namespace std;
int  main()
{
	int y,z,i;	cin>>y;
	for(z=y;z<=y;z=z+1)
	{
		int C[z],len=1;
		for(i=0;i<z;i++)	C[i]=0;		C[0]=1;
		//int k=64;
		while(1)
		{
			int sum=0,lev=z;
			for(i=1;i<lev;i++)
			{
				C[i]+=C[i-1];
				C[i]=C[i]%2;
				sum+=C[i];
			}
			if(len)	
			{
				for(i=0;i<lev;i++)		cout<<C[i]<<" ";	cout<<"---> "<<(64-len)%64;	cout<<endl;
			}
			sum=0;
			for(i=1;i<lev;i++)
				if(C[i]%2)
				{
					sum=1;
					break;
				}
			if(sum)
			{
				//ans[len]=0;
				//for(i=0;i<lev;i++)		if(C[i])		ans[len]=ans[len]^R[i];
				len++;
			}
			else		break;
		}
		cout<<z<<" "<<len<<endl;
	}
}
