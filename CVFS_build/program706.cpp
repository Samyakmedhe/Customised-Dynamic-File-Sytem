//////////////////////////////////////////////////////////////////////
//
//  Headers file
//
/////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
//
//  User Defienne Macros
//
/////////////////////////////////////////////////////////////////////

# define MAXFILESIZE 100

# define MAXINODE 5

# define READ 1
# define WRITE 2
# define EXECUTE 4

# define REGULARFILE 1
# define SPECIALFILE 2 

#define START 0
#define CURRENT 1 
#define END 2

//////////////////////////////////////////////////////////////////////
//
//  structure Name : BootBlock 
//  Description : Holds information to boot the operating Systems
//
/////////////////////////////////////////////////////////////////////


struct BootBlock
{
    char Information[100];
};
//////////////////////////////////////////////////////////////////////
//
//  structure Name : SuperBlock 
//  Description : Holds information to about the File Systems
//
/////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};


//////////////////////////////////////////////////////////////////////
//
//  structure Name : Inode 
//  Description : Holds information to about the File 
//
/////////////////////////////////////////////////////////////////////

typedef struct Inode
{
    char FileName[50];
    int InodeNumber ;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    int LinkCount;
    char * Buffer;
    struct Inode * next;

}INODE , *PINODE , **PPINODE;


//////////////////////////////////////////////////////////////////////
//
//  structure Name : FileTable 
//  Description : Holds information to about the Opened file 
//
/////////////////////////////////////////////////////////////////////
typedef struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Count;
    int Mode;
    PINODE ptrinode;
}FILETABLE, *PFILETABLE;  



//////////////////////////////////////////////////////////////////////
//
//  structure Name : UAREA 
//  Description : Holds information to about the Process  
//
/////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[50];
    PFILETABLE UFDT[MAXINODE];
};


//////////////////////////////////////////////////////////////////////
//
//  Global variable or objects used in the project
//
/////////////////////////////////////////////////////////////////////


BootBlock bootobj;
SuperBlock superobj;
PINODE head = NULL;
UAREA uareaobj;

//////////////////////////////////////////////////////////////////////
//
//  Function Name : InitialiseSuperblock
//  Description : It is Used to intialise the content of super block 
//  Author : Samyak Kailas Medhe
//  Date :  10/08/2025
/////////////////////////////////////////////////////////////////////

void InitialiseSuperblock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;
    cout<<"CVFS :  super Block  Initialise Succefully\n";

};
//////////////////////////////////////////////////////////////////////
//
//  Function Name : CreateDILB
//  Description : It is Used to create Linked list of iNode; 
//  Author : Samyak Kailas Medhe
//  Date :  10/08/2025
/////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    while(i <= MAXINODE)
    {
        newn = new INODE;

        newn->InodeNumber = i;
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->LinkCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if(temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp ->next;

        }
        i++;
    }

    cout<<"CVFS : DILB create Succefully\n";
}



//////////////////////////////////////////////////////////////////////
//
//  Function Name : StartAuxilaryDataInitialisation
//  Description : It is Used to intialise the AuxilaryData 
//  Author : Samyak Kailas Medhe
//  Date :  10/08/2025
/////////////////////////////////////////////////////////////////////

void StartAuxilaryDataInitialisation()
{
    strcpy(bootobj.Information ,"Boot process of Operating System  done");
    
    cout<<bootobj.Information<<"\n";

    InitialiseSuperblock();
    CreateDILB();

    cout<<"CVFS :  Auxilary Data Initialise Succefully\n";

};


//////////////////////////////////////////////////////////////////////
//
//  Entry point function of project (main)
//
/////////////////////////////////////////////////////////////////////


int main()
{
    StartAuxilaryDataInitialisation();
    
    return 0;
}