import math
mod=1000000000+7
for _ in range(int(input())):
	n=int(input())
	if n==1:
		a=(int(input())*-1)%mod
		if a==mod-1:
			print(1)
			print(a,"1")
		else:
			print(2)
			print(a,"0 1")
	if n==2:
		sr=list(map(int,input().split()))
		a=sr[0]
		b=sr[1]
		a1=((a-b)*(a-b))%mod
		b1=(-2*(a+b))%mod
		print(4)
		print(a1,"0 ",b1,"0 1")
	if n==3:
		sr=list(map(int,input().split()))
		a=sr[0]
		b=sr[1]
		c=sr[2]	
		x1=2*(a+b+c)
		x2=a*a + b*b + c*c -2*(a*b + b*c +c*a)
		a1=(x2*x2)%mod
		b1=(-1*(2*x1*x2 + 64*a*b*c))%mod
		c1=(x1*x1 + 2*x2)%mod
		d1=(-1*2*x1)%mod
		print(8)
		print(str(a1)+" 0 "+str(b1)+" 0 "+str(c1)+" 0 "+str(d1)+" 0 1")