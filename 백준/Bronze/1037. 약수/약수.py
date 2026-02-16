t=int(input())
s=list(map(int,sorted(input().split(),key=int)))
if t%2: print(s[t//2]**2)
else: print(s[t//2]*s[t//2-1])