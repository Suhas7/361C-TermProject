import random

## n  is the number of elements to be generated
n = 200000
s = ""
for i in range(n):
	s += str (random.randrange(1000000))
	if i != n-1:
		s += ", "

## this is the name of the file that will be used for input
text_file = open("test_200000.txt", "w")
text_file.write(s)
text_file.close()
