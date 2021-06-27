import math

n = int(input())
mincnt = math.ceil(n/3) + 1
flag = False
for i in range(0, mincnt):
    if n - 5*i >= 0:
        if (n - 5*i) % 3 == 0:
            if i + (n - 5*i) / 3 < mincnt:
                mincnt = i + (n - 5*i) / 3
                flag = True
if flag:
    print(int(mincnt))
else:
    print(-1)