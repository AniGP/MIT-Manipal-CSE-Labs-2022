from django.db import models

# Create your models here.
class UserData(models.Model):
    name = models.CharField(max_length=100)
    contact = models.PositiveBigIntegerField()
    def __str__(self):
        return self.name

class UserLocation(models.Model):
    user = models.ForeignKey(UserData,on_delete=models.CASCADE)
    latitude = models.DecimalField(max_digits=7,decimal_places=4)
    longitude = models.DecimalField(max_digits=7,decimal_places=4)
    def __str__(self):
        return '{}_{}_{}'.format(self.latitude,self.longitude,self.user.name)

class VehicleInfo(models.Model):
    driverName = models.CharField(max_length = 100)
    vehicleName = models.CharField(max_length = 100)
    vehicleRegNo = models.CharField(max_length=10)
    contact = models.PositiveBigIntegerField()
    
    def __str__(self):
        return self.driverName+"_"+self.vehicleName+"_"+self.vehicleRegNo


class TravelStatus(models.Model):
    userLocation = models.ForeignKey(UserLocation,on_delete=models.CASCADE)
    vehicle = models.ForeignKey(VehicleInfo,on_delete=models.CASCADE)
    eta = models.TimeField()
    fare = models.PositiveIntegerField()
