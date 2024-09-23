from django.urls import path
from .views import *

urlpatterns = [
    path('categories',ListCategory.as_view(),name="categories"),
    path('services',ListService.as_view(),name="services"),
    path('customers',ListCustomer.as_view(),name="customers"),
    path('requests',ListServiceRequested.as_view(),name = "requests"),
    path('categories/<int:pk>',DetailCategory.as_view(),name="category"),
    path('services/<int:pk>',DetailService.as_view(),name="service"),
    path('customers/<int:pk>',DetailCustomer.as_view(),name="customer"),
    path('requests/<int:pk>',DetailServiceRequested.as_view(),name = "request"),
]