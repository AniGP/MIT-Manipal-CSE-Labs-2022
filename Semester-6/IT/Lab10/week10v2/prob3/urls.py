from django.urls import path
from .views import *

urlpatterns = [
    path("customers",ListCustomer.as_view(),name = "customers"),
    path("staff",ListStaff.as_view(),name = "staffs"),
    path("restaurants",ListRestaurant.as_view(),name = "restaurants"),
    path("customers/<int:pk>",DetailCustomer.as_view(),name = "customer"),
    path("staff/<int:pk>",DetailStaff.as_view(),name = "staff"),
    path("restaurants/<int:pk>",DetailRestaurant.as_view(),name = "restaurant"),
]