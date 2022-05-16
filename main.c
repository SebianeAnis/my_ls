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


int main(int ac, char *argv[]) {


    int opt = 0;
    

    int a = 0;
    int A = 0;
    int R = 0;
    int f = 0;
    int z = 0;
    int i = 0;
    int l = 0;
    int g = 0;
    int r = 0;
    int t = 0;

  
   while((opt = getopt(ac, argv, "aARfzilgrt")) != -1){ 


      switch(opt){
        
       
            case 'a':
                a = 1;
                break;
            case 'A':
                A = 1;
                break;
            case 'R':
                R = 1;
                break;
            case 'f':
                f = 1;
                break;
            case 'z':
                z = 1;
                break;
            case 'i':
                i = 1;
                break;
            case 'l':
                l = 1;
                break;
            case 'g':
                g = 1;
                break;
            case 'r':
                r = 1;
                break;
            case 't':
                t = 1;
                break;


      }
   }


  if (a == 1)

    {
        my_lsa(ac,argv);
    }

  else  if ( A == 1 )

    {
        my_lsA(ac, argv);

    }

  else  if ( R == 1 )

    {
        my_lsR(".");

    }

   else  if ( f == 1 )

    {
        my_lsf(ac, argv);

    }   

   else  if ( z == 1 )

    {
        my_lssansalpha(ac, argv);

    }


  else  if ( i == 1 )

    {
        my_lsi(ac, argv);

    }

  else  if ( l == 1 )

    {
        my_lsl(ac, argv);

    } 

  else  if ( g == 1 )

    {
        my_lsg(ac, argv);

    }

  else  if ( r == 1 )

    {
        my_lsr(ac, argv);

    }

  else  if ( t == 1 )

    {
        my_lst(ac, argv);

    }

  else

    {
        my_ls(ac, argv);

    }


return 0;

}


