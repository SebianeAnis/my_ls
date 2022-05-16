#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "handlers.h"






int my_putchar(char *c){
return write(sizeof(char), &c, 1);
}

//afficher une chaine de caractère
int my_putstrr(char str){
int *a = 0;
if(str == NULL) return my_putstrr("(NULL)");
while(str[a]!= '\0'){
write(sizeof(char), &str[a], 1);
a++;
}
return a;
}


char return_converted(int num, int base){
char number[] = "0123456789";
char conv = malloc(100*sizeof(int));
int affichenum, index = 0;
while(num > 0){
affichenum = num % base;
for(int i =0; i < base; i++)
if(affichenum == i){

    int *index;
conv[index] = number[i];
index++;
}
num /= base;
}
return conv;
}
int my_putcharr(char c)
{
write (1, &c, 1);
}
//affichier un entier
int my_putint(int nb)
{
int mod;

if (nb < 0)
{
my_putcharr('-');
nb = nb * (-1);
}
if (nb >= 0)
{
if (nb >= 10)
{
mod = (nb % 10);
nb = (nb - mod) / 10;
my_putint(nb);
my_putcharr(48 + mod);
}
else
my_putcharr(48 + nb % 10);
}
}

int my_printf(char* format, ...){
va_list args;
char *outputString, *s; 
int i, ret = 0;
long l;
va_start(args, format);

for(outputString = format; outputString != '\0'; outputString++){
if(outputString == '%'){
outputString++;
switch(*outputString){
case 'c' : s = va_arg(args, char );
ret += my_putchar(s);
break;
case 'd': i = va_arg(args, int);
ret += my_putint(i);
break;
case 's': s = va_arg(args, char);
ret+= my_putstrr(s);
break;
}
}
else ret += write(1,outputString, 1);
}
va_end(args);

return ret;
}




/* //////////////////// my_strcmp ///////////////////////// */

int my_strcmp(const char *s1, const char *s2)
{
    int i=0;
    int diff=0;
    
    while (s1[i] != '\0' && s2[i] != '\0')
        {
            if (s1[i] != s2[i])
                {
                    diff = s1[i]-s2[i];
                    return diff;
                }
            
            else
                {
                    i++;
                }
            
            
        }
    
    return s1[i]-s2[i];   

}

/* //////////////////// my_strcmp ///////////////////////// */


/* //////////////////// my_putchar ///////////////////////// */


void my_putchar(char c)
{
  write(1, &c, 1);
}

/* //////////////////// my_putchar ///////////////////////// */



void my_variable(char *c)
{
  write(1, c, sizeof(c));
}


/* //////////////////// my_putstr ///////////////////////// */


void my_putstr(const char *str)
{
    int i = 0;
    while ( str[i] != '\0' )
        {
            my_putchar(str[i]);
            i++;
        }
    
}

/* //////////////////// my_putstr ///////////////////////// */



/* //////////////////// LS -a ///////////////////////// */


int my_lsa(int ac,char *argv[]) 
    {
        DIR *dir;
        struct dirent *dirent;
        struct stat sb;
        struct tiles {
   
        char *name; 
        int size; 
        int nlink;
        char *nameuser;
        char *ID;
        int modeR;
        long int date;
        };


        char *folder_name = (ac < 2) ? "." : argv[1];

        


        if ((dir = opendir(folder_name)) == NULL)
        {
            my_printf("Error: ");
            my_variable((folder_name));
            my_putstr("is not file or directory.\n");
            return(1);
        }


 
   struct tiles tableau[256];


   int nbr=0;

        while ((dirent = readdir(dir)) != NULL)
        {
           
              stat(dirent->d_name,&sb);

                       tableau[nbr].name=dirent->d_name;


                       nbr++;

        
        }

 
  struct tiles tempo;

    for(int i=0; i<nbr; i++){
    for(int j=0; j<nbr-1-i; j++){
      if(my_strcmp(tableau[j].name, tableau[j+1].name) > 0)
            {
                tempo = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tempo;
            } 
        }
    }
          for(int i=0;i<nbr;i++){


               my_variable((tableau[i].name));
               my_putstr("\n");

          }
        closedir(dir);

        return 0;

    }

/* //////////////////// LS -a ///////////////////////// */






/* //////////////////// LS sans ordre alphabétique ///////////////////////// */


