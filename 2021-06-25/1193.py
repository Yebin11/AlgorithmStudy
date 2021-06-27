n = int(input())
range = 1
cnt = 1
while range < n:
    cnt += 1
    range += cnt
tmp = range - n
if cnt%2 == 0:
    print(f"{cnt - tmp}/{tmp + 1}")
else:
    print(f"{tmp + 1}/{cnt - tmp}")