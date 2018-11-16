#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		int bi=1,by=0,nib=0;
		n--;
		if(n>=26)
		{
			int q = n/26;
			bi = pow(2,q);
			n = n%26;
		}
		if(n>=10)
		{
			by = bi;
			bi=0;
			n = n%10;
		}
		if(n>=2)
		{
			nib = bi;
			bi=0;
		}
		cout<<bi<<" "<<nib<<" "<<by<<endl;	
	}	
} 
			 