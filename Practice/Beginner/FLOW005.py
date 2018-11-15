L=[100,50,10,5,2,1]
for _ in range(int(input())):
	n=int(input())
	ans=0
	for i in range(0,6):
		ans+=n//L[i]
		n=n%L[i]
	print(ans)