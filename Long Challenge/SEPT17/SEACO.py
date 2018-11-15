mod=1000000007
for _ in range (int(input())):
	str=list(map(int,input().split()))
	n=str[0]
	m=str[1]
	sl=[0]*(m+2)
	sr=[0]*(m+2)
	B=[0]*(m+2)
	A=[0]*(n+2)
	C=[0]*(m+2)
	for i in range (1,m+1):
		str=list(map(int,input().split()))
		c=str[0]
		l=str[1]
		r=str[2]
		sl[i-1]=l
		sr[i-1]=r
		if c==1 :
			B[i]=0
			A[l]=A[l]+1
			A[r+1]=A[r+1]-1
		else :
			C[i]=-1
			B[l]=B[l]+1
			B[r+1]=B[r+1]-1
	for i in range(1,m+1):
		B[i]=B[i]+B[i-1]
	for i in range(m,0,-1):
		if C[i] == -1:
			l=sl[i-1]
			r=sr[i-1]
			for j in range (l,r+1):
				B[j]=B[j]+B[i]
			B[i]=0
	for i in range(1,m+1):
		l=sl[i-1]
		r=sr[i-1]
		A[l]=A[l]+B[i]
		A[r+1]=A[r+1]-B[i]
	for i in range(1,n+1):
		A[i]=A[i]+A[i-1]
	for i in range(1,n+1):
		print(A[i]%mod,end=' ')
	print()