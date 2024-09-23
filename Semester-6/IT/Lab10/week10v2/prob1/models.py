from re import T
from django.db import models
# Create your models here.
class User(models.Model):
    username = models.CharField(unique=True,null=False,blank=False,max_length=200)
    email = models.EmailField(null = True,blank=True)
    phno = models.PositiveBigIntegerField(null=True,blank=True)
    password = models.CharField(null=False,blank=False,max_length=200)
    def __str__(self):
        return self.username

class Blog(models.Model):
    title = models.CharField(max_length=200)
    desc = models.TextField()
    date = models.DateField()
    user = models.ForeignKey(User,on_delete=models.CASCADE,default = None)
    def __str__(self):
        return self.title

class Comment(models.Model):
    user = models.ForeignKey(User,on_delete=models.CASCADE,null=True)
    Blog = models.ForeignKey(Blog,on_delete=models.CASCADE)
    comment = models.TextField()
    date = models.DateField()