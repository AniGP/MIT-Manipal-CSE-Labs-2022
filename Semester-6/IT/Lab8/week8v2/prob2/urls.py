from django.urls import path
from . import views
urlpatterns = [
    path('',views.home,name="home"),
    path('portal',views.portal,name="portal"),
    path('search',views.search,name="search")
]