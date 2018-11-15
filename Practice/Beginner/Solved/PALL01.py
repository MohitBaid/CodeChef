for _ in range(int(input())):
	n=input()
	p=n[::-1]
	if n == p:
		print("wins")
	else:
		print("losses")