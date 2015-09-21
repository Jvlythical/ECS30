rsvp.o: rsvp.c course.c vector.c
	gcc -Wall -g rsvp.c

course.o: course.c
	gcc -Wall -g course.c 

vector.o: vector.c
	gcc -Wall -g vector.c

rsvp: rsvp.o course.o vector.o
	gcc rsvp.o course.o vector.o -o rsvp
	
