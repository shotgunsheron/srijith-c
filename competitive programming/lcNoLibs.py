
t=int(input())
for k in range(t):
    tCS=str(input())
    xO=""
    pO=""
    #for i in range(len(tCS)):
     #   if tCS[i]==" ":
      #      for j in range(0,i):
       #         xO+=tCS[j]
        #    for k in range(i+1, len(tCS)):
         #       pO+=tCS[k]
         #ignorethis
          #  break
    x = tCS.split(' ')
    xO=x[0]
    pO=x[1]



    xO=int(xO)
    pO=int(pO)

    tCST=str(input())
    xT=""
    pT=""
    #for x in range(len(tCST)-1):
     #   if tCST[x]==" ":
      #      for j in range(0,x):
       #         xT+=tCST[j]
        #    for k in range(x+1, len(tCST)):
         #       pT+=tCST[k]
          #  break
    y = tCST.split(' ')
    xT=y[0]
    pT=y[1]

    xO=int(xO)
    pO=int(pO)

    xT=int(xT)
    pT=int(pT)
    nO=xO*10**pO
    nT=xT*10**pT

    if nO==nT:
        print('=')
    if nO<nT:
        print('<')
    if nO>nT:
        print('>')
