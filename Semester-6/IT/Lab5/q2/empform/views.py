from django.shortcuts import render
from django.http import HttpResponse 

# Create your views here. 

def home(request): 
    return render(request,'home.html') 
def select(request): 
    n1 = request.GET['doj'] 
    n2 = int(n1[:4]) 
    
    if 2021-n2>5: 
        n1 = "CONGRATULATIONS YOU ARE ELGIBLE FOR PROMOTION" 
    else: 
        n1 = "SORRY YOU ARE NOT ELGIBLE FOR THE PROMOTION" 

    return render(request,'result.html',{"selection":n1}) 

