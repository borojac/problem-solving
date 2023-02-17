from datetime import datetime

start = datetime.now()
limit = 10000000

nums_div = {}
def divisors(num):
    cnt = 2
    for i in range(2, int(num**.5)+1):
        if num % i == 0:
            cnt += 2
    if num == int(num**.5)**2:
        cnt -= 1
    return cnt

count = 0
last = divisors(2)
for i in range(3, limit+1):
    if i % 1000000 == 0:
        print(i)
    x = divisors(i)
    if x == last:
        count += 1
    last = x

end = datetime.now()
print(end - start)
print(count)