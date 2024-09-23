from django.shortcuts import render
from django.http import HttpResponse
import random
#
#  Create your views here.
def home(request):
   return render(request,'home.html')
def meta(request):
   return render(request,'metadata.html')
def review(request):
   return render(request,'review.html')
def author(request):
   return render(request,'author.html')
