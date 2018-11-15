T=int(input())
f=T
A=[]
for i in range (0,T):
	k=int(input())
	A.append(k)
A.sort()
for i in range (0,T):
	print(A[i])