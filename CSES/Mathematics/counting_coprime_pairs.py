from math import gcd


n = int(input())
l = list(map(int, input().split(' ')))

summ = 0
for i in range(n-1):
    val = l[i]
    for j in range(i+1,n):
        if gcd(val, l[j]) == 1:
            summ += 1

print(summ)