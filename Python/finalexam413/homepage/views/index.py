from django import forms
from django_mako_plus import view_function
from homepage import models as hmod
from datetime import datetime, timezone


@view_function
def process_request(request):
    prices = []

    # create/check/handle the form
    form = SearchForm()
    #TODO: add logic to check for POST, is_valid, run query
    if request.method == "POST":
        form = SearchForm(request.POST)
        print(form.data)
        if form.is_valid():
            print('valid form')
            prices = hmod.CurrencyPrice.objects.filter(
                symbol=form.cleaned_data.get('symbol'), 
                date__lte=form.cleaned_data.get('end_date'), 
                date__gte=form.cleaned_data.get('start_date')).order_by(form.cleaned_data.get('sort'))

    # set up the context and render
    context = {
        'prices': prices,
        'form': form,
    }
    return request.dmp.render('index.html', context)



class SearchForm(forms.Form):
    '''Searches the CurrencyPrice table'''
    CURRENCY_CHOICES = (
        ( 'BTC', 'Bitcoin' ),
        ( 'ETH', 'Ethereum' ),
        ( 'XRP', 'Ripple' ),
    )
    SORT_CHOICES = (
        ( 'symbol', 'Symbol' ),
        ( 'date', 'Date' ),
        ( 'price', 'Price (lowest first)' ),
        ( '-price', 'Price (highest first)' ),
    )
    
    symbol = forms.ChoiceField(choices=CURRENCY_CHOICES, label='Symbol')
    start_date = forms.DateField(label='Start Date')
    end_date = forms.DateField(label='End Date')
    sort = forms.ChoiceField(choices=SORT_CHOICES, label='Sort')

    def clean(self):
        symbol = self.cleaned_data.get('symbol')
        start_date = self.cleaned_data.get('start_date')
        end_date = self.cleaned_data.get('end_date')
        sort = self.cleaned_data.get('sort')
        
        return self.cleaned_data