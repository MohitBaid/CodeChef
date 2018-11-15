A=[0]*1000005
A[0]=1
A[1]=1
mod=1000000000+7
for i in range(2,1000002):
	A[i]=(i-1)*A[i-2]+A[i-1]
	A[i]=A[i]%mod
for _ in range(int(input())):
	print(A[int(input())])