str=input()
s=str.split()
x=float(s[0]);
y=float(s[1]);
if x%5==0:
	if x+0.5<=y:
		print(y-x-.5)
	else:
		print(y)
else:
	print(y)