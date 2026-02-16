def digit(T):
	for j in range(len(T)):
		if j<len(T)-1:
			T[j+1]+=T[j]//36
			T[j]%=36
		if j>=len(T)-1 and T[j]>=36:
			T.append(T[j]//36)
			T[j]%=36
	return 0
n=int(input())
nums=[]
for i in range(n):
	nums.append(input())
k=int(input())
Mlen=0
for i in range(len(nums)):
	nums[i]=nums[i].replace(' ','')
	if len(nums[i])>Mlen:Mlen=len(nums[i])
nt=[]
for c in nums:
	nt.append([0 for i in range(len(c))])
for i in range(n):
	for j in range(-1,~len(nums[i]),-1):
		if ord(nums[i][j])>=ord('A') and ord(nums[i][j])<=ord('Z'): nt[i][~j]=ord(nums[i][j])-ord('A')+10
		else:nt[i][~j]=ord(nums[i][j])-ord('0')
if k!=0:
	st=[]
	exn=[]
	for i in nt:
		for j in i:
			if j not in exn:
				exn.append(j)
				tmp=[0 for x in range(Mlen)]
				for m in nt:
					for y in range(len(m)):
						if j==m[y]:
							tmp[y]+=35-j
				st.append(tmp)
	for i in st:
		digit(i)
	if len(st)>1:
		for i in range(Mlen):
			st.sort(key=lambda x:x[i],reverse=True)
		for i in range(len(st)):
			if len(st[i])>1:
				for i in range(-2,0):st.sort(key=lambda x:x[i],reverse=True)
		st.sort(key=lambda x:len(x),reverse=True)
T=[0 for i in range(Mlen+2)]
for i in nt:
	for j in range(len(i)):
		T[j]+=i[j]
if k!=0:
	if len(st)<k:k=len(st)
	for i in range(k):
		for j in range(len(st[i])):
			T[j]+=st[i][j]
for m in range(3):
	digit(T)
for _ in range(len(T)-1):
	if T[-1]==0:T=T[:len(T)-1]
for i in range(len(T)):
	if T[i]>9:T[i]=chr(T[i]+55)
	else:T[i]=chr(T[i]+48)
for i in range(-1,~len(T),-1):
	print(T[i],end='')