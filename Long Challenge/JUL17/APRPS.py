import math
mod=1000000000+7
for _ in range(int(input())):
	n=int(input())
	raw_input=set(map(int,input().split()))
	n=len(raw_input)
	raw_input=list(raw_input)
	if n==1 :
		a=mod-raw_input[0]
		print(2)
		print(str(a)+" 0 1")
	elif n==2:
		a=raw_input[0]
		b=raw_input[1]
		print(4)
		last=((a-b)*(a-b))%mod
		mid=(-1*(2*(a+b)))%mod

		print(str(last)+" 0 "+str(mid)+" 0 1")
	elif n==3:
		a=raw_input[0]
		b=raw_input[1]
		c=raw_input[2]
		f1=(math.sqrt(a)+math.sqrt(b)+math.sqrt(c))**2
		f2=(math.sqrt(a)-math.sqrt(b)+math.sqrt(c))**2
		f3=(math.sqrt(a)+math.sqrt(b)-math.sqrt(c))**2
		f4=(math.sqrt(a)-math.sqrt(b)-math.sqrt(c))**2
		print(8)
		ans4=(a*a+b*b+c*c-2*(a*c+b*c+a*b))*(a*a+b*b+c*c-2*(a*c+b*c+b*a))%mod;
		ans3=int((f1*f2*f3)+(f2*f3*f4)+(f1*f3*f4)+(f2*f3*f4)*-1)
		ans3=ans3%mod
		ans2=(6*(a*a + b*b + c*c) + 4*(a*b + a*c + b*c))%mod
		ans1=(-4*(a+b+c))%mod
		print(str(ans4)+" 0 "+str(ans3)+" 0 "+str(ans2)+" 0 "+str(ans1)+" 0 1")
  