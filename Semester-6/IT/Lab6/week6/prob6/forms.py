from django import forms
from django.forms.widgets import Widget
class GPcalc(forms.Form):
    name = forms.CharField(label="Name")
    marks = forms.IntegerField(label="Total Marks",min_value=0,max_value=500,widget=forms.NumberInput())