int my_lssansalpha(int argc,char *argv[]){

    DIR *dir;
   
    char *folder_name = (argc < 2) ? "." : argv[1];

    dir = opendir(folder_name);

    if(dir == NULL)
    {
        my_putstr("Error : select a directory. \n");
        return(1);
    }

    struct dirent *dirent;

  while ((dirent=readdir(dir)) != NULL)
   {
    if(dirent->d_name[0] != '.')
    {
       my_variable((dirent->d_name));
       my_putstr("\n");
   }
   }
      closedir(dir);

   return 0;
}
/* //////////////////// LS sans ordre alphabétique ///////////////////////// */





/* //////////////////// LS -f  ///////////////////////// */

int my_lsf(int argc,char *argv[]){

    DIR *dir;
   
    char *folder_name = (argc < 2) ? "." : argv[1];

    dir = opendir(folder_name);

    if(dir == NULL)
    {
        my_putstr("Error : select a directory. \n");
        return(1);
    }

    struct dirent *dirent;

    while ((dirent=readdir(dir)) != NULL)
   {
    
       my_variable((dirent->d_name));
        my_putstr("\n");

   }
      closedir(dir);

   return 0;
}

/* //////////////////// LS -f ///////////////////////// */




/* //////////////////// LS -i ///////////////////////// */

int my_lsi(int argc,char *argv[]){

    DIR *dir;
   
    char *folder_name = (argc < 2) ? "." : argv[1];

    dir = opendir(folder_name);

    if(dir == NULL)
    {
        my_putstr("Error : select a directory. \n");
        return(1);
    }



struct dirent *dirent;
struct stat sb;


  while ((dirent=readdir(dir)) != NULL)
   {
    if(dirent->d_name[0] != '.'){
       
       stat(dirent->d_name, &sb);

       
       my_printf("%ju  %s\n",(__uintmax_t) sb.st_ino, dirent->d_name );
       
    }
  
   }
   closedir(dir);
   return 0;

}
/* //////////////////// LS -i ///////////////////////// */




/* //////////////////// LS -l ///////////////////////// */

int my_lsl(int argc,char *argv[]){

    DIR *dir;
   
    char *folder_name = (argc < 2) ? "." : argv[1];

    dir = opendir(folder_name);

    if(dir == NULL)
    {
        my_printf("Error : select a directory. \n");
        return(1);
    }


struct dirent *dirent;
struct stat sb;
struct passwd  *pwd;
struct group *grp;


  while ((dirent=readdir(dir)) != NULL)
   {
    if(dirent->d_name[0] != '.'){
       
       stat(dirent->d_name, &sb);
       pwd = getpwuid(sb.st_uid);
       grp = getgrgid(sb.st_gid);       
       

         if(dirent->d_type == 10 ){
            my_putstr("l"); 
         }

         if(dirent->d_type == 4 ){
            my_putstr("d");
         }

          else{
            my_putstr("-");
         }

         my_printf("%c",(sb.st_mode & S_IRUSR)==S_IRUSR ? 'r' : '-');
         my_printf("%c",(sb.st_mode & S_IWUSR)==S_IWUSR ? 'w' : '-');
         my_printf("%c",(sb.st_mode & S_IXUSR)==S_IXUSR ? 'x' : '-');
         my_printf("%c",(sb.st_mode & S_IRGRP)==S_IRGRP ? 'r' : '-');
         my_printf("%c",(sb.st_mode & S_IWGRP)==S_IWGRP ? 'w' : '-');
         my_printf("%c",(sb.st_mode & S_IXGRP)==S_IXGRP ? 'x' : '-');
         my_printf("%c",(sb.st_mode & S_IROTH)==S_IROTH ? 'r' : '-');
         my_printf("%c",(sb.st_mode & S_IWOTH)==S_IWOTH ? 'w' : '-');
         my_printf("%c",(sb.st_mode & S_IXOTH)==S_IXOTH ? 'x' : '-');
         my_printf("%4ld ",(__uintmax_t) sb.st_nlink);
         my_printf(" %-8.8s", pwd->pw_name); 
         my_printf("%-8.8s", grp->gr_name); 
         my_printf(" %9jd ", (intmax_t)sb.st_size);
         char *time = malloc(14 * sizeof(char));
         strftime(time, 50, "%b %e %R", localtime(&sb.st_mtime));
         my_printf("%s ",time);
         my_printf("%s\n", dirent->d_name);
       
    }
  
   }
    closedir(dir);

   return 0;
   
}



/* //////////////////// LS -l ///////////////////////// */



