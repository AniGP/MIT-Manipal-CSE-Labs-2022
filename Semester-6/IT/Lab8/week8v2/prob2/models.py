from django.db import models
from django.db.models.fields.related import ForeignKey

# Create your models here.
class Works(models.Model):
    name = models.CharField(max_length=100)
    company = models.CharField(max_length=100)
    salary = models.IntegerField()

class Lives(models.Model):
    name = models.CharField(max_length=100)
    street = models.CharField(max_length=200)
    city = models.CharField(max_length=50)