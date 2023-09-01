def ff(num):
    return sum([int(x) for x in str(num)])


num1 = 1
num2 = 2
f = 1
for i in range(2, 101):
    tmp = num1
    num1 = num2
    if i % 3 == 0:
        f = 2*i//3
    else:
        f = 1
    num2 = f*num1+tmp
    print(f"{num2} {i}= {ff(num2)}")
