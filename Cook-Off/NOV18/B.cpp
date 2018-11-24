#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)n
	{
		int a,b,c,i,ans=0;	
		cin>>a>>b>>c;
		//c= min(a,c);
		int k=0;
		if(c>a)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(b==c && b==1)	
		{
			cout<<a<<endl;
			continue;
		}
		else if(b==c)		k = a/(c-1);
		else if(c==1)		k = b/(b-c);
		else				k = min(a/(c-1) , b/(b-c));
		
		int sub = a-k*c;
		if(sub<0)	ans = sub;
		
		if(k>c)
		{
			ans = ans + (c*(c+1)/2);
			k-=c;
			ans = ans + c*k;
		}
		else
		{
			ans = ans + (k*(k+1)/2);
		}
		cout<<ans<<endl;
	}
}
