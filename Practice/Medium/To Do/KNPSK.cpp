#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
   int i, j;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j]=0;
           else if (wt[i-1]<=j)
        	   K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
               K[i][j] = K[i-1][j];
	   }
   }
 
   return K[n][W];
}
int main()
{
	int n,i;	scanf("%d",&n);
	int A[n],L[n],s=0;
	priority_queue < int > pq11;
	priority_queue < int > pq21;
	priority_queue < int > pq12;
	priority_queue < int > pq22;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&A[i],&L[i]);
		s+=A[i];
		if(A[i]==1)
		{
			pq11.push(L[i]);
			pq12.push(L[i]);
		}
		else
		{
			pq21.push(L[i]);
			pq22.push(L[i]);
		}
	}
	printf("%d ",pq11.top());
	int a=pq11.top(),temp;			//storing first
	pq11.pop();
	int b=pq21.top();
	if(b>=a+pq11.top())
			printf("%d ",b);
	else
	{
		b=a+pq11.top();
		temp=pq11.pop();
	}
	for(i=3;i<=s;i++)
	{
		//printf("\n------%d %d  %d %d -----  ",a,b,pq1.top(),pq2.top());
		if(a+pq21.top()>=b+pq11.top())
		{
				printf("%d ",pq21.top()+a);
				a=b;
				b=pq2.top()+a;
				pq2.pop();
		}
		else
		{
				printf("%d ",pq1.top()+b);
				a=b;
				b=pq1.top()+b;
				pq1.pop();
		}
	}
}
