
res=0
with open("input2.txt") as data:
    for line in data:
        a=line[0]
        b=line[2]
        if (b=='X'):
            if (a=='A'):
                b='Z'
            elif (a=='B'):
                b='X'
            else:
                b='Y'
        elif (b=='Y'):
            if (a=='A'):
                b='X'
            elif (a=='B'):
                b='Y'
            else:
                b='Z'
        else:
            if (a=='A'):
                b='Y'
            elif (a=='B'):
                b='Z'
            else:
                b='X'

        if (b=='X'):
            res+=1
        elif (b=='Y'):
            res+=2
        else:
            res+=3
        if b=='X' and a=='C' or b=='Y' and a=='A' or b=='Z' and a=='B':
            res+=6
        if a=='A' and b=='X' or a=='B' and b=='Y' or a=='C' and b=='Z':
            res+=3
print(res)
            