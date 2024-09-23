from django.http import request
from django.shortcuts import render
from .forms import Registration
# Create your views here.
def home(request):
    form = Registration()
    return render(request,'prog3.html',{"form":form})

def register(request):
    form = Registration(request.POST)
    if form.is_valid():
        username = form.cleaned_data["username"]
        email = form.cleaned_data["email"]
        contact_no = form.cleaned_data["contact_no"]
        return render(request,"prog3_2.html",{"username":username,"email":email,"contact_no":contact_no})
    return render(request,"prog3_2.html",{"username":" ","email":" ","contact_no":" "})