#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,m,i,c=0;	scanf("%d %d",&n,&m);
				int A[n],B[m];
				int beg,mid,end;
				for(i=0;i<n;i++)		scanf("%d",&A[i]);
				for(i=0;i<m;i++)		scanf("%d",&B[i]);
				std::sort(A,A+n);
				for(i=0;i<m;i++)
        		{
        		   	 beg=0;
        		   	 end=n-1;
          			while(beg<=end)
         			  {
            			   mid=(beg+end)/2;
            			   if(B[i]==A[mid])
            			   {
                   				c++;
                	   			break;
               				}
               				else if(B[i]>A[mid])
                   				beg=mid+1;
            			   else if(B[i]<A[mid])
                   				end=mid-1;
           				}
        		}
      			printf("%d\n",c);
		}
		return 0;	
}
