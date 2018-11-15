import math
import fractions
MOD=1000000007
def pow(a,p):
	if p==0:
		return 1
	if p==1:
		return a
	temp=pow(a,p//2)
	if p%2==1:
		return ((temp*temp)%MOD*a)%MOD
	else :
		return (temp*temp)%MOD

for _ in range(int(input())):
	le,d,t=map(int,input().split())
	w=math.acos(d/le)
	z=str(fractions.Fraction(w).limit_denominator())
	z=list(map(int,z.split('/')))
	if len(z)==1:
		z[0]=z[0]*t
		w=math.cos(z[0])
	else:
		z[0]=z[0]*t
		w=math.cos(z[0]/z[1])
	s=str(fractions.Fraction(w).limit_denominator())
	l=list(map(int,s.split('/')))
	if len(l)==1:
		print((l[0]*le)%MOD)
	else :
		p=l[0]*le
		q=l[1]
		g=math.gcd(p,q)
		p=p//g
		q=q//g
		r=pow(q,MOD-2)	
		print((p*r)%MOD)