def move_zeros(array):
    count=0
    for i in range(len(array)):
        if array[i]==0:
            count+=1
            del array[i]
    for j in range(count):
        array.append(0)
            
    return array
print(move_zeros([1,2,4,3,0,3,4,0,4]))