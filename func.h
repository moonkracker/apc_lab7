#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int read(HANDLE hFile, char *buffer)
{
    int size;
    DWORD numberOfBytesRead;
    ReadFile(hFile, &size, 1 * sizeof(int), &numberOfBytesRead, NULL);      //read size
    ReadFile(hFile, buffer, size * sizeof(char), &numberOfBytesRead, NULL); //read info
    return size;
}

bool write(HANDLE hFile, char *buffer)
{
    char symb;
    int i = 0;
    DWORD numberOfBytesWrite;
    while (true)
    {
        scanf("%c", &symb);
        if (symb == '\n')
        {
            buffer[i] = '\0';
            WriteFile(hFile, &i, 1 * sizeof(int), &numberOfBytesWrite, NULL);      //write i(size)
            WriteFile(hFile, buffer, i * sizeof(char), &numberOfBytesWrite, NULL); //write info

            if(!strcmp(buffer, "exit\0")) 
                return false;
            else 
                return true;
        }
        else
        {
            buffer[i] = symb;
        }
        i++;
    }
}
