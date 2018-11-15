T=int(input())
while T:
	n=int(input())
	ans=1
	for i in range(1,n+1):
		ans*=i
	print(ans)
	T=T-1
