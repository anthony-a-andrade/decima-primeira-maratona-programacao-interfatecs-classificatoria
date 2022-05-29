[QL, QC] = [int(x) for x in input().split(' ')]
[L, C] = [int(x) for x in input().split(' ')]

Matriz = [[0 for x in range(QC)] for y in range(QL)]

for l in range(QL): Matriz[l][0] = 3
for c in range(QC): Matriz[-1][c] = 2
for l in range(QL): Matriz[l][-1] = 1
for c in range(QC): Matriz[0][c] = 0

for linha in range(1, L):
    for coluna in range(1, C):
        soma = 0
        soma = soma + Matriz[linha - 1][coluna - 1]
        soma = soma + Matriz[linha - 1][coluna]
        soma = soma + Matriz[linha][coluna - 1]
        Matriz[linha][coluna] = soma
        
print(Matriz[L - 1][C - 1])