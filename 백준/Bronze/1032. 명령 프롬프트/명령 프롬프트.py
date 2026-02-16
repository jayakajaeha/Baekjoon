n=int(input())
s=[]
for i in range(n):
	s.append(input())
a=s[0]
a=list(a)
for i in range(1,n):
	for j in range(len(s[i])):
		if a[j]!=s[i][j]:
			a[j]='?'
a=''.join(a)
print(a)