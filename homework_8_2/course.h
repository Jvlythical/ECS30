#ifndef _COURSE_H
	#define _COURSE_H

	typedef struct {
		int CRN;
		char subj[4];
		char crse[6];
	} Course;

	typedef struct {
		char *first_name;
		char *last_name;
		char SID[12];
		int CRNS[5];
		int num_classes;
	} Student;

	extern int read_courses (char *path, Course **c);
	extern void find_CRN (Course *c, Student *s, int course_size, int size);
	extern void find_subject (Course *c, int size);
	extern void add_course (Student **s, Course *c, int stu_size, int course_size);
	extern void remove_course (Student **s, int stu_size);
#endif

