a,b=map(int,input().split())
while b%a!=0:
	b,a=a,b%a
print(a*'1')