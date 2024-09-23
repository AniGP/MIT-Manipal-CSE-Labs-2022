from django import forms
from django.forms.widgets import Widget
class car(forms.Form):
    manufacturer = forms.ChoiceField(choices=[("Hyundai","Hyundai"),("Mercedes-Benz","Mercedes-Benz"),("McLaren","McLaren"),("BMW","BMW")],label="Manufacturer")
    model = forms.CharField(label="Model")