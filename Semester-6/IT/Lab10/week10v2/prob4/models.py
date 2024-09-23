from django.db import models

# Create your models here.
class Category(models.Model):
    name = models.CharField(max_length=100)
    def __str__(self):
        return self.name

class Service(models.Model):
    name = models.CharField(max_length=200)
    provider = models.CharField(max_length=200)
    location = models.CharField(max_length=200)
    category = models.ForeignKey(Category,on_delete=models.CASCADE)
    cost = models.IntegerField()
    def __str__(self):
        return self.name

class Customer(models.Model):
    name = models.CharField(max_length=100)
    contact = models.PositiveBigIntegerField()
    def __str__(self):
        return self.name

class ServiceRequested(models.Model):
    customer = models.ForeignKey(Customer,on_delete=models.CASCADE)
    service = models.ForeignKey(Service,on_delete=models.CASCADE)

