from django.urls import path
from . import views
urlpatterns = [
    path('',views.home,name="home"),
    path('sec_page',views.secPage,name="secPage"),
    path('first_page',views.firstPage,name="firstPage")
]