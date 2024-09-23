from django.db.models import fields
from rest_framework import serializers
from .models import *

class CategorySerializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = Category

class ServiceSerializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = Service

class CustomerSerializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = Customer

class ServiceRequestedSerializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = ServiceRequested