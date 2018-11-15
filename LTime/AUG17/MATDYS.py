for _ in range(int(input())):
	str=list(map(int,input().split()))
	pow=1	
	for i in range(0,str[0]):
		pow=pow*2
	ans=0
	for _ in range (0,str[0]):
		if str[1]%2==0:
			str[1]=str[1]//2
		else:
			str[1]=(str[1]-1)//2
			ans=ans+pow//2
		pow=pow//2
	print(ans)
