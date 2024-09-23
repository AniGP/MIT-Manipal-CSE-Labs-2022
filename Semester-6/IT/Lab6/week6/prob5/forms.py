from django import forms
class Store(forms.Form):
    items = forms.MultipleChoiceField(label="select item",choices=[("Wheat","Wheat"),("Jaggery","Jaggery"),("Dal","Dal")],widget=forms.CheckboxSelectMultiple())