#!/usr/bin/env python
import cgi
import cgitb
import os
import uuid
import pickle
cgitb.enable()
__cg_input = cgi.FieldStorage()
__session = os.environ["QUERY_STRING"].split("&")[0]
__vars = {}
__sids = {}
__next_logics = {}

class Item():
	name = ""
	available = False
	price = 0

	def __init__(self, dict):
		for k, v in dict.items():
			setattr(self, k, v)

class A():
	name = ""
	a = ""
	b = ""
	a = False
	price = 0

	def __init__(self, dict):
		for k, v in dict.items():
			setattr(self, k, v)

def a(__varDict):
	return """<html></html>""".format(**(__varDict))
def b(__varDict):
	return """<html>{gap}</html>""".format(**(__varDict))
