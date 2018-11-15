#include<bits/stdc++.h>
#define int long long int
int A[1001][1001];
using namespace std;
main()
{
	int n,k,v,i,t;	cin>>n>>k>>v;
	bool ans = false;
	int lc = 1,rc = n,ur=1,dr=n;
	for(;k>0 && ans == false;)
	{	
		if(A[ur][lc] == 0)
		{
			cout<<"1 "<<ur<<" "<<lc<<endl,k--;
			fflush(stdout);
			
			cin>>A[ur][lc];
			
			if(A[ur][lc]==v)
			{
				ans = true;
				cout<<"2 "<<ur<<" "<<lc<<endl;
				fflush(stdout);
				break;
			}
			
			if(k==0)	break;
		}
		if(A[ur][rc] == 0)
		{
			cout<<"1 "<<ur<<" "<<rc<<endl,k--;
			fflush(stdout);
			
			cin>>A[ur][rc];
			
			if(A[ur][rc]==v)
			{
				ans = true;
				cout<<"2 "<<ur<<" "<<rc<<endl;
				fflush(stdout);
				break;
			}
			if(k==0)	break;
		}	
		if(A[dr][lc] == 0)
		{
			cout<<"1 "<<dr<<" "<<lc<<endl,k--;
			fflush(stdout);
			
			cin>>A[dr][lc];
			
			if(A[dr][lc]==v)
			{
				ans = true;
				cout<<"2 "<<dr<<" "<<lc<<endl;
				fflush(stdout);
				break;
			}
			if(k==0)	break;
		}
		if(A[dr][rc] == 0)
		{
			cout<<"1 "<<dr<<" "<<rc<<endl,k--;
			fflush(stdout);
			
			cin>>A[dr][rc];
			
			if(A[dr][rc]==v)
			{
				ans = true;
				cout<<"2 "<<dr<<" "<<rc<<endl;
				fflush(stdout);
				break;
			}
			if(k==0)	break;
		}
		
		 		
 		if( !( ( A[ur][lc]>v && A[ur][rc]<v ) || ( A[ur][lc]<v && A[ur][rc]>v ) ) )			
		{	
			while(!( ( A[ur][lc]>v && A[dr][rc]<v ) || ( A[ur][lc]<v && A[dr][rc]>v ) ) )
			{
				ur++;
				if(ur == n+1)	break;	
				if(A[ur][lc] == 0)
				{
					cout<<"1 "<<ur<<" "<<lc<<endl,k--;
					fflush(stdout);
					
					cin>>A[ur][lc];
					
					if(A[ur][lc]==v)
					{
						ans = true;
						cout<<"2 "<<ur<<" "<<lc<<endl;
						fflush(stdout);
						break;
					}
					
					if(k==0)	break;
				}
				if(A[ur][rc] == 0)
				{
					cout<<"1 "<<ur<<" "<<rc<<endl,k--;
					fflush(stdout);
					
					cin>>A[ur][rc];
					
					if(A[ur][rc]==v)
					{
						ans = true;
						cout<<"2 "<<ur<<" "<<rc<<endl;
						fflush(stdout);
						break;
					}
					if(k==0)	break;
				}		
			}
		}
		
		if(ur>dr)		break;
		
		if(  !( ( A[dr][lc]>v && A[dr][rc]<v ) || ( A[dr][lc]<v && A[dr][rc]>v ) ) )			
		{		
			while(!( ( A[dr][lc]>v && A[dr][rc]<v ) || ( A[dr][lc]<v && A[dr][rc]>v ) ))
			{
				dr--;
				if(dr == -1)	break;	
				if(A[dr][lc] == 0)
				{
					cout<<"1 "<<dr<<" "<<lc<<endl,k--;
					fflush(stdout);
					
					cin>>A[dr][lc];
					
					if(A[dr][lc]==v)
					{
						ans = true;
						cout<<"2 "<<dr<<" "<<lc<<endl;
						fflush(stdout);
						break;
					}
					if(k==0)	break;
				}
				if(A[dr][rc] == 0)
				{
					cout<<"1 "<<dr<<" "<<rc<<endl,k--;
					fflush(stdout);
					
					cin>>A[dr][rc];
					
					if(A[dr][rc]==v)
					{
						ans = true;
						cout<<"2 "<<dr<<" "<<rc<<endl;
						fflush(stdout);
						break;
					}
					if(k==0)	break;
				}		
			}
		}
		
		if(ur>dr)		break;
		
		
		if( !( (A[ur][lc]>v && A[dr][lc]<v) || (A[ur][lc]<v && A[dr][lc]>v) ) )
		{
			while(!( (A[ur][lc]>v && A[dr][lc]<v) || (A[ur][lc]<v && A[dr][lc]>v) ))
			{
				lc++;
				if(lc == n+1)	break;	
				if(A[ur][lc] == 0)
				{
					cout<<"1 "<<ur<<" "<<lc<<endl,k--;
					fflush(stdout);
					
					cin>>A[ur][lc];
					
					if(A[ur][lc]==v)
					{
						ans = true;
						cout<<"2 "<<ur<<" "<<lc<<endl;
						fflush(stdout);
						break;
					}
				
					if(k==0)	break;
				}
				
				if(A[dr][lc] == 0)
				{
					cout<<"1 "<<dr<<" "<<lc<<endl,k--;
					fflush(stdout);
					
					cin>>A[dr][lc];
					
					if(A[dr][lc]==v)
					{
						ans = true;
						cout<<"2 "<<dr<<" "<<lc<<endl;
						fflush(stdout);
						break;
					}
					if(k==0)	break;
				}
			}
		}
		
		if(lc>rc)	break;
		
		if( !( (A[ur][rc]>v && A[dr][rc]<v) || (A[ur][rc]<v && A[dr][rc]>v) ) )
		{
			while( !( (A[ur][rc]>v && A[dr][rc]<v) || (A[ur][rc]<v && A[dr][rc]>v) ) )
			{
				rc--;
				if(rc == 0)	break;	
				if(A[ur][rc] == 0)
				{
					cout<<"1 "<< ur <<" "<<rc<<endl,k--;
					fflush(stdout);
					
					cin>>A[ur][rc];
					
					if(A[ur][rc]==v)
					{
						ans = true;
						cout<<"2 "<<ur<<" "<<rc<<endl;
						fflush(stdout);
						break;
					}
					if(k==0)	break;
				}
				
				if(A[dr][rc] == 0)
				{
					cout<<"1 "<<dr<<" "<<rc<<endl,k--;
					fflush(stdout);
					
					cin>>A[dr][rc];
					
					if(A[dr][rc]==v)
					{
						ans = true;
						cout<<"2 "<<dr<<" "<<rc<<endl;
						fflush(stdout);
						break;
					}
					if(k==0)	break;
				}				
			}
		}
		
 		if(lc>rc)	break;
 				
		if( ( A[ur][lc]>v && A[ur][rc]<v ) || ( A[ur][lc]<v && A[ur][rc]>v ))						//R1
		{	
			int l = lc;
			int u = rc;
			while(l <= u)
			{
				
				int m;// = (l + u )/2;
				if(A[ur][lc]<A[ur][rc])
				{
					m = l + (v - A[ur][lc])*(u - l) / (A[ur][rc] - A[ur][lc]);
				}
				else
				{
					m = u - (v - A[ur][rc])*(u - l) / (A[ur][lc] - A[ur][rc]);
				}
				
				if(A[ur][m] == 0)
				{
				
					cout<<"1 "<< ur <<" "<< m <<endl,k--;
					fflush(stdout);
					
					cin>>A[ur][m];
				}
				if(A[ur][m] == v)
				{
					ans = true;
					cout<<"2 "<<ur<<" "<< m <<endl;
					fflush(stdout);
					break;
				}
				else
				{
					if(A[ur][m]>v)
					{
						if(A[ur][lc]>A[ur][rc])		l = m+1;
						else						u = m-1;	
					}
					else
					{
						if(A[ur][lc]>A[ur][rc])		u = m-1;
						else						l = m+1;	
					}
				}
				
				if(k==0)	break;
			}
			ur++;
		}
		
		if(ur>dr)		break;
		
		if( ( A[dr][lc]>v && A[dr][rc]<v ) || ( A[dr][lc]<v && A[dr][rc]>v ))		//R2	
		{		
			int l = lc;
			int u = rc;
			while(l <= u)
			{
				
				int m;// = (l + u )/2;
				if(A[dr][lc]<A[dr][rc])
				{
					m = l + (v - A[dr][lc])*(u - l) / (A[dr][rc] - A[dr][lc]);
				}
				else
				{
					m = u - (v - A[dr][rc])*(u - l) / (A[dr][lc] - A[dr][rc]);
				}
				if(A[dr][m] == 0)
				{
				
					cout<<"1 "<< dr <<" "<< m <<endl,k--;
					fflush(stdout);
					
					cin>>A[dr][m];
				}
				if(A[dr][m] == v)
				{
					ans = true;
					cout<<"2 "<<dr<<" "<< m <<endl;
					fflush(stdout);
					break;
				}
				else
				{
					if(A[dr][m]>v)
					{
						if(A[dr][lc]>A[dr][rc])		l = m+1;
						else						u = m-1;	
					}
					else
					{
						if(A[dr][lc]>A[dr][rc])		u = m-1;
						else						l = m+1;	
					}
				}
				
				if(k==0)	break;
			}
			dr--;
		}
		
		if(ur>dr)		break;
		
		if( ( A[ur][lc]>v && A[dr][lc]<v ) || ( A[ur][lc]<v && A[dr][lc]>v ))						//C1
		{		
			int l = ur;
			int u = dr;
			while(l <= u)
			{
				
				int m;// = (l + u )/2;
				if(A[ur][lc]<A[dr][lc])
				{
					m = l + (v - A[ur][lc])*(u - l) / (A[dr][lc] - A[ur][lc]);
				}
				else
				{
					m = u - (v - A[dr][lc])*(u - l) / (A[ur][lc] - A[ur][rc]);
				}
				if(A[m][lc] == 0)
				{
				
					cout<<"1 "<< m <<" "<< lc<<endl,k--;
					fflush(stdout);
					
					cin>>A[m][lc];
				}
				if(A[m][lc] == v)
				{
					ans = true;
					cout<<"2 "<<m<<" "<< lc <<endl;
					fflush(stdout);
					break;
				}
				else
				{
					if(A[m][lc]>v)
					{
						if(A[ur][lc]>A[dr][lc])		l = m+1;
						else						u = m-1;	
					}
					else
					{
						if(A[ur][lc]>A[dr][lc])		u = m-1;
						else						l = m+1;	
					}
				}
				
				if(k==0)	break;
			}
			lc++;
		}
		
		if(lc>rc)		break;
		
		if( ( A[ur][rc]>v && A[dr][rc]<v ) || ( A[ur][rc]<v && A[dr][rc]>v ))		//C2
		{		
			//cout<<"C2"<<endl;
			int l = ur;
			int u = dr;
			while(l <= u)
			{
				
				int m;// = (l + u )/2;
				if(A[ur][rc]<A[dr][rc])
				{
					m = l + (v - A[ur][rc])*(u - l) / (A[dr][rc] - A[ur][rc]);
				}
				else
				{
					m = u - (v - A[dr][rc])*(u - l) / (A[dr][lc] - A[ur][rc]);
				}
				if(A[m][rc] == 0)
				{
				
					cout<<"1 "<< m <<" "<< rc <<endl,k--;
					fflush(stdout);
					
					cin>>A[m][rc];
				}
				if(A[m][rc] == v)
				{
					ans = true;
					cout<<"2 "<<m<<" "<< rc <<endl;
					fflush(stdout);
					break;
				}
				else
				{
					if(A[m][rc]>v)
					{
						if(A[ur][rc]>A[dr][rc])		l = m+1;
						else						u = m-1;	
					}
					else
					{
						if(A[ur][rc]>A[dr][rc])		u = m-1;
						else						l = m+1;	
					}
				}
				if(k==0)	break;
			}
			rc--;
		}
				
		if(lc>rc)		break;
	}
	if(ans == false)	
	{
		cout<<"2 -1 -1"<<endl;
		fflush(stdout);
	}
}  
