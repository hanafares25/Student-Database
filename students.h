#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include"STD_Types.h"


typedef struct student
{
    u8 student_ID;
    u8 student_Year;

}Student;

typedef struct courses
{
    u8 CourseID[3];
    u8 CourseGrade[3];

}Course;

typedef struct data
{
    Student student_data;
    Course course;


}database;

#endif // STUDENT_H_INCLUDED
