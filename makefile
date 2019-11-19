difusion_A.png : difusion.py difusion_A.dat
	python difusion.py

difusion_A.dat : difusion.out
	./difusion.out
	
difusion_B.png : difusion.py difusion_B.dat
	python difusion.py

difusion_B.dat : difusion.out
	./difusion.out
	
difusion_C.png : difusion.py difusion_C.dat
	python difusion.py

difusion_C.dat : difusion.out
	./difusion.out
	
difusion_D.png : difusion.py difusion_D.dat
	python difusion.py

difusion_D.dat : difusion.out
	./difusion.out

difusion.out : difusion.cpp
	c++ difusion.cpp -o difusion.out
	
clear : 
	rm difusion.dat difusion.out difusion.png
	
