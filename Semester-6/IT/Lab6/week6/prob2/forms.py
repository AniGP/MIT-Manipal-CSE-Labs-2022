from django import forms
class Student(forms.Form):
    name = forms.CharField(label="Name")
    roll_no = forms.IntegerField(label="Roll_no:")
    subject = forms.ChoiceField(choices=[("CN","CN"),("EOM","EOM"),("OS","OS"),("SE","SE")],label="Subjects")