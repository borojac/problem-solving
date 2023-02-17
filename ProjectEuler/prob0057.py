cnt = 0
limit = 1000

for i in range(2, limit + 1):
    sa = 1
    sb = 2
    for j in range(i):
        sa, sb = sb, 2*sb+sa
    
    a = sa + sb
    b = sb

    if (len(str(a)) > len(str(b))):
        cnt += 1

print (cnt)