x=(input().split())
c=int(x[0])
n=int(x[1])

arr=[]
for i in range(c):
    string=input()
    arr.append(string)

for i in range(0,len(arr)):
    maxDiff=0
    for j in range(i+1,len(arr)):
        diff=0
        for k in arr[i]:
            if arr[i][k]!=arr[j][k]:
                diff+=1
        maxDiff=max(diff,maxDiff)
    print(maxDiff)