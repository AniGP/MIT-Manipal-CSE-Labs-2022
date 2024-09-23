from django.shortcuts import render
from django.http import HttpResponse 
# Create your views here. 

def home(request): 
    return render(request,'home.html',{'name':'NA','cno':'NA','email':'NA','em':'NA','pm':'NA','cm':'NA','tp':'NA'}) 

