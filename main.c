#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char    *first_file;
    int     fd1;

//    fd1 = open("gnlTester/files/multiple_nlx5", O_RDONLY);
    fd1 = open("gnlTester/files/empty", O_RDONLY);
   // fd1 = open("tests/test1.txt", O_RDONLY);
    //fd1 = open("tests/koin", O_RDONLY);
    close(fd1);
    first_file = get_next_line(fd1);
    printf("grim1 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim2 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim3 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim4 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim5 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim6 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim7 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim8 ==%s", first_file);
    first_file = get_next_line(fd1);
    printf("grim9 ==%s", first_file);
    close(fd1);
}