# compilo con make -f ejercicio25.mk


*.pdf : *.dat plots.py
	python plots.py

*.dat : sample.x 
	./sample.x 

sample.x : sample.c
	cc sample.c -o sample.x -lm

clean :
	rm *.dat  *.x *.png *.log *.aux 
