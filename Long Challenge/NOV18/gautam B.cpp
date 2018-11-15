#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long int
int FAC[100000 +2];
int IFAC[100000 +2];
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
	for(i=1;i<=100000;i++)		
	{
		FAC[i]  = (1LL*FAC[i-1]*i)%MOD;
		IFAC[i] = 1LL*power(i,MOD-2)*IFAC[i-1];
		IFAC[i] = IFAC[i]%MOD;
	}
}
int combination(int c,int r)
{
	return (((FAC[c]*1LL*IFAC[r])%MOD)*1LL*IFAC[c-r])%MOD;
}
int solve(int l,int r)
{
	int x = min(l,r);
	int y = max(l,r);
	int i,ans=0;
	if(x == 0)	
		return 0;
	else
	{
		for(i=1;i<=x;i++)
		{
			ans = ans + (combination(x,i)*1LL*combination(y,i))%MOD;
		}
	}
	return ans;
}

set < string > s;
void gen(string a,int n)
{
	if(a.size()==n)
		s.insert(a);
	else
	{
		gen(a+'0',n);
		gen(a+'1',n);
	}
}
main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	compute();
	int T;	cin>>T;
	while(T--)
	{
		int n,i,j;	cin>>n;
		int A[n],ans = 0,ae=0,ao=0,l,r;	
		for(i=0;i<n;i++)	cin>>A[i];
		sort(A,A+n);		
		ans = power(2,n-1);							//ODD length
		
		//cout<<ans<<endl;
		
		map < int ,int > mp;
		map < int ,int > :: iterator mt;
		for(i=0;i<n;i++)	mp[A[i]]++;
		l = 0 , r = n;
		for(mt = mp.begin();mt!=mp.end();mt++)		// EVEN Length subsequences
		{
			r-=mt->second;
			int x = 0,ways = 0;
			for(i=2;i<=mt->second;i=i+2)
			{
			 	ways = combination(mt->second,i);
				int g = min(l,r),k,x=0;
				int pl = -1,pr = -1;
				if(g==l)	pl = l,pr = r;
				else		pl = r,pr = l;
				for(j=0;j<=pl;j++)
				{
					if(j%2==0)	k=0;
					else		k=1;
					while(k<=pr)
					{
						if(abs(k-j)<i)
						{
							//cout<<mt->first<<" "<<i<<" "<<j<<"("<<pl<<")"<<" "<<k<<"("<<pr<<")"<<" "<<(combination(pl,j)*combination(pr,k)*ways)%MOD<<endl;
							x = (x + (combination(pl,j)*1LL*combination(pr,k))%MOD)%MOD; 
						}	
						k = k + 2;	
					}
				}
				
				//cout<<mt->first<<" "<<i<<" "<<x*ways<<endl;
				ans = (ans + (x*1LL*ways)%MOD)%MOD;	
				//ae = ae + x*ways;		
			}
			
			//cout<<ans<<endl;
			
			for(i=3;i<=mt->second;i=i+2)
			{
				ways = combination(mt->second,i);
				int g = min(l,r),k,x=0;
				int pl = -1,pr = -1;
				if(g==l)	pl = l,pr = r;
				else		pl = r,pr = l;
				for(j=0;j<=pl;j++)
				{
					if(j%2==0)	k=1;
					else		k=0;
					while(k<=pr)
					{
						if(abs(k-j)<i)
						{
							//cout<<mt->first<<" "<<i<<" "<<j<<"("<<pl<<")"<<" "<<k<<"("<<pr<<")"<<" "<<(combination(pl,j)*combination(pr,k))%MOD<<endl;
							x = (x + (combination(pl,j)*1LL*combination(pr,k))%MOD)%MOD;
						}	
						k = k + 2;	
					}
				}
				
				//cout<<mt->first<<" "<<i<<" "<<x*ways<<endl;
				ans = (ans + (x*1LL*ways)%MOD)%MOD;	
				//ao = ao + x*ways;
			}
			l+=mt->second;
		}
		cout<<ans<<endl;
		
	}
	
}
