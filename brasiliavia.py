def index(arrs, value):
    for i, arr in enumerate(arrs):
        if value in arr:
            return i
    return -1

[P, E] = [int(x) for x in input().split(' ')]

Seguros = [[x + 1] for x in range(P)]
Inseguros = []

for e in range(E):
    cmd = input().split(' ')
    if cmd[0] == 'c':
        P1 = int(cmd[1])
        P2 = int(cmd[2])

        iP1 = index(Seguros, P1)
        iP2 = index(Seguros, P2)
        if iP1 != -1 and iP2 != -1:
            if iP1 == iP2: continue
            if iP1 > iP2:
                tmp = iP2
                iP2 = iP1
                iP1 = tmp

                tmp = P2
                P2 = P1
                P1 = tmp

            S_ = Seguros[iP2]
            del Seguros[iP2]
            Seguros[iP1].extend(S_)
        else:
            if iP1 == -1 and iP2 != -1: 
                iP1 = index(Inseguros, P1)
                Inseguros[iP1].extend(Seguros[iP2])
                del Seguros[iP2]
            elif iP2 == -1 and iP1 != -1: 
                iP2 = index(Inseguros, P2)
                Inseguros[iP2].extend(Seguros[iP1])
                del Seguros[iP1]
            else:
                iP1 = index(Inseguros, P1)
                iP2 = index(Inseguros, P2)
                if iP1 == iP2: continue
                Inseguros[iP1].extend(Inseguros[iP2])
                del Inseguros[iP2]
    elif cmd[0] == 'p':
        P = int(cmd[1])
        iP = index(Seguros, P)

        if iP != -1:
            S_ = Seguros[iP]
            del Seguros[iP]
            Inseguros.append(S_)
    elif cmd[0] == 'n': print("%d" % (len(Seguros) + len(Inseguros)))
    elif cmd[0] == 'ns': print("%d" % len(Seguros))
    elif cmd[0] == 'ni': print("%d" % len(Inseguros))
    elif cmd[0] == 'ii': 
        if len(Inseguros) == 0: print("vazio")
        else: 
            vetor = []
            for x in Inseguros:
                vetor.extend(x)
            vetor.sort()
            print(" ".join([" ".join([str(i) for i in vetor])]))