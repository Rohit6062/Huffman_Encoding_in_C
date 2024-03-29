from copy import deepcopy
def config(r,c,n):
    global cf
    for i in range(n):
        cf[i][c]=False
        #print(cf)
    i=0
    while(i<n):
        cf[r][i]=False
        i+=1
    #print(cf)
    i=r 
    j=c
    #print(cf)
    while(i<n and j <n):
            cf[i][j]=False
            i+=1
            j+=1
    i=r
    j=c
    while(i<n and j>=0):
            cf[i][j]=False
            i+=1
            j-=1

def f(x,r,n):
        global cf
        global tmp
        global cftmp
        global ans
        if(x==0):
                t=deepcopy(tmp)
                ans.append(t)
                return 
        for i in range(n):
                if(cf[r][i]==True):
                        cftmp=deepcopy(cf)
                        tmp[r][i]='Q'
                        config(r,i,n)
                        f(x-1,r+1,n)
                        tmp[r][i]='.'
                        if(r==0):
                            cf=deepcopy(tmp1)
                        else:
                            cf=deepcopy(cftmp)
        return


n=input()
tf=[]
cf=[]
tmp=[]
for i in range(n):
    for j in range(n):
        tf.append(True)
    cf.append(tf)
    tf=[]
    for j in range(n):
        tf.append('.')
    tmp.append(tf)
    tf=[]
cftmp=[]
tmp1=deepcopy(cf)
x=deepcopy(n)
ans=[]
f(n,0,n)
for i in ans:
        print(i)
