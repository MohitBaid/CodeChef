#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{	
		int n,i;	cin>>n;
		if(n==0)	break;
		int A[n],B[n];
		for(i=0;i<n;i++)
		{
			cin>>A[i];
			B[A[i]-1]=i+1;
		}
		if(n!=0)
		{
			int flag=1;
			for(i=0;i<n;i++)
			{
				if(A[i]!=B[i])
				{
					flag=0;
					break;
				}
			}	
			if(!flag)	printf("not ambiguous\n");
			else		printf("ambiguous\n");		
		}
	}
}
