def powermod(a, b, n):
	if b==1:
		return a % n
	if b==0:
		return 1
	r=powermod(a, b//2, n)
	r=r*r % n
	if b%2== 1:
		r = r * a % n
	return r

mod1=1000000007
mod2=1000000009
for _ in range(int(input())):
	n=int(input())
	n=n-2
	if n== -1:
		print("0 0")
	else:
		nume=((n+1)*(n+2))//2
		deno=(2*n+1)
		deno1=powermod(deno,mod1-2,mod1)
		deno2=powermod(deno,mod2-2,mod2)
		print(nume%mod1,nume%mod2)
		ans1=(nume*deno1)%mod1
		ans2=(nume*deno2)%mod2
		print(ans1,ans2)