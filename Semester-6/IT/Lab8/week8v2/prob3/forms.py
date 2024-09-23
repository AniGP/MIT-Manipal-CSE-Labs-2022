from django import forms

class PublisherForm(forms.Form):
    name = forms.CharField(max_length=100)
    street = forms.CharField(max_length=200)
    city = forms.CharField(max_length=50)
    state = forms.CharField(max_length=50)
    country = forms.CharField(max_length=50)
    site = forms.URLField()

class AuthorForm(forms.Form):
    fname = forms.CharField(max_length=100, label="first name")
    lname = forms.CharField(max_length=100, label="last name")
    email = forms.EmailField()

class BookForm(forms.Form):
    title = forms.CharField(max_length=200)
    pdate = forms.DateField(label="publication date")
    pname = forms.CharField(max_length=100,label="Publisher name")
    anames = forms.CharField(max_length=400,label="Enter first names of authors by space seperation")

class BookSearch(forms.Form):
    title = forms.CharField(max_length=200)

class AuthorSearch(forms.Form):
    fname = forms.CharField(max_length=100, label="enter the first name")

class PublisherSearch(forms.Form):
    name = forms.CharField(max_length=100)