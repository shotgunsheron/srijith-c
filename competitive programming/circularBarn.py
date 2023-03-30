t = int(input())

for _ in range(t):
    n = int(input())
    cows = list(map(int, input().split()))
    if cows[0] % 2 == 0:
        print("Farmer Nhoj")
    else:
        print("Farmer John")