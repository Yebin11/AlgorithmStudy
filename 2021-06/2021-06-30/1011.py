import math

t = int(input())
for _ in range(0, t):
    x = input()
    y = int(x.split()[1])
    x = int(x.split()[0])
    d = y - x
    res = math.floor(math.sqrt(d))
    if d == res*res:
        print(2 * res - 1)
    elif res*res < d and d <= res*res+res:
        print(2 * res)
    elif res*res+res < d and d < (res+1)*(res+1):
        print(2 * res + 1)