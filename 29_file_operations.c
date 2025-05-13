/**
 * @author: Mitul
 * @description: File Operations
 */
/**
- A file is a container in computer storage devices used for storing data.
- When a program is terminated, the entire data is lost. Storing in a file will
preserve your data even if the program terminates.
- There are two types of files: Text files (.txt) and Binary Files (.bin).
- There are four basic operations that can be performed on a file:
    -> Creating a new file
    -> Opening an existing file
    -> Closing a file
    -> Reading from and writing information to a file
- A pointer of type file is to be declared when working with the files.
            FILE *fptr;
- Opening a file is performed using the fopen() function defined in the stdio.h
header file.
            ptr = fopen("fileopen","mode");
- Opening modes in Standard I/O
    * r  : Open for reading
    * rb : Open for reading in binary mode
    * w  : Open for writing
    * wb : Open for writing in binary mode
    * a  : Open for append
    * ab : Open for append in binary mode
    * r+ : Open for both reading and writing
    * rb+: Open for both reading and writing in binary mode
    * w+ : Open for both reading and writing
    * wb+: Open for both reading and writing in binary mode
    * a+ : Open for both reading and appending
    * ab+: Open for both reading and appending in binary mode
- The file (both text and binary) should be closed after reading/writing.
Closing a file is performed using the fclose() function.
            fclose(fptr);
- For reading and writing to a text file, the functions fprintf() and fscanf()
are used. They are just the file versions of printf() and scanf(). The only
difference is that fprintf() and fscanf() expects a pointer to the structure
FILE.
- Functions fread() and fwrite() are used for reading from and writing to a file
on the disk respectively in case of binary files.
            fwrite(addressData, sizeData, numbersData, pointerToFile);
            fread(addressData, sizeData, numbersData, pointerToFile);
- The fseek() seeks the cursor to the given record in the file.
            fseek(FILE * stream, long int offset, int whence);
The first parameter stream is the pointer to the file. The second parameter is
the position of the record to be found, and the third parameter specifies the
location where the offset starts.
    * SEEK_SET: Starts the offset from the beginning of the file.
    * SEEK_END:	Starts the offset from the end of the file.
    * SEEK_CUR: Starts the offset from the current location of the cursor in the
                file.

*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct threeNum
{
    int n1, n2, n3;
};

int main(int argc, char const *argv[])
{

    int num;
    FILE *fptr;

    fptr = fopen("./program.txt", "w");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    fclose(fptr);

    if ((fptr = fopen("./program.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    fscanf(fptr, "%d", &num);

    printf("Value of n= %d\n", num);
    fclose(fptr);

    int n;
    struct threeNum _threeNum, _threeNum2;

    if ((fptr = fopen("./program.bin", "wb")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    for (n = 1; n < 5; ++n)
    {
        _threeNum.n1 = n;
        _threeNum.n2 = 5 * n;
        _threeNum.n3 = 5 * n + 1;
        fwrite(&_threeNum, sizeof(struct threeNum), 1, fptr);
    }
    fclose(fptr);

    if ((fptr = fopen("./program.bin", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    for (n = 1; n < 5; ++n)
    {
        fread(&_threeNum2, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", _threeNum2.n1, _threeNum2.n2,
               _threeNum2.n3);
    }
    fclose(fptr);

    if ((fptr = fopen("./program.bin", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    // Moves the cursor to the end of the file
    fseek(fptr, -sizeof(struct threeNum), SEEK_END);

    for (n = 1; n < 5; ++n)
    {
        fread(&_threeNum2, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", _threeNum2.n1, _threeNum2.n2,
               _threeNum2.n3);
        fseek(fptr, -2 * sizeof(struct threeNum), SEEK_CUR);
    }

    fclose(fptr);

    /* code */
    return 0;
}
