#ifndef HANDLERS
#define HANDLERS

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
#include "handlers.c"


int my_strcmp(const char *s1, const char *s2);
void my_putchar(char c);
void my_variable(char *c);
void my_putstr(const char *str);

int my_ls(int ac,char *argv[]);
int my_lsa(int argc,char *argv[]);
int my_lsA(int argc,char *argv[]);
void my_lsR(const char * dirname);
int my_lsf(int argc,char *argv[]);
int my_lssansalpha(int argc,char *argv[]);
int my_lsi(int argc,char *argv[]);
int my_lsl(int argc,char *argv[]);
int my_lsg(int argc,char *argv[]);
int my_lsr(int argc,char *argv[]);
int my_lst(int argc,char *argv[]);



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


#endif