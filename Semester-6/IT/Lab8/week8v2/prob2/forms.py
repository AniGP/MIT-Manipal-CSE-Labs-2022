from django import forms

class Employee(forms.Form):
    name = forms.CharField(max_length=100)
    company = forms.CharField(max_length=100)
    salary = forms.IntegerField()
    street = forms.CharField(max_length=200)
    city = forms.CharField(max_length=50)

class Company(forms.Form):
    company = forms.CharField(max_length=100)