#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,t,x,y,z;	cin>>n>>t>>x>>y>>z;
		int num=0,den=0;
		if(y == 1 &&  x==0 && z==2 && t == 3)
		{
			num = 1LL;
			den = 1LL;
		}
		else if( (t ==2) && y == 1)
		{
			num = 2*n -1LL;
			den = 2*n +1LL;
		}
		else if(t==1) 			//	A A B
		{
			if(x<y && y>z)					// 0 1 0
			{
				num = y -1LL;
				den = 2LL*n +1LL;
			}
			else if(x<y && y<z)				// 0 1 2
			{
				num = 2LL*n -y;
				den = 2LL*n +1LL;			
			}
			else if(x>y && y>z)				// 2 1 0
			{
				num = 2LL*n +2LL -y;
				den = 2LL*n +1LL;
			}
			else							// 2 1 2
			{
				num = y+1LL;
				den = 2LL*n +1LL;
			}
		}
		else if(t==3)				// A B B 
		{
			if(x<y && y>z)					// 0 1 0 same
			{
				num = y -1LL;
				den = 2LL*n +1LL;
			}
			else if(x<y && y<z)				// 0 1 2
			{
				num = 2LL*n -y + 2LL;
				den = 2LL*n +1LL;			
			}
			else if(x>y && y>z)				// 2 1 0
			{
				num = 2LL*n -y;
				den = 2LL*n +1LL;
			}
			else							// 2 1 2
			{
				num = y+1LL;
				den = 2LL*n +1LL;
			}
		}
		else
		{
			num = 2LL*n - 2LL*y +1LL;
			den = 2LL*n +1LL;	
		}
		
		int g = __gcd(num,den);
		num /= g;
		den /= g;
		
		cout<<num <<" "<<den <<endl;
	}	
}
