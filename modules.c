#include <stdio.h>
#include <stdlib.h>
#include"modules.h"
#include"students.h"


 extern database Database[10];

boolean SDB_isFull(void)
{
     int i;
    boolean flag=TRUE;

    for(i=0;i<10;i++)
    {
        if (Database[i].student_data.student_ID==0)
        {
            flag=FALSE;
            return flag;
        }
    }
    return flag;
}
u8 SDB_GetUsedSize(void)
{
    u8 count=0;
    int i;
    for(i=0;i<10;i++)
    {
        if(Database[i].student_data.student_ID!=0)
        {
            count++;
        }
    }
    return count;
}

boolean SDB_AddEntry(u8 id,u8 year, Course* subjects , Course* grades )
{
   if (SDB_isFull())
    {
        return FALSE;
    }
    u8 i,index;

    for(i=0;i<10;i++)
    {
        if(Database[i].student_data.student_ID==0)
        {
            index=i;
            break;
        }
    }

    Database[index].student_data.student_ID = id;
    Database[index].student_data.student_Year= year;
     for(i=0;i<3;i++)
     {

     Database[index].course.CourseID[i]= subjects->CourseID[i];
     Database[index].course.CourseGrade[i]= grades->CourseGrade[i];
     }
    return TRUE;


}

void SDB_DeleteEntry( u8 id)
{

  u8 i;
  for(i=0;i<10;i++)
  {
      if(Database[i].student_data.student_ID==id)
      {
          Database[i].student_data.student_ID=0;
          Database[i].student_data.student_Year=0;

      }
  }
}

boolean SDB_ReadEntry(u8* id, u8* year, u8* subjects, u8* grades)
{
   boolean flag=FALSE;
   u8 i;
   for(i=0;i<10;i++)
  {
      if(Database[i].student_data.student_ID==id)
      {
          year= &Database[i].student_data.student_Year;
          subjects= Database[i].course.CourseID;
          grades= Database[i].course.CourseGrade;

      flag=TRUE;
      return flag;
      }
  }

}
void SDB_GetIDList(u8* counter, u8* List)
{
 int i;
 int index=0;
    for(i=0;i<10;i++)
    {
        if(Database[i].student_data.student_ID!=0)
        {
            List[index]=Database[i].student_data.student_ID;
            index++;
        }
    }
    *counter=SDB_GetUsedSize();
}
boolean SDB_IsIDExist(u8 id)
{
  int i;

  for(i=0;i<10;i++)
  {
      if(Database[i].student_data.student_ID == id)
      {
          return TRUE;
      }
  }
  return FALSE;
}
