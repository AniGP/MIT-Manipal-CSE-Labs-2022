from django.db.models import fields
from rest_framework import serializers
from .models import *

class CustomerSerializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = Customer

class StaffSerializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = Staff

class RestaurantSerializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = Restaurant