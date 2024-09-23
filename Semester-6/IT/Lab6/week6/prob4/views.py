from django.http import request
from django.shortcuts import render
from .forms import Device
# Create your views here.
def home(request):
    form = Device()
    return render(request,'prog4.html',{"form":form})

def bill(request):
    form = Device(request.GET)
    if form.is_valid():
        devices = form.cleaned_data['devices']
        quantity = int(form.cleaned_data['quantity'])
        if devices == "HP":
            device_cost = 40000
        elif devices == "Nokia":
            device_cost = 15000
        elif devices == "Samsung":
            device_cost = 50000
        elif devices == "Motorola":
            device_cost = 25000
        else:
            device_cost = 90000
        total = device_cost * quantity
        return render(request,'prog4_2.html',{'devices':devices,"cost":device_cost,"quantity":quantity,"total":total})