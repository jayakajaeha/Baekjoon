#1094

o = 64
ha = 0
f = 0
count = 1
x = int(input())
while(o + f != x):
    o /= 2
    ha = o
    if (o + f >= x):
        ha = 0
    else:
        f += ha
        count += 1

print(count)