import re
file = open('example.html')
line= file.readline()
while line:
  line = file.readline()
  if bool( re.search(r'[A-Za-z0-9]+\w+@\w+\.[a-z]', line)):
    email=line.split()
    print(*email)
file.close()
