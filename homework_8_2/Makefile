all: rsvp

rsvp.o: rsvp.c rsvp.h
	gcc -Wall -g -c -o rsvp.o rsvp.c 

student.o: student.c student.h rsvp.h
	gcc -Wall -g -c -o student.o student.c

course.o: course.c course.h rsvp.h
	gcc -Wall -g -c -o course.o course.c 

vector.o: vector.c vector.h rsvp.h
	gcc -Wall -g -c -o vector.o vector.c

rsvp.out: rsvp.o course.o student.o vector.o
	gcc rsvp.o course.o student.o vector.o -o rsvp.out
	
clean:
	rm -rf *.o rsvp.out
