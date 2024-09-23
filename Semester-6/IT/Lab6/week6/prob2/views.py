from django.http import request
from django.shortcuts import render
from .forms import Student
# Create your views here.
def home(request):
    form = Student()
    return render(request,'prog2.html',{"form":form})

def secPage(request):
    form = Student(request.POST)
    if form.is_valid():
        a = request.session
        a['name']=form.cleaned_data['name']
        a['roll_no']=form.cleaned_data["roll_no"]
        a['subject']=form.cleaned_data["subject"]
        return render(request,'prog2_2.html',{"name":a["name"],"roll_no":a["roll_no"],"subject":a["subject"]})
    else:
        return render(request,'prog2_2.html',{"name":" ","roll_no":" ","subject":" "})

def firstPage(request):
    if request.session.has_key('name'):
        del request.session["name"]
    if request.session.has_key('roll_no'):
        del request.session["roll_no"]
    if request.session.has_key('roll_no'):
        del request.session["roll_no"]
    form = Student()
    return render(request,'prog2.html',{"form":form})