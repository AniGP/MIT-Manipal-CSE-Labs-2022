from django import forms

class ProductForm(forms.Form):
    title = forms.CharField(max_length=100)
    price = forms.IntegerField()
    desc = forms.CharField(widget=forms.Textarea(),label="description")
