#include <stdlib.h>
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
#include <stdarg.h>
#include <limits.h>
#include <libgen.h>




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
            my_putstr("Error: ");
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

       
       printf("%ju  %s\n",(__uintmax_t) sb.st_ino, dirent->d_name );
       
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
        printf("Error : select a directory. \n");
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


         printf("%c",(sb.st_mode & S_IRUSR)==S_IRUSR ? 'w' : '-');
         printf("%c",(sb.st_mode & S_IWUSR)==S_IWUSR ? 'w' : '-');
         printf("%c",(sb.st_mode & S_IXUSR)==S_IXUSR ? 'x' : '-');
         printf("%c",(sb.st_mode & S_IRGRP)==S_IRGRP ? 'r' : '-');
         printf("%c",(sb.st_mode & S_IWGRP)==S_IWGRP ? 'w' : '-');
         printf("%c",(sb.st_mode & S_IXGRP)==S_IXGRP ? 'x' : '-');
         printf("%c",(sb.st_mode & S_IROTH)==S_IROTH ? 'r' : '-');
         printf("%c",(sb.st_mode & S_IWOTH)==S_IWOTH ? 'w' : '-');
         printf("%c",(sb.st_mode & S_IXOTH)==S_IXOTH ? 'x' : '-');
         printf("%4ld ",(__uintmax_t) sb.st_nlink);
         printf(" %-8.8s", pwd->pw_name); 
         printf("%-8.8s", grp->gr_name); 
         printf(" %9jd ", (intmax_t)sb.st_size);
         char *time = malloc(14 * sizeof(char));
         strftime(time, 50, "%b %e %R", localtime(&sb.st_mtime));
         printf("%s ",time);
         printf("%s\n", dirent->d_name);
       
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

         printf("%c",(sb.st_mode & S_IRUSR)==S_IRUSR ? 'r' : '-');
         printf("%c",(sb.st_mode & S_IWUSR)==S_IWUSR ? 'w' : '-');
         printf("%c",(sb.st_mode & S_IXUSR)==S_IXUSR ? 'x' : '-');
         printf("%c",(sb.st_mode & S_IRGRP)==S_IRGRP ? 'r' : '-');
         printf("%c",(sb.st_mode & S_IWGRP)==S_IWGRP ? 'w' : '-');
         printf("%c",(sb.st_mode & S_IXGRP)==S_IXGRP ? 'x' : '-');
         printf("%c",(sb.st_mode & S_IROTH)==S_IROTH ? 'r' : '-');
         printf("%c",(sb.st_mode & S_IWOTH)==S_IWOTH ? 'w' : '-');
         printf("%c",(sb.st_mode & S_IXOTH)==S_IXOTH ? 'x' : '-');
         printf("%4ld ",(__uintmax_t) sb.st_nlink);
         printf("%-8.8s", grp->gr_name); 
         printf(" %9jd ", (intmax_t)sb.st_size);
         char *time = malloc(14 * sizeof(char));
         strftime(time, 50, "%b %e %R", localtime(&sb.st_mtime));
         printf("%s ",time);
         printf("%s\n", dirent->d_name);
       
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


    printf("Reading files in: %s\n", dirname);

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) 
    {
        if(entity->d_name[0] != '.')
        {
            printf("    %s\n", entity->d_name);
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


/* my_lsa = Ls -a = fichiers ( meme cachés) dans l’ordre 

my_lsf = Ls -f = tout compris (même cachés) dans le désordre      Bonus

my_lssansalpha = ls sans l’ordre alphabétique 

my_lsi = Ls-i = ls inode  nom de dossiers + leur num inode       Bonus

my_lsl = Ls-l = ls -l sans ordre alphabétique

my_lsg = Ls-g = ls -g sans ordre alphabétique et PROPRIETAIRE.   Bonus 

my_ls = ls = nom des fichiers dans l’ordre alphabétique          Bonus

my_lsr = ls-r = nom des fichiers dans l’ordre alphabétique à l’envers

my_lsA = ls -A : ls sans « . » Et « .. »  

my_lsR = ls -R = ordonner avec titre et sous dossiers */



/*int main(int argc, char *argv[]){

//my_ls(argc, argv);
//my_lsa(argc, argv);
//my_lsA(argc, argv);
//my_lsf(argc, argv);
//my_lssansalpha(argc, argv);
//my_lsi(argc, argv);
//my_lsl(argc, argv);
//my_lsg(argc, argv);
my_lsr(argc, argv);
//my_lst(argc, argv);


    return 0;

} */


int main() {


my_lsR(".");

return 0;

}

