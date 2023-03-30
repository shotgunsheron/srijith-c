# generate random integer values
from random import seed
import math
from random import randint
# seed random number generator


rows=[]
n = 24 # of time blocks

for i in range(0, n):
  rows.append([])
avgTable = []
days=1
workBlocksArr=[]
breakBlocksArr=[]

def inputNewDay(newTable):

  if (len(avgTable)==n):
    avgTable.clear()
  for i in range(0,len(newTable)):
    rows[i].append(newTable[i][0])
    sum=0
    lengthVar=len(rows[i])
    for j in range(len(rows[i])):
      if (rows[i][j]!="NA"):
        sum=sum+int(rows[i][j])
      elif (rows[i][j]=="NA"):
        lengthVar=lengthVar-1
    avg=sum/lengthVar
    #avgTable[i][1]=avg
    avgTable.append([i,avg])
  
  
  #print(avgTable)
def calcWBRatios(avgTable):
  avgTasks=0
  for i in range (0, len(avgTable)):
    avgTasks=avgTasks+int(avgTable[i][0])
  
  avgTasks=avgTasks/(len(avgTable))
  #print(avgTasks)
  tempBreak=1
  tempWork=0
  tempWBlocks=0
  workHit=False
  wBRatios=[]
  first=False

  for i in range (0, len(avgTable)):
    if (avgTable[i][0]!="NA"):
      tasks=avgTable[i][0]
      if (workHit==True and int(tasks)<avgTasks):
        if (first==True):
          wBRatios.append([tempBreak,tempWork,tempWBlocks])
        if (first==False):
          first=True
        tempWork=0
        tempWBlocks=0
        workHit=False

      elif (int(tasks)<int(avgTasks)):
        tempBreak=tempBreak+1
      elif (int(tasks)>=int(avgTasks)):
        tempWork=tempWork+int(tasks)
        workHit=True
        tempWBlocks=tempWBlocks+1
  return wBRatios   
      
    
def calcHighestWBRatio(wBRatios):
  ratios=[]
  for i in range(0,len(wBRatios)):
    ratios.append(wBRatios[i][1]/wBRatios[i][0])
  maxRatio=max(ratios)
  res=[]
  for i in range(0,len(wBRatios)):
    if (wBRatios[i][1]/wBRatios[i][0]==maxRatio):
      res=[wBRatios[i][0],wBRatios[i][1], wBRatios[i][2]]
      break
  return res  






def createSchedule(workBlocks, breakBlocks, fixedEvents, tPB):
  newSchedule=[]
  currWork=workBlocks
  currBreak=breakBlocks
  for i in range(0,n):
    newSchedule.append([])
    if (i not in fixedEvents):
      if (currWork>0):
        newSchedule[i]=[tPB]
        currWork=currWork-1
        if (currWork==0 and currBreak==0):
          currBreak=breakBlocks
      elif (currBreak>0):
        newSchedule[i]=[0]
        currBreak=currBreak-1
        if (currWork==0 and currBreak==0):
          currWork=workBlocks
      
  #print(newSchedule)
  return newSchedule
        

scheduleG=[]
def newDay(newSchedule):

  inputNewDay(newSchedule)
  wBRatios=calcWBRatios(newSchedule)
  #wB=(calcHighestWBRatio(wBRatios))
  
  wB=calcHighestWBRatio(wBRatios)

  wB[0]=math.floor(wB[0])
  wB[1]=math.ceil(wB[1])

  tasks=wB[1] #the number of tasks to be completed after a break block
  tasksPerBlock=math.ceil(tasks/wB[2]) #number of tasks that can be completed in a block
  global workBlocksArr, breakBlocksArr, days
  workBlocksArr.append(wB[2])
  breakBlocksArr.append(wB[0])

  days=days+1
  if (days==6):
    days=5
    workBlocksArr.pop(0)
    breakBlocksArr.pop(0)
    for i in range(0,len(rows)):
      if (len(rows[i])>0):
        rows[i].pop(0)

  workBlocks=0
  breakBlocks=0
  for i in range(0,len(workBlocksArr)):
    workBlocks=workBlocks+workBlocksArr[0]
  for i in range(0,len(breakBlocksArr)):
    breakBlocks=breakBlocks+breakBlocksArr[0]
  workBlocks=math.ceil(workBlocks/days)
  breakBlocks=math.floor(breakBlocks/days)

  if (breakBlocks==0):
    breakBlocks=1
  if (workBlocks==0):
    workBlocks=1

  fixedEvents=[]
  global scheduleG
  
  generatedSchedule=createSchedule(workBlocks,breakBlocks, fixedEvents, tasksPerBlock)
  scheduleG=generatedSchedule
  print("Schedule is: ")
  print(generatedSchedule)
  print("Work blocks: "+str(workBlocks) +"| ","Break blocks: "+str(breakBlocks)+"| ", "Tasks Per Block: "+str(tasksPerBlock)+"| "+'\n')
  #print(wB[0],wB[2])

def generateRandomDays():
  day=[]
  for i in range(0,n):
    day.append([randint(0,4)])
  return day


newDay(generateRandomDays())
newDay(generateRandomDays())
newDay(generateRandomDays())
newDay(generateRandomDays())
newDay(generateRandomDays())

# Convert to a DataFrame and render (needs pandas library).
import pandas as pd
df = pd.DataFrame(data=rows)
pd.DataFrame.from_records(rows)
