n = int(input())
mod = 10**9 + 7

f = (1 + 5 ** .5) / 2
p = (1 - 5 ** .5) / 2

print(int((pow(f,n) - pow(p,n))/(f-p)) % mod)