# -*- coding: utf-8 -*-
"""
Created on Thu Aug  8 14:07:14 2019

@author: Balaji
"""
################################
##Generated with a lot of love##
##    with   EasyPython       ##
##Web site: easycoding.tn     ##
################################
import requests #Please install with PIP: pip install requests

import time

req = None


req = ''
for count in range(5):
  req = requests.get('http://192.168.137.40/hi')
  print(req.text)
  time.sleep(1)