/* //////////////////// LS -g ///////////////////////// */


int my_lsg(int argc,char *argv[]){

    DIR *dir;
   
    char *folder_name = (argc < 2) ? "." : argv[1];

    dir = opendir(folder_name);

    if(dir == NULL)
    {
        my_putstr("Error : select a directory. \n");
        return(1);
    }


struct dirent *dirent;
struct stat sb;
struct group *grp;


  while ((dirent=readdir(dir)) != NULL)
   {
    if(dirent->d_name[0] != '.'){
       
       stat(dirent->d_name, &sb);
       grp = getgrgid(sb.st_gid);       
       

         if((intmax_t) sb.st_mode == 16877 ){
            my_putstr("d");
         }
          else{
            my_putstr("-");
         }

         my_printf("%c",(sb.st_mode & S_IRUSR)==S_IRUSR ? 'r' : '-');
         my_printf("%c",(sb.st_mode & S_IWUSR)==S_IWUSR ? 'w' : '-');
         my_printf("%c",(sb.st_mode & S_IXUSR)==S_IXUSR ? 'x' : '-');
         my_printf("%c",(sb.st_mode & S_IRGRP)==S_IRGRP ? 'r' : '-');
         my_printf("%c",(sb.st_mode & S_IWGRP)==S_IWGRP ? 'w' : '-');
         my_printf("%c",(sb.st_mode & S_IXGRP)==S_IXGRP ? 'x' : '-');
         my_printf("%c",(sb.st_mode & S_IROTH)==S_IROTH ? 'r' : '-');
         my_printf("%c",(sb.st_mode & S_IWOTH)==S_IWOTH ? 'w' : '-');
         my_printf("%c",(sb.st_mode & S_IXOTH)==S_IXOTH ? 'x' : '-');
         my_printf("%4ld",(__uintmax_t) sb.st_nlink);
         my_printf("%-8.8s", grp->gr_name); 
         my_printf(" %9jd ", (intmax_t)sb.st_size);
         char *time = malloc(14 * sizeof(char));
         strftime(time, 50, "%b %e %R", localtime(&sb.st_mtime));
         my_printf("%s ",time);
         my_printf("%s\n", dirent->d_name);
       
    }
  
   }
    closedir(dir);

   return 0;
   
}

/* //////////////////// LS -g ///////////////////////// */




/* //////////////////// LS -r ///////////////////////// */


int my_lsr(int ac,char *argv[]) 
    {
        DIR *dir;
        struct dirent *dirent;
        struct stat sb;
        struct tiles {
   
        char *name; 
        int size; 
        int nlink;
        char *nameuser;
        char *ID;
        int modeR;
        long int date;
        };


        char *folder_name = (ac < 2) ? "." : argv[1];


        if ((dir = opendir(folder_name)) == NULL)
        {
            my_putstr("Error: ");
            my_variable(folder_name);
            my_putstr(" is not file or directory. \n");
            return(1);
        }


 
    struct tiles tableau[256];


    int nbr=0;

        while ((dirent = readdir(dir)) != NULL)
        {
            if (dirent->d_name[0] != '.')
            {
              stat(dirent->d_name,&sb);

                       tableau[nbr].name=dirent->d_name;


                       nbr++;

        }
        }

 
     struct tiles tempo;

    for(int i=0; i<nbr; i++){
    for(int j=0; j<nbr-1-i; j++){
      if(my_strcmp(tableau[j].name, tableau[j+1].name) < 0)
            {
                tempo = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tempo;
            } 
        }
    }
          for(int i=0;i<nbr;i++){


               my_variable(tableau[i].name);
               my_putstr("\n");

          }
        closedir(dir);

        return 0;

    }

/* //////////////////// LS -r ///////////////////////// */



