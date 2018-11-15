T=int(input())
while T:
	n=int(input())
	ans=0;
	while n:
		ans+=n%10
		n=int(n/10)
	print(ans)
	T=T-1