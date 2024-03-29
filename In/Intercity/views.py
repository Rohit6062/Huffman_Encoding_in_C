from django.http import HttpResponse
from django.shortcuts import render,redirect
import mysql.connector as db
from django.contrib import messages

curr_user=None
data={'isUser':0,'loc':['pune','mumbai','japan','wano','kuri','goa']}
cursor=None
def root():
    global cursor
    mydb=db.connect(host='localhost',user='admin',password='6062')
    cursor=mydb.cursor()
def index(request):
    global curr_user
    uname = request.POST.get('uname',None)
    upass=request.POST.get('pass',None)
    print(uname ,upass)
    if(uname!=None and upass!=None):
        try:
            mydb = db.connect(host='localhost',user=uname,password=upass)
            cursor=mydb.cursor()
            curr_user=uname
            data['isUser']=1  
            messages.success(request,f"Your are Loged in as {curr_user}")  
            return render(request,'index.html',data)
        except:
            messages.error(request,'Wrong credentials!')
            return redirect(login)        
    else:
        messages.error(request,'you need to log in!')
        return render(request,'index.html',data)


def login(request):
    global cursor
    name=request.POST.get('name',None)
    uname=request.POST.get('uname',None)
    upass=request.POST.get('pass',None)
    if(name and uname and upass):
        mydb=db.connect(host='localhost',user='admin',password='6062')
        cursor=mydb.cursor()
        try:
            sql=f"create user %s@'localhost' identified by %s";
            val = (uname,upass)
            print(sql,val)
            cursor.execute(sql,val)
            messages.success(request,f'You are successfully Registered !, Please Log in to proceed ')
            return render(request,'login.html')
        except db.Error as err:
            if(err.errno==1396):
                messages.error(request,'user name already used, please try defferent User Name! ')
            else:
                messages.error(request,err)
            return redirect(signup)
    if(name==None and uname==None and upass==None):
        return render(request,'login.html')
    else:
        messages.error(request,'All fields are compalsary')
        return redirect(signup)

def signup(request): 
    return render(request,'signup.html')
def logout(request):
    curr_user=None
    data['isUser']=0
    global cursor
    cursor = None
    return index(request)

def home(request):
    return render(request,'homepage.html',data)
