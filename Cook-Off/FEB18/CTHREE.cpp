#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
 	int T;	cin>>T;
 	while(T--)
 	{
 		int n,a,b,c,i;	cin>>n>>a>>b>>c;
 		set < int > fac;
 		set < int >:: iterator it,jt,kt;
		for(i=1;i*i<=n;i++)
 		{
 			if(n%i==0)
 			{
 				fac.insert(i);
 				fac.insert(n/i);
 			}
 		}
		int ans=0;
		for(it=fac.begin();it!=fac.end() && (*it)<=a ; it++)
		{
			if((n%((*it)*(*it))==0) && (n/((*it)*(*it)))<= c && (*it) <=b)
			{
					ans++;	
			}
			for(jt=fac.begin();jt!=fac.end()&&(*jt)<=b; jt++)
			{
				if(jt!=it)
				if((n%((*it)*(*jt)))==0 && (n/((*it)*(*jt))) <= c)
				{
					ans++;				
				}
			}
		}
		cout<<ans<<endl; 		
 	}
}
