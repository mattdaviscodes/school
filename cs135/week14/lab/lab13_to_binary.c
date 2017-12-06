/*
 *  Name: lab13_to_binary.c
 *  Purpose: Read and save ages and names to binary file
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
   char name[100], input[100];
   int age, name_len;


   printf("This program reads and saves ages and names in a binary file.\n");

   if ((fp = fopen(FILENAME, "wb")) == NULL) {
     printf("Error opening file %s in binary write mode.\n", FILENAME);
     fclose(fp);
     exit(EXIT_FAILURE);
   }

   while (1) {
       printf("Enter person (age, name): ");
       fgets(input, 100, stdin);

       if (input[0] == '\n') {
           break;
       }

       sscanf(input, "%d, %[^\t\n]", &age, name);
       name_len = strlen(name);

       fwrite(&age, sizeof(int), 1, fp);
       fwrite(&name_len, sizeof(int), 1, fp);
       fwrite(name, sizeof(name[0]), sizeof(name) / sizeof(name[0]) , fp);
   }

   fclose(fp);

   return 0;
 }
