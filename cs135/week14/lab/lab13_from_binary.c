/*
 *  Name: lab13_from_binary.c
 *  Purpose: Read ages and names from binary file
 *  Author: Matt Davis
 *  Date: 12/4/17
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define FILENAME "people.dat"

 int main(int argc, char *argv[])
 {
   FILE *fp;
   char *name, line[100];
   int ch;
   int age, name_len;
   int *ageptr, *namelenptr;

   ageptr = &age;
   namelenptr = &name_len;


   printf("This program reads and saves ages and names in a binary file.\n");

   if ((fp = fopen(FILENAME, "rb")) == NULL) {
     printf("Error opening file %s in binary read mode.\n", FILENAME);
     fclose(fp);
     exit(EXIT_FAILURE);
   }

   // while (1) {
   //     fread(&age, sizeof(int), 1, fp);
   //     fread(&name_len, sizeof(int), 1, fp);
   //
   //     name = (char *)malloc((sizeof(char) * name_len + 1));
   //     fread(name, sizeof(char), sizeof(name) / sizeof(name[0]) + 1, fp);
   //     name[name_len] = '\0';
   //
   //     if (feof(fp)) {
   //         free(name);
   //         break;
   //     }
   //
   //     printf("Name: %d, %s\n", age, name);
   //     free(name);
   // }

   fread(&age, sizeof(int), 1, fp);
   fread(&name_len, sizeof(int), 1, fp);
   fread(name, sizeof(char), name_len+1, fp);
   printf("Name: %d, %s\n", age, name);

   fread(&age, sizeof(int), 1, fp);
   fread(&name_len, sizeof(int), 1, fp);
   fread(name, sizeof(char), name_len+1, fp);
   printf("Name: %d, %s\n", age, name);

   fclose(fp);

   return 0;
 }
