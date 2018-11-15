T=int(input())
while T:
	str=list(map(int,input().split()))
	temp=str[0]%str[2]
	if temp!=0:
		str[0]+=(str[2]-temp)
	temp=str[1]%str[2]
	if temp!=0:
		str[1]-=temp	
	ans=str[1]-str[0]
	ans=int(ans/str[2])+1
	print(ans)	
	T=T-1