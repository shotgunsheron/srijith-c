#python3 -m cProfile -s tottime longcomparison.py - performance check command
t=int(input())
for o in range(t):
    tCS=str(input())
    xO=""
    pO=""

    x = tCS.split(' ')
    xO=x[0]
    pO=x[1]

    xO=int(xO)
    pO=int(pO)
    #----------
    tCST=str(input())
    xT=""
    pT=""

    y = tCST.split(' ')
    xT=y[0]
    pT=y[1]

    xT=int(xT)
    pT=int(pT)
    #--------

    nO=xO*10**pO
    nT=xT*10**pT

    if nO==nT:
        print('=')
    if nO<nT:
        print('<')
    if nO>nT:
        print('>')
