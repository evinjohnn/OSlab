#include <stdio.h>
#include <unistd.h>

#define Max_Length 1024

int main()
{
    char sourceFileName[100], destinationFileName[100];
    
    FILE *sourcefile, *destinationfile;
    char line[Max_Length];
    
    printf("Enter src file name with extension: ");
    scanf("%s", sourceFileName);
    
    sourcefile = fopen(sourceFileName, "r");
    if (sourcefile == NULL)
    {   
        printf("Error opening source file\n");
        return 1;
    }

    printf("Enter des file name with extension: ");
    scanf("%s", destinationFileName);
    
    destinationfile = fopen(destinationFileName, "w");
    if (destinationfile == NULL)
    {   
        printf("Error opening destination file\n");
        fclose(sourcefile);
        return 1;
    }

    while(fgets(line, Max_Length, sourcefile)) {
        fputs(line, destinationfile);
    }
    
    printf("File content copied successfully from %s to %s\n", sourceFileName, destinationFileName);
    
    fclose(sourcefile);
    fclose(destinationfile);
    
    return 0;
}