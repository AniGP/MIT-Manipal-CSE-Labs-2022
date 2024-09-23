from django.http import request
from django.shortcuts import render
from .forms import GPcalc
# Create your views here.
def home(request):
    form = GPcalc()
    return render(request,'prog6.html',{"form":form})
def calc(request):
    form = GPcalc(request.GET)
    if form.is_valid():
        a = request.session
        a['name'] = form.cleaned_data['name']
        b = float(form.cleaned_data['marks'])
        a['gpa'] = b/50
        return render(request,'prog6_2.html',{"name":a['name'],"gpa":a["gpa"]})