T=int(input())
while T:
	n=int(input())
	p=5
	ans=0
	m=1
	var=1
	while var==1:
		fac=int(n/p)
		if fac==0:
			var=0
		ans+=fac
		p*=5
	print(ans)
	T=T-1