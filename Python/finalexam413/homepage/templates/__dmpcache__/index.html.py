# -*- coding:utf-8 -*-
from mako import runtime, filters, cache
UNDEFINED = runtime.UNDEFINED
STOP_RENDERING = runtime.STOP_RENDERING
__M_dict_builtin = dict
__M_locals_builtin = locals
_magic_number = 10
_modified_time = 1571081074.658554
_enable_loop = True
_template_filename = 'C:/Users/Yoping/413Projects/finalexam/homepage/templates/index.html'
_template_uri = 'index.html'
_source_encoding = 'utf-8'
import django_mako_plus
import django.utils.html
_exports = ['title', 'content']


def _mako_get_namespace(context, name):
    try:
        return context.namespaces[(__name__, name)]
    except KeyError:
        _mako_generate_namespaces(context)
        return context.namespaces[(__name__, name)]
def _mako_generate_namespaces(context):
    pass
def _mako_inherit(template, context):
    _mako_generate_namespaces(context)
    return runtime._inherit_from(context, 'base.htm', _template_uri)
def render_body(context,**pageargs):
    __M_caller = context.caller_stack._push_frame()
    try:
        __M_locals = __M_dict_builtin(pageargs=pageargs)
        def title():
            return render_title(context._locals(__M_locals))
        def content():
            return render_content(context._locals(__M_locals))
        prices = context.get('prices', UNDEFINED)
        self = context.get('self', UNDEFINED)
        __M_writer = context.writer()
        __M_writer('\n')
        if 'parent' not in context._data or not hasattr(context._data['parent'], 'title'):
            context['self'].title(**pageargs)
        

        __M_writer('\n')
        if 'parent' not in context._data or not hasattr(context._data['parent'], 'content'):
            context['self'].content(**pageargs)
        

        __M_writer('\n')
        return ''
    finally:
        context.caller_stack._pop_frame()


def render_title(context,**pageargs):
    __M_caller = context.caller_stack._push_frame()
    try:
        def title():
            return render_title(context)
        __M_writer = context.writer()
        __M_writer('Crypto Search')
        return ''
    finally:
        context.caller_stack._pop_frame()


def render_content(context,**pageargs):
    __M_caller = context.caller_stack._push_frame()
    try:
        def content():
            return render_content(context)
        prices = context.get('prices', UNDEFINED)
        self = context.get('self', UNDEFINED)
        __M_writer = context.writer()
        __M_writer('\n\n    <div id="form_container">\n        \n        <form method="POST">\n            <label for="symbol">Symbol:</label>\n            <select id="symbol-list" name="symbol">\n                <option value="BTC">Bitcoin</option>\n                <option value="ETH">Ethereum</option>\n                <option value="XRP">Ripple</option>\n            </select><br />\n            <label for="start-date">Start Date</label><input type="text" id="start-date" name="start_date"/><br />\n            <label for="end-date">End Date</label><input type="text" id="end-date" name="end_date"/><br />\n            <label for="sort">Sort:</label>\n            <select id="sort-list" name="sort">\n                <option value="symbol">Symbol</option>\n                <option value="date">Date</option>\n                <option value="price">Price (lowest first)</option>\n                <option value="-price">Price (highest first)</option>\n            </select><br /><br />\n            <input type="submit" />\n        </form>\n\n        <div class="text-right">\n            <button class="btn btn-default" id="start_date_button">Set Starting Date</button>\n            <button class="btn btn-default" id="end_date_button">Set Ending Date</button>\n        </div>\n    </div>\n\n    <div id="results_container">\n        <table>\n            <tr>\n                <th>Symbol</th>\n                <th>Date</th>\n                <th>Price</th>\n            </tr>\n            \n')
        for p in prices:
            __M_writer('            <tr>\n                <td>')
            __M_writer(django_mako_plus.ExpressionPostProcessor(self)(p.symbol))
            __M_writer('</td>\n                <td>')
            __M_writer(django_mako_plus.ExpressionPostProcessor(self)(p.date))
            __M_writer('</td>\n                <td>')
            __M_writer(django_mako_plus.ExpressionPostProcessor(self)(p.price))
            __M_writer('</td>\n            </tr>\n')
        __M_writer('            \n        </table>\n    </div>\n\n')
        return ''
    finally:
        context.caller_stack._pop_frame()


"""
__M_BEGIN_METADATA
{"filename": "C:/Users/Yoping/413Projects/finalexam/homepage/templates/index.html", "uri": "index.html", "source_encoding": "utf-8", "line_map": {"29": 0, "40": 1, "45": 2, "50": 51, "56": 2, "62": 2, "68": 3, "76": 3, "77": 40, "78": 41, "79": 42, "80": 42, "81": 43, "82": 43, "83": 44, "84": 44, "85": 47, "91": 85}}
__M_END_METADATA
"""
