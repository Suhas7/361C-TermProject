import random

n = 200000
s = ""
for i in range(n):
	s += str (random.randrange(1000000))
	if i != n-1:
		s += ", "

text_file = open("test_200000.txt", "w")
text_file.write(s)
text_file.close()
