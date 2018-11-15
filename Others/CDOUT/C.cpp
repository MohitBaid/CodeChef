#include<iostream>
#define Mod 1000000007
using namespace std;
long long int inv[200001], ifact[200001], fact[200001];
template<typename T, typename T1>
T mod(T x, T1 p) {
    x %= p;
    if (x < 0)
        x += p;
    return x;
}
template<typename T>
T inverse(T x, T p) {
    x = mod(x, p);
    if (x == 1)
        return x;
    return mod((1LL * (-p / x) * (inv[p % x] % p)) , p); 
}
int NcR(int n, int r) 
{
    int ret = (1LL * ifact[n - r] * ifact[r]) % Mod ;
	ret = (1LL * ret * fact[n]) % Mod;
    return ret;
}
#define ll long long
ll power(ll a, ll b, ll mod){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}	
 
ll modular_inverse(ll n){
	return power(n, Mod-2, Mod);
}
 
ll nCr(ll n, ll k, ll mod){
	return (fact[n]*((modular_inverse(fact[k]*modular_inverse(fact[n-k]))%mod))%mod);
}                        
int main()
{
	int t,i;	cin>>t;	
	fact[0] = 1;
	for(int i = 1; i <=200000; i++) 
			fact[i] = 1LL * fact[i - 1] * i % Mod;
	ifact[0] = 1;
	for(int i = 1; i <=200000; i++) 
			ifact[i] = 1LL * ifact[i - 1] * inverse(i, Mod) % Mod;
	 while(t--)
 	{
 		int n;	cin>>n;
 		n=n/2;
  		long long int c=NcR(2*n,n);
 		printf("%lld\n",c%Mod);
 	}
    return 0;
}
