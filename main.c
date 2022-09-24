#include <stdio.h>
#include <stdlib.h>
#include"students.h"
#include"modules.h"

database Database[10];

int main()
{
   //  printf("%d \n", Database[0].course.CourseGrade[1]);
    u8 arr_list[10]={0};
    u8* counter;
    int i;
    Course c1;
    c1.CourseID[0]=1;
    c1.CourseID[1]=2;
    c1.CourseID[2]=3;
    c1.CourseGrade[0]= 80;
    c1.CourseGrade[1]= 80;
    c1.CourseGrade[2]= 80;



    SDB_AddEntry(20,5,&c1,&c1);

    printf("Student 1 ID: %d\n", Database[0].student_data.student_ID);
    printf("Student 1 Year: %d\n", Database[0].student_data.student_Year);
    for(i=0;i<3;i++)
    {
        printf("Course %d ID: %d \n",i+1, Database[0].course.CourseID[i]);
        printf("Course %d Grade: %d \n",i+1, Database[0].course.CourseGrade[i]);
    }


    SDB_GetIDList(counter,arr_list);
    printf("ID  %d  count %d\n",arr_list[0], *counter );
    return 0;
}
