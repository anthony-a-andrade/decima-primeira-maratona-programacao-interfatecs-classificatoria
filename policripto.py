entrada = input()
nums_ = [x for x in input()]
nums = []
sinal = ""

for num in nums_:
    if num == "-" or num == "+": sinal = num
    else:
        valor = int(num)
        if sinal == "-": valor = valor * -1
        nums.append(valor)

alfa = "abcdefghijklmnopqrstuvwxyz"    
i = 0
for letra in entrada:
    if letra == 'w': 
        print(' ', end='')
        continue
    posicao = alfa.index(letra)
    posicao = posicao + nums[i]
    if (posicao > 25):
        posicao = posicao - 26
    print(alfa[posicao], end='')
    i = i + 1
print()