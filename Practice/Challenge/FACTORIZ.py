for _ in range(0,int(input())):
	n=int(input())
	l=[]
	if n%2 ==0:
		while n%2==0:
			l.append(2)
			n=n//2
	for i in range(3,min(n+1,100001),2):
		if n%i==0:
			while n%i==0:
				l.append(i)
				n=n//i
	if n>1:
		l.append(n)
	print(len(l))
	for x in l:
		print(x)