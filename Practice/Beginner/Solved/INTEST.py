str=input()	
s=str.split()
n=int(s[0])	
k=int(s[1])
c=0
for T in range (0,n):
	x=int(input())
	if x%k==0:
		c=c+1
print(c)