N = int(input())
I = 0
II = 0
III = 0
IV = 0
for n in range(N):
    x, y = [int(x) for x in input().split(' ')]

    if x > 0 and y > 0: I = I + 1
    if x > 0 and y < 0: II = II + 1
    if x < 0 and y < 0: III = III + 1
    if x < 0 and y > 0: IV = IV + 1

print("I = %d" % I)
print("II = %d" % II)
print("III = %d" % III)
print("IV = %d" % IV)