T=int(input())
ans=0
player=0
a=0
b=0
while T:
	s=list(map(int,input().split()))
	a+=s[0]
	b+=s[1]
	if a>b:
		flag=1
		diff=a-b
	else:
		flag=2
		diff=b-a
	if diff>ans:
		ans=diff
		player=flag
	T=T-1
print(str(player)+" "+str(ans))