n, k = map(int, input().split(" "))

def bitsoncount(x): 
    b=0
    while(x > 0):
        x &= x - 1   
        b+=1
    return b

l = []
for i in range(n):
    l.append(int(input(), 2))

minn = 31
for i in range(n - 1):
    for j in range(i + 1,n):
        tmp = bitsoncount(l[i] ^ l[j])
        if minn > tmp:
            minn = tmp

print (minn)