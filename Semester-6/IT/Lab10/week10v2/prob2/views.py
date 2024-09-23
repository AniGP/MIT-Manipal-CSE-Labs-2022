from django.shortcuts import render
from .serializers import *
from .models import *
from rest_framework import generics
# Create your views here.
class ListUserData(generics.ListCreateAPIView):
    queryset = UserData.objects.all()
    serializer_class = UserDataserializer

class DetailUserData(generics.RetrieveUpdateDestroyAPIView):
    queryset = UserData.objects.all()
    serializer_class = UserDataserializer

class ListUserLocation(generics.ListCreateAPIView):
    queryset = UserLocation.objects.all()
    serializer_class = UserLocationserializer

class DetailUserLocation(generics.RetrieveUpdateDestroyAPIView):
    queryset = UserLocationserializer
    serializer_class = UserLocationserializer
    
class ListVehicleInfo(generics.ListCreateAPIView):
    queryset = VehicleInfo.objects.all()
    serializer_class = VehicleInfoserializer

class DetailVehicleInfo(generics.RetrieveUpdateDestroyAPIView):
    queryset = VehicleInfo.objects.all()
    serializer_class = VehicleInfoserializer

class ListTravelStatus(generics.ListCreateAPIView):
    queryset = TravelStatus.objects.all()
    serializer_class = TravelStatusserializer

class DetailTravelStatus(generics.RetrieveUpdateDestroyAPIView):
    queryset = TravelStatus.objects.all()
    serializer_class = TravelStatusserializer
