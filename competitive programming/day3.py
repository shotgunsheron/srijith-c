res = 0

x=0
firstpart=""
secondpart=""
thirdpart=""
with open("input.txt") as data:

    for line in data:
        if (x==0):
            firstpart=line
            x=1
        elif (x==1):
            secondpart=line
            x=2
        else:
            thirdpart=line
            x=0
            for i in range(0,len(firstpart)):
                if firstpart[i] in secondpart and firstpart[i] in thirdpart:
                    if (firstpart[i].isupper()):
                        res+=ord(firstpart[i])-ord('A')+1+26
                    else:
                        res+=ord(firstpart[i])-ord('a')+1          
                    break
            firstpart=""
            secondpart=""
            thirdpart=""

print(res)

        
