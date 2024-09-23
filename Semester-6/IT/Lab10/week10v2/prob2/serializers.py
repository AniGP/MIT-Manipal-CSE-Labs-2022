from django.db.models import fields
from rest_framework import serializers
from .models import *

class UserDataserializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = UserData

class UserLocationserializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = UserLocation

class VehicleInfoserializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = VehicleInfo

class TravelStatusserializer(serializers.ModelSerializer):
    class Meta:
        fields = '__all__'
        model = TravelStatus

        