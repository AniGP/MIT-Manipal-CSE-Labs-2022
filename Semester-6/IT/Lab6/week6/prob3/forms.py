from django import forms
from django.forms.widgets import Widget
class Registration(forms.Form):
    username = forms.CharField(label="Username")
    password = forms.CharField(label="Password",widget=forms.PasswordInput())
    email = forms.EmailField(label="E-mail",widget=forms.EmailInput(),required=False)
    contact_no = forms.IntegerField(label="contact",widget=forms.NumberInput(),required=False,min_value=100000000,max_value=9999999999)