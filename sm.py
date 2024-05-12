f=open('test.txt','r')
dic={}
for li in f:
    for x in li:
        if x in dic:
            dic[x]+=1;
        else:
            dic[x]=1
print(dic)
