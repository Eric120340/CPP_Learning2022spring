#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[100];
    char *description;
    strcpy(name, "Zara");
    
    description = (char *)malloc(30 *sizeof(char)); //申请内存
    if (description == NULL)
    {
        fprintf(stderr, "Error- unable to allocate required memory.\n");
    }
    else
    {
        strcpy(description, "Zara is a DPS student.");
    }

    //Store a bigger description 
    description = (char *)realloc(description, 100 * sizeof(char));
    if (description == NULL)
    {
        fprintf(stderr, "Error- unable to allocate required memory.\n");
    }
    else
    {
        strcpy(description, "She is in class 10.");
    }
    
    printf("Name = %s\n",name);
    printf("Description: %s\n", description);
    free(description);  //释放内存 
    return 0;

}