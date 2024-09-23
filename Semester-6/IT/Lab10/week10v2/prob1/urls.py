from django.urls import path
from .views import *
urlpatterns = [
    path("blogs",ListBlogs.as_view(),name = "ListBlog"),
    path("blogs/<int:pk>",DetailBlog.as_view(),name = "Blog"),
    path("comments",ListComment.as_view(),name="comments"),
    path("users",ListUser.as_view(),name = "users"),
    path("users/<int:pk>",DetailUser.as_view(),name = "User"),
    path("comments/<int:pk>",DetailComment.as_view(),name="comment"),
]