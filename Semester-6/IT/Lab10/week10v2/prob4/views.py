from django.shortcuts import render
from rest_framework import generics,filters
from .models import *
from .serializers import *
# Create your views here.

class ListCategory(generics.ListCreateAPIView):
    queryset = Category.objects.all()
    serializer_class = CategorySerializer

class DetailCategory(generics.RetrieveUpdateDestroyAPIView):
    queryset = Category.objects.all()
    serializer_class = CategorySerializer

class ListService(generics.ListCreateAPIView):
    queryset = Service.objects.all()
    serializer_class = ServiceSerializer
    filter_backends = [filters.SearchFilter]
    search_fields = ['name','location']

class DetailService(generics.RetrieveUpdateDestroyAPIView):
    queryset = Service.objects.all()
    serializer_class = ServiceSerializer

class ListCustomer(generics.ListCreateAPIView):
    queryset = Customer.objects.all()
    serializer_class = CustomerSerializer

class DetailCustomer(generics.RetrieveUpdateDestroyAPIView):
    queryset = Customer.objects.all()
    serializer_class = CustomerSerializer

class ListServiceRequested(generics.ListCreateAPIView):
    queryset = ServiceRequested.objects.all()
    serializer_class = ServiceRequestedSerializer

class DetailServiceRequested(generics.RetrieveUpdateDestroyAPIView):
    queryset = ServiceRequested.objects.all()
    serializer_class = ServiceRequestedSerializer

