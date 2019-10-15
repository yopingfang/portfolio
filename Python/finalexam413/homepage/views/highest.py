from django import forms
from django_mako_plus import view_function
from homepage import models as hmod
from datetime import datetime, timezone
from django.http import HttpResponse

@view_function
def process_request(request, symbol):

    new_date = hmod.CurrencyPrice.objects.filter(symbol=symbol).latest('date')
    return HttpResponse(new_date.date)