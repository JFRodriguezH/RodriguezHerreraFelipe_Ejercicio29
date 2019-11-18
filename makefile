difusion.png : difusion.py difusion.dat
	python difusion.py

difusion.dat : difusion.out
	./difusion.out

difusion.out : difusion.cpp
	c++ difusion.cpp -o difusion.out
	
clear : 
	rm difusion.dat difusion.out difusion.png
	
