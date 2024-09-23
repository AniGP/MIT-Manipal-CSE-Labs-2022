from django.urls import path
from . import views
urlpatterns = [
    path('',views.home,name="home"),
    path('entry',views.entry,name="entry"),
    path('index',views.index,name="index")
]