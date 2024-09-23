from django.db import models
from django.db.models.aggregates import Count

# Create your models here.

class Publisher(models.Model):
    name = models.CharField(max_length=100)
    street = models.CharField(max_length=200)
    city = models.CharField(max_length=50)
    state = models.CharField(max_length=50)
    country = models.CharField(max_length=50)
    site = models.URLField()
class Au(models.Model):
    fname = models.CharField(max_length=100)
    lname = models.CharField(max_length=100)
    em = models.EmailField()

class Book(models.Model):
    title = models.CharField(max_length=200)
    pdate = models.DateField()
    authors = models.ManyToManyField(Au)
    publisher = models.ForeignKey(Publisher,on_delete=models.CASCADE)
