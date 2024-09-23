from django.db import models
# Create your models here.

class Customer(models.Model):
    name = models.CharField(max_length=100)
    contact = models.PositiveBigIntegerField()

class Staff(models.Model):
    name = models.CharField(max_length=100)
    designation = models.CharField(max_length=200)
    contact = models.PositiveBigIntegerField()

class Restaurant(models.Model):
    name = models.CharField(max_length=200)
    cuisine = models.CharField(max_length=100)
    location = models.CharField(max_length=100)
    contact = models.PositiveBigIntegerField()

