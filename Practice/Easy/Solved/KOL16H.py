a=1
for _ in range(int(input())):
	n=int(input())
	if n<=33:
		ans=pow(2,n)-1
	else:
		ans=pow(2,33)-1
	print("Case "+str(a)+": "+str(ans))
	a=a+1