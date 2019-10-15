from django import forms
from django_mako_plus import view_function
from homepage import models as hmod
from datetime import datetime, timezone
from django.http import HttpResponse

@view_function
def process_request(request, symbol):

    old_date = hmod.CurrencyPrice.objects.filter(symbol=symbol).earliest('date')
    return HttpResponse(old_date.date)


# query the lowest (oldest) date for a symbol.
#     (hint: google how to do a SELECT MIN query with django)
#     * Create this file in the project.
#     * The symbol is sent as a url parameter, such as:
#         http://localhost:8000/homepage/lowest/ETH
#         http://localhost:8000/homepage/lowest/BTC
#     * Return an HttpResponse with the date string directly from the view
#     * All that is needed here is a process_request() method (no form, no template),
#       but you are welcome to use a template if you want.
#     * Test by typing the url into your browser.
#         (you should get a single date string back)
#     * You can assume the url will be sent correctly - you don't have to worry
#       about errors like bad or missing symbol codes.