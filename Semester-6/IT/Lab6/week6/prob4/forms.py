from django import forms
from django.forms.widgets import Widget
class Device(forms.Form):
    devices = forms.ChoiceField(choices=[("HP","HP"),("Nokia","Nokia"),("Samsung","Samsung"),("Motorola","Motorola"),("Apple","Apple")],label="Select the Device",widget=forms.RadioSelect())
    quantity = forms.IntegerField(label="Enter the quantity",min_value=1,max_value=6,widget=forms.NumberInput())