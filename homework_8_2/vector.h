#ifndef _VECTOR_H
	#define _VECTOR_H
	extern void initialize (Course **c, int size);
	extern int initialize_student (Student **s, int size);
	extern void resize (Course **c, int size);
	extern int resize_student (Student **s, int size);
	extern void deallocate (Course *c);
	extern void deallocate_student (Student *s);
#endif
