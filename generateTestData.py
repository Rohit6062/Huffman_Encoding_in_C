li=[]
for i in range(30):
    li.append(0)

li[0]=1
li[1]=1
out=2
for i in range(2,26):
    li[i]=out
    out+=out
f= open('Data.txt','w')
print("Generating...")
for i in range(26):
    for j in range(li[i]):
        f.write(chr(97+i))

