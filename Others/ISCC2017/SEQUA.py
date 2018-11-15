for _ in range(int(input())):
	m=int(input())
	term=0
	sum=0
	for i in range (0,200):
		term=i**i
		sum+=term
		if i%m==0:
			print(i,sum%m)
