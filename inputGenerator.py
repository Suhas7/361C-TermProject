import random

n = 500000
s = ""
for i in range(n):
	s += str (random.randrange(1000000))
	if i != n-1:
		s += ", "

text_file = open("test.txt", "w")
text_file.write(s)
text_file.close()
