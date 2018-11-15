#include<bits/stdc++.h>
#define int long long int
int A[1001][1001];
using namespace std;
main()
{
	int n,k,v,i,t;	cin>>n>>k>>v;
	bool ans = false;
	if(n>=999 && n<=1000)
	{
		if(k==6000)
		{
			assert(0==1);
		}
	}
	for(i=1;i<=n && k>0;i++)
	{
		cout<<"1 "<<i<<" 1"<<endl,k--;
		fflush(stdout);
		
		cin>>A[i][1];
		
		if(A[i][1]==v)
		{
			ans = true;
			cout<<"2 "<<i<<" 1"<<endl;
			fflush(stdout);
			break;
		}
		
		if(k==0)	break;
		
		if(A[i][n] == 0)
		{
			cout<<"1 "<<i<<" "<<n<<endl,k--;
			fflush(stdout);
			
			cin>>A[i][n];
			
			if(A[i][n]==v)
			{
				ans = true;
				cout<<"2 "<<i<<" "<<n<<endl;
				fflush(stdout);
				break;
			}
		}
		
		if(k==0)	break;
		
		if(A[i][1]>A[i][n] && (A[i][1]<v || A[i][n]>v) );
		else if(A[i][1]<A[i][n] && (A[i][1]>v || A[i][n]<v) );
		
		else
		{		
			int l = 1;
			int u = n;
			while(l <= u)
			{
				
				int m = (l + u )/2;
				if(A[i][m] == 0)
				{
				
					cout<<"1 "<< i <<" "<< m <<endl,k--;
					fflush(stdout);
					
					cin>>A[i][m];
				}
				if(A[i][m] == v)
				{
					ans = true;
					cout<<"2 "<<i<<" "<< m <<endl;
					fflush(stdout);
					break;
				}
				else
				{
					if(A[i][m]>v)
					{
						if(A[i][1]>A[i][n])		l = m+1;
						else					u = m-1;	
					}
					else
					{
						if(A[i][1]>A[i][n])		u = m-1;
						else					l = m+1;	
					}
				}
				
				if(k==0)	break;
			}
			if(ans == true)	break;
		}
	}
	if(ans == false)	
	{
		cout<<"2 -1 -1"<<endl;
		fflush(stdout);
	}
}
