from django.db import models
class Category(models.Model):
    name = models.CharField(max_length=100,primary_key=True)
    numberOfVisits = models.IntegerField()
    numberOfLikes = models.IntegerField()
# Create your models here
class Page(models.Model):
    category = models.CharField(max_length=100)
    title = models.CharField(max_length=100)
    url = models.URLField(primary_key=True)
    view = models.IntegerField()


