from django.urls import path
from . import views
urlpatterns = [
   path('',views.home,name="home"),
   path('metadata',views.meta,name='metaData'),
   path('review',views.review,name='review'),
   path('author',views.author,name='author')
]