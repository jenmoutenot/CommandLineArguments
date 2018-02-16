#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"

// This is my code
// Jen Moutenot
// CS366

const int BUF_SIZE = 512;

/* purpose: to change the current file's access mode
 * input: the current file
 * returns: nothing
*/
void mode(char *file)
{
  char *new_mode;
  printf("Enter access mode: \n");
  scanf("%s", *new_mode);
  FILE *fp = fopen(file, "w");
  if (file == NULL)
    perror("Can't open the file");
  else
  {
    chmod(fp, new_mode);
  }
  close(file);
}

/* purpose: to display the last 100 bytes, or fewer if fewer exist, of the current file
 * input: the current file
 * returns:
*/
void last(char *file)
{
  int last_bytes;
  char *c;

  FILE *fp = fopen(file_name, "r");
  if ( file == NULL)
    perror("Can't open the file");
  else
  {
    fseek(file, -100, SEEK_END);
    int i;
    while (( i = fgetc(file)) != EOF)
    {
      printf("%s\n", i);
    }
    close(file);
  }
}

/* purpose: to change the file's access time to the current time
 * input: the current file
 * returns:

void time()
{
}
*/

/* purpose: to append the current file to another file
 * input: the current file
 * returns:
*/
void append(char *file) 
{
  char c;
  char dest[BUF_SIZE]; 
  printf("Enter file destination you would like to append to: \n");
  scanf("%s", dest); //scanning the user's input
  FILE *fp1 = fopen(file, "r"); //reading the current file
  FILE *fp2 = fopen(dest, "a"); //appending into the destination
  if (file == NULL)
    perror("Can't open the file");
  if (dest == NULL)
    perror("Can't open the file");
  while ((c = getc(fp1))!= EOF)
  {
    putc(c, fp2);
  }
  close(file);
  close(dest);  
}
/* purpose: to duplicate the current file, which creates a copy of the file
 * input: the current file
 * returns:
*/
void duplicate(char *file)
{
  char c;
  char dest[BUF_SIZE];
  
  printf("Enter destination name: \n");
  scanf("%s", dest); //scanning the user's input
  FILE *fp1 = fopen(file, "r");  //reading the current file
  FILE *fp2 = fopen(dest, "w");  //writing the copy into the file destination
  if (file == NULL)
    perror("Can't open the file");
  if (dest == NULL)
    perror("Can't open the file");
  while ((c = getc(fp1))!= EOF)  // copy the contents until you get to the end of the file
  {
    putc(c, fp2); //put the contents inside the new file
  }
  close(file);
  close(dest);
}

/* purpose: to rename the current file
 * input: the current file
 * returns:
*/
void rename_file(char *file_old)
{
  char file_new[BUF_SIZE]; //technically a pointer
  
  printf("Enter new name for file: \n");
  scanf("%s", file_new);  //scanning the user's input
  if (rename(file_old, file_new) == 0 ) //file_old is still a pointer, was not dereferenced
  {
    printf("%s has been renamed %s.\n", file_old, file_new); //passing through strings
  }
    else 
  {
    perror("Error\n");
  }
}

/* purpose: to list the current file contents to /dev/tty
 * input: the current file
 * returns:
*/
void cat(char *file)
{
  FILE *fp; //initialize file we are manipulating
  fp = fopen(file, "r"); //fp is the file pointer
  if (file == NULL)
    perror("Can't open the file");
  char c;  
  c = fgetc(fp);  
  while(c != EOF) //end of file
  {
     printf("%c", c); //printing the contents of the file
     c = fgetc(fp); 
  }
  close(file);
}

/* purpose: to clean up and organize Mr. Krabs' files using the program wash
 * input: an array of files
 * returns:
*/

int main(int argc, char *argv[])
{
  if(argc <= 1) 
  {
    printf("Enter in the files\n");
    exit(-1); 
  }
  printf("\nEnter in one of the following commands:\n");
  printf(" ’c’ cat, list the current file to /dev/tty\n");
  printf(" ’d’ duplicate the current file (duplicate)\n");
  printf(" ’r’ rename the current file\n");
  printf(" ’u’ unlink the current file\n");
  printf(" ’t’ truncate the current file\n");
  printf(" ’a’ append the current file to another file\n");
  printf(" ’l’ last, display the last 100 bytes of the current file\n");
  printf(" ’m’ mode, change the current file’s access permissions\n");
  printf(" ’x’ change the current file’s access time to the current time \n");
  printf(" ’n’ next, goto the next file \n");
  printf(" ’q’ quit\n");
  
  for(argv++; *argv != NULL; )   //incrementing argv(the array of files) to go to the next file
  {
    char command[BUF_SIZE];
    printf("\nfile %s: command:", *argv);
    fgets(command, BUF_SIZE, stdin);

    switch (*command)
    {
      case 'c': cat(*argv); break;
      case 'd': duplicate(*argv); break;
      case 'r': rename_file(*argv); break;
      case 'u': unlink(*argv); break;
      case 't': truncate(*argv, 0); break;
      case 'a': append(*argv); break;
   /*  
      case 'l': last(*argv); break;
   */
      case 'm': mode(*argv); break;
   /*
      case 'x': time(*argv); break;
    */
      case 'n': argv++; break;         //incrementing to the next file
      case 'q': return 0; break; 
    }
  }  

  return 1; //returning off of 'n' to quit
  
}
