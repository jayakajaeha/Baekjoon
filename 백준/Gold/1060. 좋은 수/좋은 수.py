l=int(input())
s=map(int, input().split())
s=sorted(s)
n=int(input())
b={}
b[0]=[]
h=n
if s[0]-1<n:h=int(s[0]/2+1)
h1=n
for j in range(1,h):
	b[(j-1)*(s[0]-1-j)+s[0]-2]=[]
if h==1 and s[0]==2:
	b[0].append(1)
for i in range(0,l-1):
	h1=n
	if s[i+1]-s[i]-1<n:h1=int((s[i+1]-s[i])/2+1)
	for j in range(1,h1):
		b[(j-1)*(s[i+1]-1-s[i]-j)+s[i+1]-s[i]-2]=[]
for j in range(1,h):
	if j!=s[0]-j:
		b[(j-1)*(s[0]-1-j)+s[0]-2].append(j)
		b[(j-1)*(s[0]-1-j)+s[0]-2].append(s[0]-j)
	else:b[(j-1)*(s[0]-1-j)+s[0]-2].append(j)
for i in range(0,l-1):
	h1=n
	if s[i+1]-s[i]-1<n:h1=int((s[i+1]-s[i])/2+1)
	for j in range(1,h1):
		if s[i]+j!=s[i+1]-j:
			b[(j-1)*(s[i+1]-1-s[i]-j)+s[i+1]-s[i]-2].append(s[i]+j)
			b[(j-1)*(s[i+1]-1-s[i]-j)+s[i+1]-s[i]-2].append(s[i+1]-j)
		else:b[(j-1)*(s[i+1]-1-s[i]-j)+s[i+1]-s[i]-2].append(s[i]+j)
for i in s:
	b[0].append(i)
b=dict(sorted(b.items()))
k=list(b.keys())
b[k[-1]+1]=[]
for i in range(s[-1]+1,s[-1]+n):
	b[k[-1]+1].append(i)
k=list(b.keys())
v=list(b.values())
cnt=0
idx=0
while cnt!=n:
	v[idx]=sorted(v[idx])
	for i in v[idx]:
		print(i,end=' ')
		cnt+=1
		if cnt==n:break
	idx+=1