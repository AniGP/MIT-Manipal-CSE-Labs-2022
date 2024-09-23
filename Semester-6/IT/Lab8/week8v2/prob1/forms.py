from prob1.models import Category
from django import forms
class CategoryForm(forms.Form):
    name = forms.CharField(max_length=100)
    numberOfVisits = forms.IntegerField()
    numberOfLikes = forms.IntegerField()

class PageForm(forms.Form):
    category = forms.CharField(max_length=100)
    title = forms.CharField(max_length=100)
    url = forms.URLField()
    view = forms.IntegerField()

