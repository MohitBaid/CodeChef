#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int f,k,s=0;	cin>>f>>k;
		if(f==2)
		{
			cout<<"0.50000000"<<endl;
			continue;
		}
		
		while(k--)
		{
			if(f==1)			break;
			if(f<=2)			f=1,s+=1;
			else if(f%2==0)	
			{	
				if( (f/2)%2 == 1 )	
				{
					if(s>= f/2)
					{
						s += f/2;		
						f = f/2;
					}
					else
					{
						s +=(f/2 -1);
						f = f/2 +1;
					}
				}
				else					
				{
					s+= f/2;
					f = f/2;
				}
			}
			else						
			{
				s += (f/2 -1);
				f = f/2 +1;
			}
			//cout<<f<<" "<<s<<endl;
		}
			
		double x = 1.0/f;
		printf("%.20lf\n",x);
	}
}
