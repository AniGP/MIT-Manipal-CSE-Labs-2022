from django.db.models import fields
from rest_framework import serializers
from .models import Comment,Blog,User


class UserSerializer(serializers.ModelSerializer):
    class Meta:
        fields = (
            'id',
            'username',
            'email',
            'phno',
            'password',
        )
        model = User

class CommentSerializer(serializers.ModelSerializer):
    class Meta:
        fields = (
            'id',
            'user',
            'Blog',
            'comment',
            'date'
        )
        model = Comment

class BlogSerializer(serializers.ModelSerializer):
    class Meta:
        fields = (
            'id',
            'title',
            'desc',
            'date',
            'user',
        )
        model = Blog

