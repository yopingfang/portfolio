from django.db import models

# Create your models here.

class CurrencyPrice(models.Model):
    symbol = models.TextField()
    date = models.DateField()
    price = models.DecimalField(max_digits=7, decimal_places=2)
