res=[]
currElf=0

with open("input.txt") as data:
    for line in data:
        if (line=='\n'):
            res.append(currElf)
            currElf=0   
        else:
            currElf+=int(line)

res.sort()

print(str(res[len(res)-1]+res[len(res)-2]+res[len(res)-3]))
