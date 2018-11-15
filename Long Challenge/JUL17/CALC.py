for _ in range(int(input())):
	s=list(map(int,input().split()))
	if s[0]>s[1]:
		temp=(s[0]-1)//3
		if s[1] > temp:
			print(s[0]-s[1])
		else:
			print((s[0]*s[0])//(4*s[1]))
	else:
		print("0")