N = int(input())

entrada = [int(x) for x in [input() for i in range(N)]]
ok = True
maior = max(entrada)

for i in range(1, maior):
    if i not in entrada:
        ok = False
        print(i)

if (ok): print("bom trabalho")