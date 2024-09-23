from re import I
from django.http import request
from django.shortcuts import render
from .forms import Store
from .models import item
# Create your views here.
def home(request):
    form = Store()
    return render(request,'prog5.html',{"form":form})

def firstPage(request):
    form = Store()
    form1 = Store(request.GET)
    if form1.is_valid():
        items = form1.cleaned_data['items']
        a = []
        for i in items:
            it = item()
            if i=="Wheat":
                it.name="Wheat"
                it.cost = 40
            if i=="Jaggery":
                it.name="Jaggery"
                it.cost=60
            if i=="Dal":
                it.name = i
                it.cost = 80
            a.append(it)
        return render(request,'prog5.html',{'form':form1,'items':a})
    return render(request,'prog5.html',{"form":form})
