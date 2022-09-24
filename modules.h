#ifndef MODULES_H_INCLUDED
#define MODULES_H_INCLUDED
#include"STD_Types.h"
#include"students.h"

boolean SDB_isFull(void);
u8 SDB_GetUsedSize(void);
boolean SDB_AddEntry(u8 id,u8 year, Course* subjects , Course* grades );
void SDB_DeleteEntry( u8 id);
boolean SDB_ReadEntry(u8* id, u8* year, u8* subjects, u8* grades);
void SDB_GetIDList(u8* counter, u8* List);
boolean SDB_IsIDExist(u8 ID);


#endif // MODULES_H_INCLUDED
