#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long int
int FAC[20000 +2];
int IFAC[20000 +2];
int power(int a,int b)
{
	
	if(b==0)	return 1;
	if(b==1)	return a;
	
	int temp = power(a,b/2);
	int ans = (temp*1LL*temp)%MOD;
	
	if(b%2==1)	  
		ans = (ans *1LL* a)%MOD;
		
	return ans;
}
void compute()
{
	int i;
	FAC[0]=1;
	IFAC[0]=1;
	for(i=1;i<=20000;i++)		
	{
		FAC[i]  = (1LL*FAC[i-1]*i)%MOD;
		IFAC[i] = 1LL*power(i,MOD-2)*IFAC[i-1];
		IFAC[i] = IFAC[i]%MOD;
	}
}
int combination(int c,int r)
{
	if(r>c)		return 0;
	return (((FAC[c]*1LL*IFAC[r])%MOD)*1LL*IFAC[c-r])%MOD;
}
set < string > s;
main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output2.txt","w",stdout);
	compute();
	int T;	cin>>T;
	while(T--)
	{
		int n,i,j;	cin>>n;
		int A[n],ans = 0,l,r;	
		for(i=0;i<n;i++)	cin>>A[i];
		
		sort(A,A+n);		
		map < int ,int > mp;
		map < int ,int > :: iterator mt;
		for(i=0;i<n;i++)	mp[A[i]]++;
		l = 0 , r = n;
		for(mt = mp.begin();mt!=mp.end();mt++)		
		{
			r-=mt->second;
			int x = 0,ways = 0;
			for(i=1;i<=mt->second;i++)
			{
				ways = combination(mt->second,i);
				int k,d=i-1;
				for(j=0;j<=min(l,r);j++)
				{
					
								x = (x + (combination(l,j)*1LL*combination(r,j+d))%MOD)%MOD; 	
					if(d!=0)	x = (x + (combination(l,j+d)*1LL*combination(r,j))%MOD)%MOD; 	
				}
				//cout<<x<<endl;
				ans = (ans + (x*1LL*ways)%MOD)%MOD;		
			}
			l+=mt->second;
		}
		cout<<ans<<endl;
	} 
	
}
