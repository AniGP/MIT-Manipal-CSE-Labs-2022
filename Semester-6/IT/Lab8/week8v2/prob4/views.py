from django.shortcuts import render
from .forms import ProductForm
from .models import Product
# Create your views here.
def home(request):
    return render(request,'prog4.html')

def entry(request):
    form1 = ProductForm(request.POST)
    form = ProductForm()
    if form1.is_valid():
        title = form1.cleaned_data['title']
        price = form1.cleaned_data['price']
        desc = form1.cleaned_data['desc']
        Product.objects.create(title = title,price = price,desc = desc)
    return render(request,'prog4p1.html',{"form":form})

def index(request):
    products = Product.objects.all()
    return render(request,'prog4p2.html',{"products":products})
