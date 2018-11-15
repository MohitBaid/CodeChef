for _ in range(int(input())):
	s=input()
	c="101"
	if c in s:
		print("Good")
	else:
		c="010"
		if c in s:
			print("Good")
		else:
			print("Bad")
