#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,m,i,j,k;	cin>>n>>m;
		int A[n][m],B[n][m],C[n+m -1],D[n+m-1];
		
		if(n==1)
		{
			int c = 0;
			for(i=0;i<m;i++)
			{
				A[0][i++]= c+1;
				A[0][i]= c+1;
				c = (c+1)%2;
			}
		}
		else if(m==1)
		{
			int c = 0;
			for(i=0;i<n;i++)
			{
				A[i++][0]= c+1;
				A[i][0]= c+1;
				c = (c+1)%2;
			}
		}
		else if(n==2)
		{
			int c = 0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					A[i][j] = 1;
					j++;
					if(j==m)	break;
					
					A[i][j] = 2;
					j++;
					if(j==m)	break;
					
					A[i][j] = 3;
				}
			}
		}
		else if(m==2)
		{
			int c = 0;
			for(i=0;i<n;i++)
			{
				A[i][0] = 1;
				A[i][1] = 1;
				
				i++;
				if(i==n)	break;
				
				A[i][0] = 2;
				A[i][1] = 2;
				
				i++;
				if(i==n)	break;
				
				A[i][0] = 3;
				A[i][1] = 3;
			}
		}
		else
		{
			int c = 0;
			for(i=0;i<n;i++)
			{
				C[i++] = c;
				if(i<n)		C[i] = c;
				else		break;	
			
				c = (c+1)%2;
			}
			i++;
			c = 1;
			for(;i<n+m;i++)
			{
				C[i++]=c;
				C[i] = c;
				c = (c+1)%2;
			}	
			for(i=0;i<n+m;i++)
			{
				int row_i = 0;
				int col_i = 0;
				if(i<n)
				{
					row_i = i;
					col_i =0;
				}
				else if(i==n)
					continue;
				else
				{
					row_i =0;
					col_i =i-n;
				}
			
				int c = 0;
				for(j=0;row_i<n && col_i<m;j++)
				{
					
					A[row_i][col_i] = (c+1);
					if(C[i]==1)
						A[row_i][col_i] +=2;	
					c = (c+1)%2;
					row_i++;
					col_i++;
				}
			}		
		}
		
		int ans_k = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				ans_k = max(ans_k,A[i][j]);
			}
		}
		cout<<ans_k<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
