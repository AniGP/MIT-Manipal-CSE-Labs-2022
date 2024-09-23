from django.http import request
from django.shortcuts import render
from .forms import car
# Create your views here.
def home(request):
    form = car()
    return render(request,'prog1.html',{"form":form})

def result(request):
    c = request.GET["manufacturer"]
    p = request.GET["model"]
    return render(request,"prog1_result.html",{"manufacturer":c,"model":p})