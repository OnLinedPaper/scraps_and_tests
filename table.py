from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
import time


driver = webdriver.Chrome()
driver.get('http://www.panamacompra.gob.pa/Inicio/#!/busquedaAvanzada?BusquedaRubros=true&IdRubro=41')

wvar = 0
while(wvar == 0):
  try:
    el = driver.find_element_by_xpath('/html/body/div[1]/div[2]/div/div[2]/div/div/div[2]/div[2]/div[3]/table/tbody/tr[3]')
    wvar = 1
  except NoSuchElementException:
    print('table body empty, waiting...')
    time.sleep(1)

print('table loaded!')
table = driver.find_element_by_xpath('/html/body/div[1]/div[2]/div/div[2]/div/div/div[2]/div[2]/div[3]/table/tbody')
print(table.text)
