n = input()
m = int(n.split()[1])
n = int(n.split()[0])
cards = input().split()
cards = [int(i) for i in cards]
sum = 0
for i in range(n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            tmp = cards[i] + cards[j] + cards[k]
            if m - sum > m - tmp and m - tmp >= 0:
                print(cards[i], cards[j], cards[k])
                sum = tmp
print(sum)