/* //////////////////// LS -t ///////////////////////// */


 int my_lst(int ac,char *argv[]) 
    {
        DIR *dir;
        struct dirent *dirent;
        struct stat sb;
        struct tiles {
   
        char *name; 
        int size; 
        int nlink;
        char *nameuser;
        char *ID;
        int modeR;
        long int date;
        };


        char *folder_name = (ac < 2) ? "." : argv[1];


        if ((dir = opendir(folder_name)) == NULL)
        {
            my_putstr("Error: ");
            my_variable(folder_name);
            my_putstr(" is not file or directory. \n");
            return(1);
        }


 
    struct tiles tableau[256];


    int nbr=0;

        while ((dirent = readdir(dir)) != NULL)
        {
            if (dirent->d_name[0] != '.')
            {
              stat(dirent->d_name,&sb);

            char *time = malloc(14 * sizeof(char));
            strftime(time, 50, "%b %e %R", localtime(&sb.st_mtime));

                       tableau[nbr].date=*time;   


                       nbr++;

        }
        }

 
     struct tiles tempo;

    for(int i=0; i<nbr; i++){
    for(int j=0; j<nbr-1-i; j++){
      
      if(tableau[j].date<tableau[j+1].date)
            {
                tempo = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tempo;
            } 
        }
    }
          for(int i=0;i<nbr;i++){


               my_variable(tableau[i].name);
               my_putstr("\n");

          }
        closedir(dir);

        return 0;

    }


/* //////////////////// LS -t ///////////////////////// */






/* //////////////////// LS -A ///////////////////////// */


int my_lsA(int ac,char *argv[]) 
    {
        DIR *dir;
        struct dirent *dirent;
        struct stat sb;
        struct tiles {
   
        char *name; 
        int size; 
        int nlink;
        char *nameuser;
        char *ID;
        int modeR;
        long int date;
        };


        char *folder_name = (ac < 2) ? "." : argv[1];


        if ((dir = opendir(folder_name)) == NULL)
        {
            my_putstr("Error: ");
            my_variable(folder_name );
            my_putstr(" is not file or directory. \n");
            return(1);
        }


 
    struct tiles tableau[256];


    int nbr=0;

        while ((dirent = readdir(dir)) != NULL)
        {
           
              stat(dirent->d_name,&sb);

                       tableau[nbr].name=dirent->d_name;


                       nbr++;

       
        }

 
     struct tiles tempo;

    for(int i=0; i<nbr; i++){
    for(int j=0; j<nbr-1-i; j++){
      if(my_strcmp(tableau[j].name, tableau[j+1].name) > 0)
            {
                tempo = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tempo;
            } 
        }
    }
          for(int i=0;i<nbr;i++){

             if((my_strcmp(tableau[i].name, "." ) == 0 ) ||  my_strcmp(tableau[i].name, ".." ) == 0 ){
             continue;
                   }
                   else{

                          my_variable(tableau[i].name);
                          my_putstr("\n");
                   }
          }
        closedir(dir);

        return 0;

    }

/* //////////////////// LS -A  ///////////////////////// */


/* //////////////////// LS  ///////////////////////// */


int my_ls(int ac,char *argv[]) 
    {
        DIR *dir;
        struct dirent *dirent;
        struct stat sb;
        struct tiles {
   
        char *name; 
        int size; 
        int nlink;
        char *nameuser;
        char *ID;
        int modeR;
        long int date;
        };


        char *folder_name = (ac < 2) ? "." : argv[1];


        if ((dir = opendir(folder_name)) == NULL)
        {
            my_putstr("Error: ");
            my_variable(folder_name );
            my_putstr(" is not file or directory. \n");

            return(1);
        }


 
    struct tiles tableau[256];


    int nbr=0;

        while ((dirent = readdir(dir)) != NULL)
        {
            if (dirent->d_name[0] != '.')
            {
              stat(dirent->d_name,&sb);

                       tableau[nbr].name=dirent->d_name;


                       nbr++;

        }
        }

 
     struct tiles tempo;

    for(int i=0; i<nbr; i++){
    for(int j=0; j<nbr-1-i; j++){
      if(my_strcmp(tableau[j].name, tableau[j+1].name) > 0)
            {
                tempo = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tempo;
            } 
        }
    }
          for(int i=0;i<nbr;i++){


               my_variable(tableau[i].name);
               my_putstr("\n");
          }
        closedir(dir);

        return 0;

    }

/* //////////////////// LS  ///////////////////////// */



/* //////////////////// LS -R ///////////////////////// */


void my_lsR(const char * dirname) 
    {
         DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }


    my_printf("Reading files in: %s\n", dirname);

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) 
    {
        if(entity->d_name[0] != '.')
        {
            my_printf("    %s\n", entity->d_name);
            if (entity->d_type == 4 && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) 
            {
                char path[100] = { 0 };
                strcat(path, dirname);
                strcat(path, "/");
                strcat(path, entity->d_name);
                my_lsR(path);
            }
        }
            entity = readdir(dir);
    }
        


    closedir(dir);

    } 
    


/* //////////////////// LS -R ///////////////////////// */




