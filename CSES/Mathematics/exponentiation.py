# from math import pow
p = 1000000007  
  
# def power(x, y) :
#     if x == 0 and y == 0:
#         return 1
#     res = 1     # Initialize result
 
#     # Update x if it is more
#     # than or equal to p
#     x = x % p 
     
#     if (x == 0) :
#         return 0
 
#     while (y > 0) :
         
#         # If y is odd, multiply
#         # x with result
#         if ((y & 1) == 1) :
#             res = (res * x) % p
 
#         # y must be even now
#         y = y >> 1      # y = y/2
#         x = (x * x) % p
         
#     return res
# Driver code 
n = int(input())
for _ in range(n):
    a,b = map(int, input().split(' '))
    print(pow(a, b,p))