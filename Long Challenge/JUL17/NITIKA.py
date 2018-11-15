import string
for _ in range(int(input())):
	L=[]
	str=input().split()
	if len(str) == 1:
		s=str[0].title()
	elif len(str) == 2:
		L.append(str[0][0].replace(str[0][0],str[0][0].upper()))
		L.append(str[1].title())
		s=". ".join(L)
	else :
		L.append(str[0][0].replace(str[0][0],str[0][0].upper()))
		L.append(str[1][0].replace(str[1][0],str[1][0].upper()))
		L.append(str[2].title())
		s=". ".join(L)
	print(s)