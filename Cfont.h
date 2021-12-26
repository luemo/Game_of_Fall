#ifndef _CFONT__H_
#define _CFONT__H_
int init_Cfont();
int close_Cfont();
int print_cfont(BITMAP *Cfont_out,int x,int y,int R,int G,int B,int line);
#endif