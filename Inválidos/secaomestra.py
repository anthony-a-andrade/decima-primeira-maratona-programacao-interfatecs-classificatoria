def integral(x, coeficientes):
    result = 0
    qnt = len(coeficientes)
    for i, coeficiente in enumerate(coeficientes):
        result = result + (coeficiente * (x ** (qnt - 1 - i)))
    return result

def calcXs(g, espc_x, coeficientes):
    result = []
    for i in range(g):
        x_i = espc_x * i
        result.append(integral(x_i, coeficientes))
    return result

def f_x(Xs):
    result = 0
    qnt = len(Xs)
    for i, x in enumerate(Xs):
        if i == 0 or i + 1 == qnt: result = result + x
        else:
            op = 2
            if i % 2 != 0: op = 4
            result = result + (x * op)
    return result

[B, H] = [float(x) for x in input().split(' ')]
G = int(input())
Coeficientes = [float(x) for x in input().split(' ')]
QntPontos = int(input())

ESPC_X = B / (2 * (QntPontos - 1))
Xs = calcXs(QntPontos, ESPC_X, Coeficientes)
A_Cinza = 2 * (ESPC_X/ 3) * f_x(Xs)
AMS = (B * H) - A_Cinza
CM = AMS / (B * H)
print("%.4f" % CM)