from django.urls import path
from django.urls.resolvers import URLPattern
from .views import *

urlpatterns = [
    path("userData",ListUserData.as_view(),name = "userData"),
    path("userLocation",ListUserLocation.as_view(),name = "usersLocation"),
    path("vehicleInfo",ListVehicleInfo.as_view(),name = "vehiclesInfo"),
    path("travelStatus",ListTravelStatus.as_view(),name = "travelStatuses"),
    path("userData/<int:pk>",DetailUserData.as_view(),name = "userDatum"),
    path("userLocation/<int:pk>",DetailUserLocation.as_view(),name = "userLocation"),
    path("vehicleInfo/<int:pk>",DetailVehicleInfo.as_view(),name = "vehicleInfo"),
    path("travelStatus/<int:pk>",DetailTravelStatus.as_view(),name = "travelStatus"),
]