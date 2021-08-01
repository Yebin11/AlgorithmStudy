def hanoi(n, start, to, bypass):
    if n == 1:
        print(start, to)
    else:
        hanoi(n-1, start, bypass, to)
        print(start, to)
        hanoi(n-1, bypass, to, start)

n = int(input())
print((1 << n) - 1)
hanoi(n, 1, 3, 2)