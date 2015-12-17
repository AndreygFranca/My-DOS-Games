#ifndef NAVE_H_
#define NAVE_H_
/////////////////////////////////////////////////////////
//PxP_Nave_Struct
//17/12/2015
//ANDREY FRANCA
/////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    COORD Position;
    HANDLE sOutput, sInput;
    INPUT_RECORD InputRecord;
    DWORD Events;

    //Funcoes
    void (*MoveNave)();
    void (*DrawNave)(int);

} _Nave;

void MoveNave ()
{

}
void DrawNave (int draw)
{

}

_Nave NaveConstructor ()
{
    _Nave constructorNave;
    constructorNave.Events = 0;
    constructorNave.MoveNave = &MoveNave;
    constructorNave.DrawNave = &DrawNave;
    return constructorNave;
}

#endif
