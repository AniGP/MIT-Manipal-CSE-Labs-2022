from django.urls import path
from . import views
urlpatterns = [
    path('',views.home,name="home"),
    path('publisherEntry',views.publisherEntry,name="publisherEntry"),
    path('authorEntry',views.authorEntry,name="authorEntry"),
    path('bookEntry',views.bookEntry,name="bookEntry"),
    path('searchBook',views.searchBook,name="searchBook"),
    path('searchAuthor',views.searchAuthor,name="searchAuthor"),
    path('searchPublisher',views.searchPublisher,name="searchPublisher"),
]