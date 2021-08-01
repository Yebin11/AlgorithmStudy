import math
t = int(input())
for i in range(0, t):
    line = input().split()
    h = int(line[0])
    w = int(line[1])
    n = int(line[2])
    res = ""
    if n % h == 0:
        res += str(h)
    else:
        res += str(n % h)
    if math.ceil(n / h) < 10:
        res += '0'
    res += str(math.ceil(n / h))
    print(res)