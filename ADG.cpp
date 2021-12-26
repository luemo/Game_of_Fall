

#include <stdio.h>
#include <allegro.h>
#include <math.h>
#include "Cfont.h"

#define lift 55
#define LIFT 55
#define MIDDLE 160
#define RIGHT 265
#define ONE 48
#define TWO 120
#define THREE 192


int Chap_Four ();
int Chap_Four_One ();/*英杰*/
int Chap_Four_Two ();/*李昱*/
int Chap_Four_Three ();/*洛維*/
int Chap_Fifth ();
int Chap_Fifth_One ();
int Chap_Fifth_Two ();
int Chap_Fifth_Three ();
int Chap_Sixth ();
int Chap_Sixth_One ();
int Chap_Sixth_Two ();
int Chap_Sixth_Three ();
int Chap_Seven ( int i, int like );

void Start ();
int GirlMove ( int GirlX1, int GirlX2, int BoyX1, int n );
int BoyMove ( int BoyX1, int BoyX2, int GirlX1, int n );
int appear ( int X, int X1, int n );
void ChangFace ( int n , int i , int j);/*變臉圖，n=人，i=幕，j=張(第六幕才需要)P.S.:readkey要去掉?*/
int SixForOther ( int BoyX1, int GirlX1,int OtherX1);
int ChooseToStory (int i);
void BleakColor ();
void PutFace ();
int Print_words(int X, int R,int G, int B, int line);

BITMAP *buffer;
BITMAP *buffer2;
BITMAP *BigMap;
BITMAP *Girl;
BITMAP *Other;
BITMAP *Boy;
BITMAP *Face;

BITMAP *BigMap_4;
BITMAP *BigMap_4_1;
BITMAP *BigMap_4_2;
BITMAP *BigMap_4_3;
BITMAP *Girl1_4;/*千語*/
BITMAP *Boy1_4;/*英杰*/
BITMAP *Boy2_4;/*李昱*/
BITMAP *Boy3_4;/*洛維*/
BITMAP *FaceG1_4;/*千語*/
BITMAP *FaceB1_4;/*英杰*/
BITMAP *FaceB2_4;/*李昱*/
BITMAP *FaceB3_4;/*洛維*/
SAMPLE *Music4;
SAMPLE *Music4_1;
SAMPLE *Music4_2;
SAMPLE *Music4_3;
SAMPLE *Music4_4;

BITMAP *BigMap_5;
BITMAP *BigMap_5_1;
BITMAP *BigMap_5_2;
BITMAP *BigMap_5_3_1;
BITMAP *BigMap_5_3_2;
BITMAP *Girl1_5;
BITMAP *Other_1;/*其他角色*/
BITMAP *Boy1_5;
BITMAP *Boy2_5;
BITMAP *Boy3_5;
BITMAP *FaceG1_5;
BITMAP *FaceB1_5;
BITMAP *FaceB2_5;
BITMAP *FaceB3_5;
BITMAP *FaceOther_1;/*其他角色*/
SAMPLE *Music5;
SAMPLE *Music5_1;
SAMPLE *Music5_2;
SAMPLE *Music5_3;
SAMPLE *Music5_4;
SAMPLE *Music5_5;


BITMAP *BigMap_6_1;
BITMAP *BigMap_6_2;
BITMAP *BigMap_6_3;
BITMAP *Girl1_6_1;
BITMAP *Girl1_6_2;
BITMAP *Other_2;
BITMAP *Other_3;
BITMAP *Other_4;
BITMAP *Boy1_6_1;
BITMAP *Boy1_6_2;
BITMAP *Boy2_6_1;
BITMAP *Boy2_6_2;
BITMAP *Boy3_6_1;
BITMAP *Boy3_6_2;
BITMAP *FaceG1_6_1;
BITMAP *FaceG1_6_2;
BITMAP *FaceB1_6_1;
BITMAP *FaceB1_6_2;
BITMAP *FaceB2_6_1;
BITMAP *FaceB2_6_2;
BITMAP *FaceB3_6_1;
BITMAP *FaceB3_6_2;
BITMAP *FaceOther_2;
BITMAP *FaceOther_3;
BITMAP *FaceOther_4;
SAMPLE *Music6;
SAMPLE *Music6_1;
SAMPLE *Music6_2;
SAMPLE *Music6_3;

BITMAP *BigMap_7;
BITMAP *BigMap_7_1;
BITMAP *BigMap_7_2;
BITMAP *BigMap_7_3;
BITMAP *BigMap_7_4;
BITMAP *Girl1_7;
BITMAP *Boy1_7;
BITMAP *Boy2_7;
BITMAP *Boy3_7;
BITMAP *FaceG1_7;
BITMAP *FaceB1_7;
BITMAP *FaceB2_7;
BITMAP *FaceB3_7;
SAMPLE *Music7;
SAMPLE *Music7_1;
SAMPLE *Music7_2;
SAMPLE *Music7_3;
SAMPLE *Music7_4;
SAMPLE *Music7_5;

BITMAP *Bleak;
BITMAP *HandChoose;
BITMAP *CubeChoose;
BITMAP *CubeChoose1;


/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

/*chapter1*/
volatile int boy_to_left ( int boyX );
int chap1(int serifu_y);
int only_b(int serifu_y2);
int only_g(int serifu_y3);
int class_r(int serifu_c);
int class_r2(int serifu_c2);
/*interval*/
void f1t2(int x);
/*chater2*/
int saten(int serifu_yy);
int saten2(int serifu_yy2);
int saten3(int serifu_yy3);
int saten4(int serifu_yy4);
int saten5(int serifu_yy5);

/*poniter of bitmap&sample*/
//BITMAP *buffer;
BITMAP *back;				/*image of bg in chap1  borridors*/
BITMAP *back2;				/*image of bg in chap1  classroom*/
BITMAP *back3;				/*image of bg in chap2  cafe1*/
BITMAP *back4;				/*image of bg in chap2  cafe2*/
BITMAP *boy;				/*image of boy*/
BITMAP *girl;				/*image of girl*/
BITMAP *serifu;				/*image of frame*/
BITMAP *seri;				/*image of dialogue in  chap1*/
BITMAP *seri2;				/*image of dialogue in chap2*/
SAMPLE *bgm1;				/*sound of bgm in chap1*/
SAMPLE *chime;				/*sound of chime*/
SAMPLE *door;				/*sound of opened a door*/
SAMPLE *bgm2;				/*sound of bgm in chap2*/
SAMPLE *bell;				/*sound of bell*/
/*********************************************************************************************/
/*********************************************************************************************/
/*********************************************************************************************/
/*********************************************************************************************/

/*start main*/
int main()
{

	allegro_init();
	install_keyboard();
	install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL );
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

	init_Cfont();/*文字系統*/

/*********************************************************************************************/
/**************************************主程式之文子的部分↓***********************************/
/*********************************************************************************************/

	buffer = create_bitmap(SCREEN_W, SCREEN_H);					/* create buffer */
	back = load_bitmap("image/rouka.bmp", NULL);				/*load the image of bg in chap1*/
	back2 = load_bitmap("image/class.bmp", NULL);				/*load the image of bg in chap1*/
	back3 = load_bitmap("image/saten.bmp", NULL);				/*load the image of bg in chap2*/
	back4 = load_bitmap("image/saten2.bmp", NULL);				/*load the image of bg in chap2*/
	boy = load_bitmap("image/B1.bmp", NULL);					/*load the image of boy*/
	girl = load_bitmap("image/As.bmp", NULL);					/*load the image of girl*/
	serifu = load_bitmap("image/line.bmp", NULL);				/*load the image of frame*/
	seri = load_bitmap("image/chap1.bmp", NULL);				/*load the image chap1's dialogue*/
	seri2 = load_bitmap("image/chap2.bmp", NULL);				/*load the image chap2's dialogue*/
	bgm1 = load_sample( "sound/sawa04.wav" );					/* load the sound of bgm in chap1*/
	door = load_sample("sound/door.wav");						/* load the sound of door opening */
	chime = load_sample( "sound/chime.wav" );					/* load the sound of chime */
	bgm2 = load_sample( "sound/saten.wav" );					/* load the sound of bgm in chap2 */
	bell = load_sample( "sound/bell.wav" );						/* load the sound of bell */


	/*display the images&sound*/
	blit(back, buffer, 0, 0, 0, 0, 640, 480);
	blit(back2, buffer, 0, 0, 0, 0, 640, 480);
	blit(boy, buffer, 0, 0, 0, 0, boy->w, boy->h);
	blit(girl, buffer, 0, 0, 0, 360, 120, 120);
	blit(seri, buffer, 0, 0, 130, 370, 500, 100);
	blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
	play_sample(bgm1, 70, 128, 1000, 1);						/*sound of bgm in chap1*/

	blit(back3, buffer, 0, 0, 0, 0, 640, 480);
	blit(seri2, buffer, 0, 0, 130, 370, 500, 100);
	blit(serifu, buffer, 0, 0, 0, 360, buffer->w,  buffer->h);
	play_sample(bgm2, 20, 128, 1000, 1);	/*sound of bgm2 in chap2*/
	blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		
	
	int boyX = 640;
	int x = 0;
	int y, y2, y3, c, c2, s, s2, s3, s4, s5;


/*called function*/

	
	boyX = boy_to_left ( 640 );			/*boy move to left*/
	y = chap1( 0 );						/*meet senior boy in corridors scroll line 190px*/
	y2 = only_b(0);						/*boy only scroll line to 220px */
	y3 = only_g(0);						/*girl only scroll line to 325px*/
	c = class_r(0);						/*meet classmate in classroom scroll line to 405*/
	c2 = class_r2(0);					/*talk to classmate in classroom scroll line to 1035px */


	s = saten(0);						/*come to customers scroll line 70px*/	
	s2 = saten2(0);						/*talk only customer scroll line 160px*/
	s3 = saten3(0);						/*appear part job scroll line 670px*/
	s4 = saten4(0);						/*boy come back to cafe*/
	s5 = saten5(0);						/*ask to be girlfriend scroll line 1134px*/
	stop_sample(bgm2);					/*stop the bgm2 */

	readkey ();

//	destroy_bitmap ( buffer );
	destroy_bitmap ( back );
	destroy_bitmap (back2);
	destroy_bitmap ( girl );
	destroy_bitmap ( serifu );
	destroy_bitmap ( boy );
	destroy_bitmap (seri);
	destroy_bitmap (seri2);
	destroy_bitmap (back3);		
	destroy_bitmap (back4);
	destroy_sample (bgm1);
	destroy_sample (bgm2);
	destroy_sample (chime);
	destroy_sample (bell);
/*********************************************************************************************/
/**************************************主程式之文子的部分↑***********************************/
/*********************************************************************************************/


/*********************************************************************************************/
/**************************************主程式之宜洵的部分↓***********************************/
/*********************************************************************************************/

//	buffer = create_bitmap ( SCREEN_W, SCREEN_H );/*圖檔匯入*/
	buffer2 = create_bitmap ( SCREEN_W, SCREEN_H );
	BigMap = create_bitmap ( SCREEN_W, SCREEN_H );
	Girl = create_bitmap ( 320 , 480 );
	Boy = create_bitmap ( 320 , 480 );
	Other = create_bitmap ( 320 , 480 );
	Face = create_bitmap ( 156 , 156 );
	CubeChoose = create_bitmap ( 500 , 208 );;

	BigMap_4 = load_bitmap ("MAP/MAP-4.bmp" , NULL );
	BigMap_4_1 = load_bitmap ("MAP/MAP-4-1.bmp" , NULL );
	BigMap_4_2 = load_bitmap ("MAP/MAP-4-2.bmp" , NULL );
	BigMap_4_3 = load_bitmap ("MAP/MAP-4-3.bmp" , NULL );
	BigMap_5 = load_bitmap ("MAP/MAP-5.bmp" , NULL );
	BigMap_5_1 = load_bitmap ("MAP/MAP-5-1.bmp" , NULL );
	BigMap_5_2 = load_bitmap ("MAP/MAP-5-2.bmp" , NULL );
	BigMap_5_3_1 = load_bitmap ("MAP/MAP-5-3-1.bmp" , NULL );
	BigMap_5_3_2 = load_bitmap ("MAP/MAP-5-3-2.bmp" , NULL );
	BigMap_6_1 = load_bitmap ("MAP/MAP-6-1.bmp" , NULL );
	BigMap_6_2 = load_bitmap ("MAP/MAP-6-2.bmp" , NULL );
	BigMap_6_3 = load_bitmap ("MAP/MAP-6-3.bmp" , NULL );
	BigMap_7 = load_bitmap ("MAP/MAP-7.bmp" , NULL );
	BigMap_7_1 = load_bitmap ("MAP/MAP-7-1.bmp" , NULL );
	BigMap_7_2 = load_bitmap ("MAP/MAP-7-2.bmp" , NULL );
	BigMap_7_3 = load_bitmap ("MAP/MAP-7-3.bmp" , NULL );
	BigMap_7_4 = load_bitmap ("MAP/MAP-7-4.bmp" , NULL );

	Girl1_4 = load_bitmap ("CHARACTER/Girl/Girl-4.bmp" , NULL );
	Girl1_5 = load_bitmap ("CHARACTER/Girl/Girl-5.bmp" , NULL );
	Girl1_6_1 = load_bitmap ("CHARACTER/Girl/Girl-6.1.bmp" , NULL );
	Girl1_6_2 = load_bitmap ("CHARACTER/Girl/Girl-6.2.bmp" , NULL );
	Girl1_7 = load_bitmap ("CHARACTER/Girl/Girl-7.bmp" , NULL );

	Other_1 = load_bitmap ("CHARACTER/Other/Girl_For_4.bmp" , NULL );
	Other_2 = load_bitmap ("CHARACTER/Other/A.bmp" , NULL );
	Other_3 = load_bitmap ("CHARACTER/Other/B.bmp" , NULL );
	Other_4 = load_bitmap ("CHARACTER/Other/C.bmp" , NULL );

	Boy1_4 = load_bitmap ("CHARACTER/Boy1/No.1-4.bmp" , NULL );
	Boy2_4 = load_bitmap ("CHARACTER/Boy2/No.2-4.bmp" , NULL );
	Boy3_4 = load_bitmap ("CHARACTER/Boy3/No.3-4.bmp" , NULL );
	Boy1_5 = load_bitmap ("CHARACTER/Boy1/No.1-5.bmp" , NULL );
	Boy2_5 = load_bitmap ("CHARACTER/Boy2/No.2-5.bmp" , NULL );
	Boy3_5 = load_bitmap ("CHARACTER/Boy3/No.3-5.bmp" , NULL );
	Boy1_6_1 = load_bitmap ("CHARACTER/Boy1/No.1-6.1.bmp" , NULL );
	Boy2_6_1 = load_bitmap ("CHARACTER/Boy2/No.2-6.1.bmp" , NULL );
	Boy3_6_1 = load_bitmap ("CHARACTER/Boy3/No.3-6.1.bmp" , NULL );
	Boy1_6_2 = load_bitmap ("CHARACTER/Boy1/No.1-6.2.bmp" , NULL );
	Boy2_6_2 = load_bitmap ("CHARACTER/Boy2/No.2-6.2.bmp" , NULL );
	Boy3_6_2 = load_bitmap ("CHARACTER/Boy3/No.3-6.2.bmp" , NULL );
	Boy1_7 = load_bitmap ("CHARACTER/Boy1/No.1-7.bmp" , NULL );
	Boy2_7 = load_bitmap ("CHARACTER/Boy2/No.2-7.bmp" , NULL );
	Boy3_7 = load_bitmap ("CHARACTER/Boy3/No.3-7.bmp" , NULL );

	Bleak = load_bitmap ("MAP/Bleak.bmp" , NULL );
	HandChoose = load_bitmap ("Hand_Choose.bmp" , NULL );
	CubeChoose1 = load_bitmap ("Cube_Choose.bmp" , NULL );

	Music4 = load_sample( "VOICE/4.wav" ); /* load the sound file */
	Music4_1 = load_sample( "VOICE/4-1.wav" ); 
	Music4_2 = load_sample( "VOICE/4-2.wav" ); 
	Music4_3= load_sample( "VOICE/4-3.wav" ); 
	Music4_4= load_sample( "VOICE/4-4.wav" ); 
	Music5 = load_sample( "VOICE/5.wav" ); 
	Music5_1 = load_sample( "VOICE/5-1.wav" ); 
	Music5_2 = load_sample( "VOICE/5-2.wav" ); 
	Music5_3 = load_sample( "VOICE/5-3.wav" ); 
	Music5_4 = load_sample( "VOICE/5-4.wav" ); 
	Music5_5 = load_sample( "VOICE/5-5.wav" ); 
	Music6 = load_sample( "VOICE/6.wav" ); 
	Music6_1 = load_sample( "VOICE/6-1.wav" ); 
	Music6_2 = load_sample( "VOICE/6-2.wav" ); 
	Music6_3 = load_sample( "VOICE/6-3.wav" ); 
	Music7 = load_sample( "VOICE/7.wav" ); 
	Music7_1 = load_sample( "VOICE/7-1.wav" ); 
	Music7_2 = load_sample( "VOICE/7-2.wav" ); 
	Music7_3 = load_sample( "VOICE/7-3.wav" ); 
	Music7_4 = load_sample( "VOICE/7-4.wav" ); 
	Music7_5 = load_sample( "VOICE/7-5.wav" ); 	


	int i;
	int like[3]={0};/*好感度*/
	i = Chap_Four ();
	like[i] = like[i] + 1;
	i = Chap_Fifth ();
	like[i] = like[i] + 1;
	i = Chap_Sixth ();
	like[i] = like[i] + 1;
	i = Chap_Seven ( i, like[i] );
//	like[i] = like[i] + 1;
/****************************************************************/


/****************************************************************/


/****************************************************************/
/*destroy_bitmap (Bleak);
destroy_bitmap (HandChoose);
destroy_bitmap (CubeChoose);
destroy_bitmap (CubeChoose1);

 destroy_bitmap (buffer);
destroy_bitmap (buffer2);
destroy_bitmap (buffer2);
destroy_bitmap (BigMap);
destroy_bitmap (Girl);
destroy_bitmap (Other);
destroy_bitmap (Boy);
destroy_bitmap (Face);

destroy_bitmap (BigMap_4);
destroy_bitmap (BigMap_4_1);
destroy_bitmap (BigMap_4_2);
destroy_bitmap (BigMap_4_3);
destroy_bitmap (Girl1_4);
destroy_bitmap (Boy1_4);
destroy_bitmap (Boy2_4);
destroy_bitmap (Boy3_4);
destroy_sample (Music4);
destroy_sample (Music4_1);
destroy_sample (Music4_2);
destroy_sample (Music4_2);
destroy_sample (Music4_3);

destroy_bitmap (BigMap_5);
destroy_bitmap (BigMap_5_1);
destroy_bitmap (BigMap_5_2);
destroy_bitmap (BigMap_5_3_1);
destroy_bitmap (BigMap_5_3_2);
destroy_bitmap (Girl1_5);
destroy_bitmap (Boy1_5);
destroy_bitmap (Boy2_5);
destroy_bitmap (Boy3_5);
destroy_bitmap (Other_1);
destroy_sample (Music5);
destroy_sample (Music5_1);
destroy_sample (Music5_2);
destroy_sample (Music5_3);
destroy_sample (Music5_4);
destroy_sample (Music5_5);

destroy_bitmap (BigMap_6_1);
destroy_bitmap (BigMap_6_2);
destroy_bitmap (BigMap_6_3);
destroy_bitmap (Girl1_6_1);
destroy_bitmap (Girl1_6_2);
destroy_bitmap (Boy1_6_1);
destroy_bitmap (Boy1_6_2);
destroy_bitmap (Boy2_6_1);
destroy_bitmap (Boy2_6_2);
destroy_bitmap (Boy3_6_1);
destroy_bitmap (Boy3_6_2);
destroy_bitmap (Other_2);
destroy_bitmap (Other_3);
destroy_bitmap (Other_4);
destroy_sample (Music6);
destroy_sample (Music6_1);
destroy_sample (Music6_2);
destroy_sample (Music6_3);


destroy_bitmap (BigMap_7);
destroy_bitmap (BigMap_7_1);
destroy_bitmap (BigMap_7_2);
destroy_bitmap (BigMap_7_3);
destroy_bitmap (BigMap_7_4);
destroy_bitmap (Girl1_7);
destroy_bitmap (Boy1_7);
destroy_bitmap (Boy2_7);
destroy_bitmap (Boy3_7);
destroy_bitmap (Boy);
destroy_bitmap (Boy);
destroy_bitmap (Boy);
destroy_sample (Music7);
destroy_sample (Music7_1);
destroy_sample (Music7_2);
destroy_sample (Music7_3);
destroy_sample (Music7_4);
destroy_sample (Music7_5);
*/



	close_Cfont();
	allegro_exit();
	

/*********************************************************************************************/
/**************************************主程式之宜洵的部分↑***********************************/
/*********************************************************************************************/

	return 0;
}
END_OF_MAIN ();

/*********************************************************************************************/
/*********************************************************************************************/
/**************************************文子的部分↓*******************************************/
/*********************************************************************************************/
/*********************************************************************************************/

/*function area*/


volatile int boy_to_left ( int boyX )/*boy move to left*/
{
	play_sample(chime, 128, 128, 1000, 0);
	while ( boyX <= lift )
	{
		boyX = boyX + 1;
		blit ( back, buffer, 0, 0, 0, 0, 640, 480 );
		blit ( boy, buffer, 0, 0, boyX, 0, boy->w, boy->h );
		blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
		blit(girl, buffer, 0, 0, 0, 360, 120, 120);
		blit(seri, buffer, 0, 0, 130, 370, 500, 100);
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
	}

	while ( boyX >= lift )
	{
		boyX = boyX -1;
		blit ( back, buffer, 0, 0, 0, 0, 640, 480 );
		blit ( boy, buffer, 0, 0, boyX, 0, boy->w, boy->h );
		blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
		blit(girl, buffer, 0, 0, 0, 360, 120, 120);
		blit(seri, buffer, 0, 0, 130, 370, 500, 100);
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
	}
	return boyX;
}

/*Chapter1 dialogue*/
int chap1(int serifu_y)
{
	int a;


		for(a=0; a<=190;)
		{
			if(key[KEY_SPACE])
			{
				serifu_y+=28;
				a=serifu_y;
				blit ( back, buffer, 0, 0, 0, 0, 640, 480 );
				blit ( boy, buffer, 0, 0, 54, 0, boy->w, boy->h );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(girl, buffer, 0, 0, 0, 360, 120, 120);
				blit(seri, buffer, 0, a, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return a;
}

int only_b(int serifu_y2)
{
	int b;

		for(b=0; b<=28;)
		{
			if(key[KEY_SPACE])
			{
				serifu_y2+=28;
				b=serifu_y2;
				blit ( back, buffer, 0, 0, 0, 0, 640, 480 );
				blit ( boy, buffer, 0, 0, 54, 0, boy->w, boy->h );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(seri, buffer, 0, 190+b, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return b;
}

int only_g(int serifu_y3)
{
	int c;

		for(c=0; c<=80;)
		{
			if(key[KEY_SPACE])
			{
				serifu_y3+=28;
				c=serifu_y3;
				blit ( back, buffer, 0, 0, 0, 0, 640, 480 );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(girl, buffer, 0, 0, 0, 360, 120, 120);
				blit(seri, buffer, 0, 245+c, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return c;
}

int class_r(int serifu_c)
{
	int d;

		for(d=0; d<=80;)
		{
			if(key[KEY_SPACE])
			{
				serifu_c+=28;
				d=serifu_c;
				play_sample(door, 80, 128, 1000, 0);
				stop_sample(door);
				//blit ( back2 , buffer, 0, 0, 0, 0, 640, 480 );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(seri, buffer, 0, 325+d, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return d;
}

int class_r2(int serifu_c2)
{
	int e;

		for(e=0; e<=532;)
		{
			if(key[KEY_SPACE])
			{
				serifu_c2+=28;
				e=serifu_c2;
				blit ( back2, buffer, 0, 0, 0, 0, 640, 480 );
				blit ( boy, buffer, 0, 0, 266, 0, boy->w, boy->h );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(girl, buffer, 0, 0, 0, 360, 120, 120);
				blit(seri, buffer, 0, 405+e, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}

	stop_sample(bgm1);					/*stop the bgm1*/
	return e;
}

/*function area*/

/*Chapter2 dialogue*/
int saten(int serifu_yy)
{
	int a;
		for(a=0; a<=80;)
		{
			if(key[KEY_SPACE])
			{
				serifu_yy+=28;
				a=serifu_yy;
				blit ( back3, buffer, 0, 0, 0, 0, 640, 480 );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(girl, buffer, 0, 0, 0, 360, 120, 120);
				blit(seri2, buffer, 0, a-22, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	play_sample(bell, 255, 128, 1000, 0);
	return a;
}

int saten2(int serifu_yy2)
{
	int b;

		for(b=0; b<=56;)
		{
			if(key[KEY_SPACE])
			{
				serifu_yy2+=28;
				b=serifu_yy2;
				blit ( back3, buffer, 0, 0, 0, 0, 640, 480 );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(seri2, buffer, 0, 70+b, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return b;
}

int saten3(int serifu_yy3)
{
	int c;

		for(c=0; c<=448;)
		{
			if(key[KEY_SPACE])
			{
				serifu_yy3+=28;
				c=serifu_yy3;
				blit ( back3, buffer, 0, 0, 0, 0, 640, 480 );
				blit(boy, buffer, 0, 0, 266, 0, boy->w, boy->h);
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(girl, buffer, 0, 0, 0, 360, 120, 120);
				blit(seri2, buffer, 0, 160+c, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return c;
}

int saten4(int serifu_yy4)
{
	int d;
	play_sample(bell, 255, 128, 1000, 0);
		for(d=28; d<=56;)
		{
			if(key[KEY_SPACE])
			{

				serifu_yy4+=28;
				d=serifu_yy4;
				blit ( back4 , buffer, 0, 0, 0, 0, 640, 480 );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(girl, buffer, 0, 0, 0, 360, 120, 120);
				blit(seri2, buffer, 0, 670+d, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return d;
}

int saten5(int serifu_yy5)
{
	int e;
		for(e=0; e<=340;)
		{
			if(key[KEY_SPACE])
			{
				serifu_yy5+=28;
				e=serifu_yy5;
				blit ( back4, buffer, 0, 0, 0, 0, 640, 480 );
				blit ( boy, buffer, 0, 0, 266, 0, boy->w, boy->h );
				blit(serifu, buffer, 0, 0, 0, 360, buffer->w, buffer->h);
				blit(girl, buffer, 0, 0, 0, 360, 120, 120);
				blit(seri2, buffer, 0, 720+e, 130, 370, 500, 100);
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
			}
		readkey();
		}
	return e;
}

/*********************************************************************************************/
/*********************************************************************************************/
/**************************************文子的部分↑*******************************************/
/*********************************************************************************************/
/*********************************************************************************************/



/*********************************************************************************************/
/*********************************************************************************************/
/**************************************宜洵的部分↓*******************************************/
/*********************************************************************************************/
/*********************************************************************************************/

void ChangFace ( int n , int i , int j)/*變臉圖，n=人，i=幕，j=張(第六幕才需要)*/
{
	FaceG1_4 = load_bitmap ("Face/Girl/fgirl-4.bmp" , NULL );
	FaceB1_4 = load_bitmap ("Face/Boy1/fno.1-4.bmp" , NULL );
	FaceB2_4 = load_bitmap ("Face/Boy2/fno.2-4.bmp" , NULL );
	FaceB3_4 = load_bitmap ("Face/Boy3/fno.3-4.bmp" , NULL );
	FaceG1_5 = load_bitmap ("Face/Girl/fgirl-5.bmp" , NULL );
	FaceB1_5 = load_bitmap ("Face/Boy1/fno.1-5.bmp" , NULL );
	FaceB2_5 = load_bitmap ("Face/Boy2/fno.2-5.bmp" , NULL );
	FaceB3_5 = load_bitmap ("Face/Boy3/fno.3-5.bmp" , NULL );
	FaceG1_6_1 = load_bitmap ("Face/Girl/fgirl-6.1.bmp" , NULL );
	FaceB1_6_1 = load_bitmap ("Face/Boy1/fno.1-6.1.bmp" , NULL );
	FaceB2_6_1 = load_bitmap ("Face/Boy2/fno.2-6.1.bmp" , NULL );
	FaceB3_6_1 = load_bitmap ("Face/Boy3/fno.3-6.1.bmp" , NULL );
	FaceG1_6_2 = load_bitmap ("Face/Girl/fgirl-6.2.bmp" , NULL );
	FaceB1_6_2 = load_bitmap ("Face/Boy1/fno.1-6.2.bmp" , NULL );
	FaceB2_6_2 = load_bitmap ("Face/Boy2/fno.2-6.2.bmp" , NULL );
	FaceB3_6_2 = load_bitmap ("Face/Boy3/fno.3-6.2.bmp" , NULL );
	FaceG1_7 = load_bitmap ("Face/Girl/fgirl-7.bmp" , NULL );
	FaceB1_7 = load_bitmap ("Face/Boy1/fno.1-7.bmp" , NULL );
	FaceB2_7 = load_bitmap ("Face/Boy2/fno.2-7.bmp" , NULL );
	FaceB3_7 = load_bitmap ("Face/Boy3/fno.3-7.bmp" , NULL );

	FaceOther_1 = load_bitmap ("Face/Other/fgirl_for_4.bmp" , NULL );
	FaceOther_2 = load_bitmap ("Face/Other/fa.bmp" , NULL );
	FaceOther_3 = load_bitmap ("Face/Other/fb.bmp" , NULL );
	FaceOther_4 = load_bitmap ("Face/Other/fc.bmp" , NULL );

	if ( n == -1 && i == -1 && j == -1 )
	{
		clear_bitmap( Face );
	}
	if ( n == 0 )
	{
		if ( i == 4 )
		{blit ( FaceG1_4, Face, 0, 0, 0, 0, FaceG1_4->w, FaceG1_4->h );}
		if ( i == 5 )
		{blit ( FaceG1_5, Face, 0, 0, 0, 0, FaceG1_5->w, FaceG1_5->h );}
		if ( i == 6)
		{
			if ( j == 1 )
			{blit ( FaceG1_6_1, Face, 0, 0, 0, 0, FaceG1_6_1->w, FaceG1_6_1->h );}
			if ( j == 2 )
			{blit ( FaceG1_6_2, Face, 0, 0, 0, 0, FaceG1_6_2->w, FaceG1_6_2->h );}
		}
		if ( i == 7 )
		{blit ( FaceG1_7, Face, 0, 0, 0, 0, FaceG1_7->w, FaceG1_7->h );}

	}
	if ( n == 1 )
	{
		if ( i == 4 )
		{blit ( FaceB1_4, Face, 0, 0, 0, 0, FaceB1_4->w, FaceB1_4->h );}
		if ( i == 5 )
		{blit ( FaceB1_5, Face, 0, 0, 0, 0, FaceB1_5->w, FaceB1_5->h );}
		if ( i == 6)
		{
			if ( j == 1 )
			{blit ( FaceB1_6_1, Face, 0, 0, 0, 0, FaceB1_6_1->w, FaceB1_6_1->h );}
			if ( j == 2 )
			{blit ( FaceB1_6_2, Face, 0, 0, 0, 0, FaceB1_6_2->w, FaceB1_6_2->h );}
		}
		if ( i == 7 )
		{blit ( FaceB1_7, Face, 0, 0, 0, 0, FaceB1_7->w, FaceB1_7->h );}
	}
	if (n == 2 )
	{
		if ( i == 4 )
		{blit ( FaceB2_4, Face, 0, 0, 0, 0, FaceB2_4->w, FaceB2_4->h );}
		if ( i == 5 )
		{blit ( FaceB2_5, Face, 0, 0, 0, 0, FaceB2_5->w, FaceB2_5->h );}
		if ( i == 6)
		{
			if ( j == 1 )
			{blit ( FaceB2_6_1, Face, 0, 0, 0, 0, FaceB2_6_1->w, FaceB2_6_1->h );}
			if ( j == 2 )
			{blit ( FaceB2_6_2, Face, 0, 0, 0, 0, FaceB2_6_2->w, FaceB2_6_2->h );}
		}
		if ( i == 7 )
		{blit ( FaceB2_7, Face, 0, 0, 0, 0, FaceB2_7->w, FaceB2_7->h );}
	}
	if (n == 3 )
	{
		if ( i == 4 )
		{blit ( FaceB3_4, Face, 0, 0, 0, 0, FaceB3_4->w, FaceB3_4->h );}
		if ( i == 5 )
		{blit ( FaceB3_5, Face, 0, 0, 0, 0, FaceB3_5->w, FaceB3_5->h );}
		if ( i == 6)
		{
			if ( j == 1 )
			{blit ( FaceB3_6_1, Face, 0, 0, 0, 0, FaceB3_6_1->w, FaceB3_6_1->h );}
			if ( j == 2 )
			{blit ( FaceB3_6_2, Face, 0, 0, 0, 0, FaceB3_6_2->w, FaceB3_6_2->h );}
		}
		if ( i == 7 )
		{blit ( FaceB3_7, Face, 0, 0, 0, 0, FaceB3_7->w, FaceB3_7->h );}
	}
	if ( n == 4 )
	{
		if ( i == 1)
		{blit ( FaceOther_1, Face, 0, 0, 0, 0, FaceOther_1->w, FaceOther_1->h );}
		if ( i == 2)
		{blit ( FaceOther_2, Face, 0, 0, 0, 0, FaceOther_2->w, FaceOther_2->h );}
		if ( i == 3)
		{blit ( FaceOther_3, Face, 0, 0, 0, 0, FaceOther_3->w, FaceOther_3->h );}
		if ( i == 4)
		{blit ( FaceOther_4, Face, 0, 0, 0, 0, FaceOther_4->w, FaceOther_4->h );}
	}
destroy_bitmap (FaceG1_4);
destroy_bitmap (FaceB1_4);
destroy_bitmap (FaceB2_4);
destroy_bitmap (FaceB3_4);
destroy_bitmap (FaceG1_5);
destroy_bitmap (FaceB1_5);
destroy_bitmap (FaceB2_5);
destroy_bitmap (FaceB3_5);
destroy_bitmap (FaceOther_1);
destroy_bitmap (FaceG1_6_1);
destroy_bitmap (FaceG1_6_2);
destroy_bitmap (FaceB1_6_1);
destroy_bitmap (FaceB1_6_2);
destroy_bitmap (FaceB2_6_1);
destroy_bitmap (FaceB2_6_2);
destroy_bitmap (FaceB3_6_1);
destroy_bitmap (FaceB3_6_2);
destroy_bitmap (FaceOther_2);
destroy_bitmap (FaceOther_3);
destroy_bitmap (FaceOther_4);
destroy_bitmap (FaceG1_7);
destroy_bitmap (FaceB1_7);
destroy_bitmap (FaceB2_7);
destroy_bitmap (FaceB3_7);
}
void PutFace ()
{

	BITMAP *Face2= create_bitmap ( 156 , 156 );;
	BITMAP *Speak = load_bitmap ("SPEAK.bmp" , NULL );

	int i,j;

//	blit ( BigMap, buffer2, 0, 0, 0, 0, 640, 480 );
	blit ( Speak, buffer2, 0, 0, 0, 480 - 156, Speak->w, Speak->h );
	blit ( buffer2, Face2, 36, 480 - 156, 0, 0, Face2->w, Face2->h );
	for( i = 0; i < Face2->h; i++ )
	{
		for( j = 0; j < Face2->w*3; j=j+3 )
		{
			if( Face->line[i][j] == 0 && Face->line[i][j+1] == 0 && Face->line[i][j+2] == 0 )
			{
				Face->line[i][j] = Face2->line[i][j];
				Face->line[i][j+1] = Face2->line[i][j+1];
				Face->line[i][j+2] = Face2->line[i][j+2];
			}
		}
	}
	blit ( Face, screen, 0, 0, 0, 480 - 156, buffer->w, buffer->h );
	clear_bitmap( buffer2 );
	destroy_bitmap (Face2);
	destroy_bitmap (Speak);
}

/**************************************************************************************/
/**************************************************************************************/
void Start ()
{
	blit ( BigMap, buffer, 0, 0, 0, 0, 640, 480 );
	blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
	blit ( buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h );
	clear_bitmap( buffer );
}

int GirlMove ( int GirlX1, int GirlX2, int BoyX1, int n )
{
	blit ( BigMap, buffer2, 0, 0, 0, 0, 640, 480 );

	while ( GirlX1 != GirlX2 )
	{
		if ( GirlX1 <= GirlX2 - 1 )
		{GirlX1 = GirlX1 + 1;}
		if ( GirlX1 >= GirlX2 + 1 )
		{GirlX1 = GirlX1 - 1;}

		blit ( BigMap, buffer, 0, 0, 0, 0, 640, 480 );

		blit ( Boy, buffer, 0, 0, BoyX1, 0, Boy->w, Boy->h );
		BleakColor ();
		blit ( buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h );
		blit ( Girl, buffer, 0, 0, GirlX1, 0, Girl->w, Girl->h );
		BleakColor ();
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
	}
	if ( n == 0 )
	{while (!key[KEY_SPACE]){}}
	clear_bitmap( buffer2 );
	return GirlX1;
}

int BoyMove ( int BoyX1, int BoyX2, int GirlX1, int n )
{
	blit ( BigMap, buffer2, 0, 0, 0, 0, 640, 480 );

	while ( BoyX1 != BoyX2 )
	{
		if ( BoyX1 <= BoyX2 - 1 )
		{BoyX1 = BoyX1 + 1;}
		if ( BoyX1 >= BoyX2 + 1 )
		{BoyX1 = BoyX1 - 1;}

		blit ( BigMap, buffer, 0, 0, 0, 0, 640, 480 );
		blit ( Girl, buffer, 0, 0, GirlX1, 0, Girl->w, Girl->h );
		BleakColor ();
		blit ( buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h );
		blit ( Boy, buffer, 0, 0, BoyX1, 0, Boy->w, Boy->h );
		BleakColor ();
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
	}
	clear_bitmap( buffer2 );

	if ( n == 0 )
	{while (!key[KEY_SPACE]){}}
	return BoyX1;
}

int appear ( int X, int X1, int n )
{
	blit ( BigMap, buffer2, 0, 0, 0, 0, 640, 480 );

	if ( n==0 )/*女生*/
	{
		blit ( BigMap, buffer, 0, 0, 0, 0, 640, 480 );
		blit ( buffer, buffer2, 0, 0, 0, 0, 640, 480 );
		blit ( Boy, buffer, 0, 0, X1, 0, Boy->w, Boy->h );
		BleakColor ();
		blit ( buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h );
		blit ( Girl, buffer, 0, 0, X, 0, Girl->w, Girl->h );
		BleakColor ();
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
	}
	if ( n==1 )/*男生*/
	{
		blit ( BigMap, buffer, 0, 0, 0, 0, 640, 480 );
		blit ( buffer, buffer2, 0, 0, 0, 0, 640, 480 );
		blit ( Girl, buffer, 0, 0, X1, 0, Girl->w, Girl->h );
		BleakColor ();
		blit ( buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h );
		blit ( Boy, buffer, 0, 0, X, 0, Boy->w, Boy->h );
		BleakColor ();
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
	}
	clear_bitmap( buffer2 );
	while (!key[KEY_SPACE]){}
	return X;
}
int SixForOther ( int BoyX1, int GirlX1,int OtherX1)
{
	blit ( BigMap, buffer, 0, 0, 0, 0, 640, 480 );
	blit ( buffer, buffer2, 0, 0, 0, 0, 640, 480 );
	blit ( Boy, buffer, 0, 0, BoyX1, 0, Boy->w, Boy->h );
	BleakColor ();
	blit ( buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h );
	blit ( Girl, buffer, 0, 0, GirlX1, 0, Girl->w, Girl->h );
	BleakColor ();
	blit ( buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h );
	blit ( Other, buffer, 0, 0, OtherX1, 0, Other->w, Other->h );
	BleakColor ();
	blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
	clear_bitmap( buffer );
	clear_bitmap( buffer2 );
	while (!key[KEY_SPACE]){}

		return OtherX1;
}

void BleakColor ()	/*消去背景*/
{
	int i,j;
	for( i = 0; i < buffer->h; i++ )
	{
		for( j = 0; j < buffer->w*3; j=j+3 )
		{
			if( buffer->line[i][j] == 0 && buffer->line[i][j+1] == 0 && buffer->line[i][j+2] == 0 )
			{
				buffer->line[i][j] = buffer2->line[i][j];
				buffer->line[i][j+1] = buffer2->line[i][j+1];
				buffer->line[i][j+2] = buffer2->line[i][j+2];
			}
		}
	}
}


int ChooseToStory (int i)
{
	Bleak = load_bitmap ("MAP/Bleak.bmp" , NULL );
	HandChoose = load_bitmap ("Hand_Choose.bmp" , NULL );
	CubeChoose1 = load_bitmap ("Cube_Choose.bmp" , NULL );

	int n = 48;
	blit ( Bleak, buffer, 0, 0, 0, 0, Bleak->w, Bleak->h );
	blit ( Bleak, buffer2, 0, 0, 0, 0, Bleak->w, Bleak->h );

	while ( !key[KEY_ENTER] )
	{
		blit ( CubeChoose1, buffer, 0, (i-4)*207, 112, 48, CubeChoose->w, 208 );
		blit ( HandChoose, buffer, 256-64, 0, 48, n, 64, HandChoose->h );
		BleakColor ();
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
		if (key[KEY_Z])
		{n = ONE;}
		else if (key[KEY_X])
		{n=TWO;}
		else if (key[KEY_C])
		{n=THREE;}
	}
	if (n == ONE)
	{n = 1;}
	if (n == TWO)
	{n = 2;}
	if (n == THREE)
	{n = 3;}
	return n;
}

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
int Chap_Four ()/*第四幕開始*/
{
	int GirlX;
	int n,i;

	play_sample( Music4, 255, 0, 1000, 1);

	blit ( BigMap_4, BigMap, 0, 0, 0, 0, BigMap_4->w, BigMap_4->h );
	blit ( Girl1_4, Girl, 0, 0, 0, 0, Girl1_4->w, Girl1_4->h );

	Start ();
	
	GirlX = GirlMove ( 640, MIDDLE, 640, 1 );
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 119);
	n = ChooseToStory (4);	/*n=選項*/
	GirlX = appear ( MIDDLE, 640, 0 );
	switch (n)
	{
		case 3:/*英杰篇*/
			Print_words( 200, 255, 0, 0, 27);/*千語說話(第一句)*/
			stop_sample(Music4);
			i = Chap_Four_One ();
			break;
		case 1:/*李昱篇*/
			Print_words( 200, 255, 0, 0, 0);/*千語說話(第一句)*/
			stop_sample(Music4);
			i = Chap_Four_Two ();
			break;
		case 2:/*洛維篇*/
			Print_words( 200, 255, 0, 0, 15);/*千語說話(第一句)*/
			stop_sample(Music4);
			i = Chap_Four_Three ();
			break;
	}


	return i;
}/*第四幕結束*/

int Chap_Four_One ()/*第四幕英杰篇*/
{
	int BoyX, GirlX;

	play_sample( Music4_1, 255, 0, 1000, 1);

	blit ( BigMap_4_1, BigMap, 0, 0, 0, 0, BigMap_4_1->w, BigMap_4_1->h );
	blit ( Boy1_4, Boy, 0, 0, 0, 0, Boy1_4->w, Boy1_4->h );

	GirlX = GirlMove ( 640, RIGHT, 640, 0 );
	BoyX = appear ( LIFT, GirlX, 1 );
	ChangFace ( 1, 4, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 28);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 29);
	ChangFace ( 1, 4, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 30);
	BoyX = 	BoyMove ( BoyX, RIGHT+160, GirlX ,0 );
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 31);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 32);
	ChangFace ( 1, 4, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 33);

	BoyX = 	BoyMove ( BoyX, LIFT, GirlX ,0 );
	GirlX = GirlMove ( GirlX, RIGHT+25, BoyX, 1 );
	GirlX = GirlMove ( GirlX, RIGHT-25, BoyX, 0 );/*揮棒*/
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 34);
	ChangFace ( 1, 4, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 35);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 36);
	stop_sample(Music4_1);


/*第四幕英杰篇結束*/
	return 0;
}
int Chap_Four_Two ()/*第四幕李昱篇*/
{

	int BoyX, GirlX;
	play_sample( Music4_2, 255, 0, 1000, 1);

	blit ( BigMap_4_2, BigMap, 0, 0, 0, 0, BigMap_4_2->w, BigMap_4_2->h );
	blit ( Boy2_4, Boy, 0, 0, 0, 0, Boy2_4->w, Boy2_4->h );

	BoyX = appear ( MIDDLE, 640, 1 );
	ChangFace ( 2, 4, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 1);
	BoyX = 	BoyMove ( BoyX, LIFT, 640 , 0 );
	GirlX = GirlMove ( 640, RIGHT, BoyX, 0 );
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 2);
	ChangFace ( 2, 4, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 3);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 4);
	BoyX = 	BoyMove ( BoyX, GirlX-160, GirlX, 1 );
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 5);
	while ( BoyX >=0)/*李昱強拉千語*/
	{
		BoyX = 	BoyMove ( BoyX, BoyX -5, GirlX, 1 );
		GirlX = GirlMove ( GirlX, GirlX -5, BoyX, 1 );
	}
	BoyX = 	640 - 160 ;
	GirlX = 640;
	while ( BoyX >= MIDDLE )/*李昱強拉千語*/
	{
		BoyX = 	BoyMove ( BoyX, BoyX -5, GirlX, 1 );
		GirlX = GirlMove ( GirlX, GirlX -5, BoyX, 1 );
	}

	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 6);
	ChangFace ( 2, 4, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 7);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 8);
	ChangFace ( 2, 4, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 9);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 10);
	ChangFace ( 2, 4, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 11);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 12);
	ChangFace ( 2, 4, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 13);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 14);

	stop_sample(Music4_2);

/*第四幕李昱篇結束*/
	return 1;
}
int Chap_Four_Three ()/*第四幕洛維篇*/
{
	int BoyX, GirlX;


	play_sample( Music4_3, 255, 0, 1000, 1);

	blit ( BigMap_4_3, BigMap, 0, 0, 0, 0, BigMap_4_3->w, BigMap_4_3->h );
	blit ( Boy3_4, Boy, 0, 0, 0, 0, Boy3_4->w, Boy3_4->h );

	GirlX = GirlMove ( 640, MIDDLE, 640, 0 );
	Print_words( 200, 255, 0, 0, 16);/*千語說話*/
	play_sample( Music4_4, 255, 0, 1000, 0);
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 0, 255, 255, 17);/*我好恨*/
	Print_words( 200, 255, 255, 0, 18);
	GirlX = GirlMove ( GirlX, 0 - 320, 640, 1 );/*嚇的跑來跑去*/
	GirlX = GirlMove ( GirlX, 640, 640, 1 );
	BoyX = appear ( MIDDLE, 640, 1 );
	GirlX = GirlMove ( GirlX, MIDDLE, BoyX, 1 );
	GirlX = GirlMove ( GirlX, MIDDLE + 100, BoyX, 1 );/*撞到*/
	GirlX = GirlMove ( GirlX, MIDDLE + 50, BoyX, 0 );
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 19);
	ChangFace ( 3, 4, 0);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 20);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 255, 255, 21);
	GirlX = GirlMove ( GirlX, MIDDLE + 100, BoyX, 1 );
	GirlX = GirlMove ( GirlX, MIDDLE + 50, BoyX, 0 );
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 22);
	Print_words( 200, 255, 0, 0, 23);/*千語說話*/
	ChangFace ( 3, 4, 0);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 24);
	ChangFace ( 0, 4, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 25);

	stop_sample(Music4_3);


/*第四幕洛維篇結束*/
	return 2;
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
int Chap_Fifth ()/*第五幕開始*/
{
	int GirlX, BoyX;
	int n,i;
	play_sample( Music5, 255, 0, 1000, 1);

	blit ( BigMap_5, BigMap, 0, 0, 0, 0, BigMap_5->w, BigMap_5->h );
	blit ( Girl1_5, Girl, 0, 0, 0, 0, Girl1_5->w, Girl1_5->h );

	Start ();

	GirlX = appear ( MIDDLE, 640, 0 );
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 37);
	n = ChooseToStory (5);	/*n=選項*/
	GirlX = appear ( MIDDLE, 640, 0 );

	switch (n)
	{
		case 2:/*英杰篇*/
			GirlX = appear ( MIDDLE, 640, 0 );
			Print_words( 200, 255, 0, 0, 49);/*千語說話*/
			GirlX = GirlMove ( GirlX, 640, 640, 1 );
			stop_sample(Music5);
			i = Chap_Fifth_One ();
			break;
		case 3:/*李昱篇*/
			Print_words( 200, 255, 0, 0, 58);/*千語說話*/
			GirlX = GirlMove ( GirlX, 640, 640, 1 );
			stop_sample(Music5);
			i = Chap_Fifth_Two ();
			break;
		case 1:/*洛維篇*/
			Print_words( 200, 255, 0, 0, 38);/*千語說話*/
			GirlX = GirlMove ( GirlX, 640, 640, 1 );
			stop_sample(Music5);
			i = Chap_Fifth_Three ();
			break;
	}
	stop_sample(Music5_4);
	play_sample( Music5_5, 255, 0, 1000, 1);

	blit ( BigMap_5_2, BigMap, 0, 0, 0, 0, BigMap_5_2->w, BigMap_5_2->h );
	GirlX = GirlMove ( 640, 645, 640, 1 );
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 70);
	blit ( Other_1, Boy, 0, 0, 0, 0, Other_1->w, Other_1->h );/*把校醫當Boy*/
	BoyX = 	appear ( MIDDLE, 640, 1 );
	ChangFace ( 4, 1, 0);/*校醫說話*/
	Print_words( 200, 0, 255, 0, 71);
	BoyX = 	BoyMove ( BoyX, RIGHT , 640 , 0 );
	GirlX = appear ( LIFT, BoyX, 0 );
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 72);
	BoyX = 	appear ( BoyX, GirlX, 1 );
	ChangFace ( 4, 1, 0);/*校醫說話*/
	Print_words( 200, 0, 255, 0, 73);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 74);

	stop_sample(Music5_5);

	return n;
}/*第五幕結束*/
int Chap_Fifth_One ()/*第五幕英杰篇*/
{
	int BoyX, GirlX;
	play_sample( Music5_1, 255, 0, 1000, 1);

	blit ( BigMap_5_1, BigMap, 0, 0, 0, 0, BigMap_5_1->w, BigMap_5_1->h );
	blit ( Boy1_5, Boy, 0, 0, 0, 0, Boy1_5->w, Boy1_5->h );

	BoyX = appear ( RIGHT, 640, 1 );
	ChangFace ( 1, 5, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 50);
	GirlX = GirlMove ( 0 - 320, LIFT, BoyX, 0 );
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 51);
	ChangFace ( 1, 5, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 52);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 53);
	ChangFace ( 1, 5, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 54);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 56);
	stop_sample(Music5_1);
	play_sample( Music5_4, 255, 0, 1000, 1);

	GirlX = GirlMove ( GirlX, GirlX + 10, BoyX, 1 );/*千語暈眩*/
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 55);
	GirlX = GirlMove ( GirlX, GirlX - 20, BoyX, 1 );
	GirlX = GirlMove ( GirlX, GirlX + 10, BoyX, 1 );
	BoyX = 	BoyMove ( BoyX, GirlX + 100 , GirlX , 1 );
	ChangFace ( 1, 5, 0);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 57);

/*第五幕英杰篇結束*/
	return 0;
}
int Chap_Fifth_Two ()/*第五幕李昱篇*/
{
	int BoyX, GirlX;
	play_sample( Music5_2, 255, 0, 1000, 1);

	blit ( BigMap_5_1, BigMap, 0, 0, 0, 0, BigMap_5_1->w, BigMap_5_1->h );
	blit ( Boy2_5, Boy, 0, 0, 0, 0, Boy2_5->w, Boy2_5->h );

	BoyX = appear ( MIDDLE, 640, 1 );
	ChangFace ( 2, 5, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 59);
	BoyX = 	BoyMove ( BoyX, LIFT, 640, 0 );
	GirlX = GirlMove ( 640, RIGHT, BoyX, 0 );
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 60);
	ChangFace ( 2, 5, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 61);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 62);
	ChangFace ( 2, 5, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 63);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 64);
	BoyX = 	BoyMove ( BoyX, 0-320, GirlX, 0 );
	Print_words( 200, 255, 0, 0, 65);/*千語說話*/
	BoyX = 	BoyMove ( BoyX, LIFT, GirlX, 0 );
	ChangFace ( 2, 5, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 66);
	BoyX = 	BoyMove ( BoyX, 640, GirlX, 1 );

	GirlX = GirlMove ( GirlX, 640, BoyX, 0 );
	BoyX = 	BoyMove ( 0 - 320 , MIDDLE, GirlX, 1 );
	GirlX = GirlMove ( 0 - 320 , MIDDLE - 160 , BoyX, 1 );
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 68);
	stop_sample(Music5_2);
	play_sample( Music5_4, 255, 0, 1000, 1);
	GirlX = GirlMove ( GirlX, GirlX + 10, BoyX, 1 );/*千語暈眩*/
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 67);
	GirlX = GirlMove ( 	GirlX, GirlX - 20, BoyX, 1 );
	GirlX = GirlMove ( GirlX, GirlX + 10, BoyX, 1 );
	BoyX = 	BoyMove ( BoyX, GirlX + 100 , GirlX , 1 );
	ChangFace ( 2, 5, 0);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 69);

/*第五幕李昱篇結束*/
	return 1;
}
int Chap_Fifth_Three ()/*第五幕洛維篇*/
{
	int BoyX, GirlX;
	play_sample( Music5_3, 255, 0, 1000, 1);

	blit ( BigMap_5_3_1, BigMap, 0, 0, 0, 0, BigMap_5_3_1->w, BigMap_5_3_1->h );
	blit ( Boy3_5, Boy, 0, 0, 0, 0, Boy3_5->w, Boy3_5->h );

	GirlX = GirlMove ( 640, LIFT, 640, 0 );
	blit ( BigMap_5_3_2, BigMap, 0, 0, 0, 0, BigMap_5_3_2->w, BigMap_5_3_2->h );
	BoyX = 	BoyMove ( 640, RIGHT, GirlX, 0 );
	ChangFace ( 3, 5, 0);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 39);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 40);
	ChangFace ( 3, 5, 0);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 41);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 42);
	ChangFace ( 3, 5, 0);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 43);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 44);
	ChangFace ( 3, 5, 0);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 45);
	ChangFace ( 0, 5, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 46);
	stop_sample(Music5_3);
	play_sample( Music5_4, 255, 0, 1000, 1);


	GirlX = GirlMove ( GirlX, GirlX + 10, BoyX, 1 );/*千語暈眩*/
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 47);
	GirlX = GirlMove ( GirlX, GirlX - 20, BoyX, 1 );
	GirlX = GirlMove ( GirlX, GirlX + 10, BoyX, 1 );
	BoyX = 	BoyMove ( BoyX, GirlX + 100 , GirlX , 1 );
	ChangFace ( 3, 5, 0);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 48);


/*第五幕洛維篇結束*/
	return 2;
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

int Chap_Sixth ()/*第六幕開始*/
{

 	int GirlX, BoyX, OtherX;
	int n,i;
	play_sample( Music6, 255, 0, 1000, 1);

	blit ( BigMap_6_1, BigMap, 0, 0, 0, 0, BigMap_6_1->w, BigMap_6_1->h );
	blit ( Girl1_6_1, Girl, 0, 0, 0, 0, Girl1_6_1->w, Girl1_6_1->h );

	Start ();

	GirlX = appear ( MIDDLE, 640, 0 );
	ChangFace ( 0, 6, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 76);
	GirlX = GirlMove ( GirlX, 0 - 320 , 640, 0 );

	stop_sample(Music6);
	play_sample( Music6_1, 255, 0, 1000, 1);
	blit ( BigMap_6_2, BigMap, 0, 0, 0, 0, BigMap_6_2->w, BigMap_6_2->h );
	GirlX = appear ( LIFT, 640, 0 );/*千語說話*/
	Print_words( 200, 255, 0, 0, 77);
	Print_words( 200, 255, 0, 0, 78);/*千語說話*/

	n = ChooseToStory (6);	/*n=選項*/

	stop_sample(Music6_1);
	play_sample( Music6_2, 255, 0, 1000, 1);

	blit ( Other_2, Boy, 0, 0, 0, 0, Other_2->w, Other_2->h );
	BoyX = 	appear ( 640, 640, 1 );
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 79);
	ChangFace ( 4, 2, 0);/*同學A說話*/
	Print_words( 200, 0, 255, 0, 80);
	ChangFace ( 0, 6, 1);/*千語說話*/
	GirlX =	appear ( MIDDLE, 640, 0 );
	Print_words( 200, 255, 0, 0, 81);
	blit ( FaceOther_2, Face, 0, 0, 0, 0, FaceOther_2->w, FaceOther_2->h );
	BoyX = appear ( MIDDLE, 640, 1 );
	ChangFace ( 4, 2, 0);/*同學A說話*/
	Print_words( 200, 0, 255, 0, 82);
	Print_words( 200, 0, 255, 0, 83);
	blit ( Other_3, Girl, 0, 0, 0, 0, Other_3->w, Other_3->h );
	GirlX = appear ( LIFT - 50, BoyX, 0 );
	ChangFace ( 4, 3, 0);/*同學B說話*/
	Print_words( 200, 0, 255, 0, 84);
	blit ( Other_4, Other, 0, 0, 0, 0, Other_4->w, Other_4->h );
	OtherX = SixForOther ( BoyX, GirlX, RIGHT + 50 );
	ChangFace ( 4, 4, 0);/*同學C說話*/
	Print_words( 200, 0, 255, 0, 85);
	OtherX = SixForOther ( BoyX, GirlX, OtherX );
	ChangFace ( 0, 6, 2);/*千語說話*/
	Print_words( 200, 255, 0, 0, 86);
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 87);
	Print_words( 200, 255, 255, 255, 88);/*男生說話"住手!"*/

	switch (n)
	{
		case 1:/*英杰篇*/
			i = Chap_Sixth_One ();
			break;
		case 3:/*李昱篇*/
			i = Chap_Sixth_Two ();
			break;
		case 2:/*洛維篇*/
			i = Chap_Sixth_Three ();
			break;
	}

	stop_sample(Music6_3);

	return i;
}/*第六幕結束*/
int Chap_Sixth_One ()/*第六幕英杰篇*/
{
	int BoyX, GirlX;

	blit ( Boy1_6_1, Boy, 0, 0, 0, 0, Boy1_6_1->w, Boy1_6_1->h );
	blit ( Girl1_6_2, Girl, 0, 0, 0, 0, Girl1_6_2->w, Girl1_6_2->h );

	BoyX = appear ( RIGHT, 640, 1 );
	ChangFace ( 1, 6, 1);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 89);
	GirlX = appear ( LIFT, BoyX, 0 );
	ChangFace ( 0, 6, 2);/*千語說話*/
	Print_words( 200, 255, 0, 0, 90);
	ChangFace ( 1, 6, 1);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 91);

	stop_sample(Music6_2);
	play_sample( Music6_3, 255, 0, 1000, 1);

	blit ( BigMap_6_3, BigMap, 0, 0, 0, 0, BigMap_6_3->w, BigMap_6_3->h );
	blit ( Boy1_6_2, Boy, 0, 0, 0, 0, Boy1_6_2->w, Boy1_6_2->h );
	blit ( Girl1_6_1, Girl, 0, 0, 0, 0, Girl1_6_1->w, Girl1_6_1->h );
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 92);

	BoyX = appear ( 640, 640, 1 );
	BoyX = appear ( RIGHT, 640, 1 );
	ChangFace ( 1, 6, 2);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 93);
	BoyX = appear ( RIGHT, 640, 1 );
	GirlX = appear ( LIFT, BoyX, 0 );
	ChangFace ( 0, 6, 1);/*千語說話*/
	Print_words( 200, 255, 0, 0, 94);
	ChangFace ( 1, 6, 2);/*英杰說話*/
	Print_words( 200, 255, 255, 255, 95);

/*第六幕英杰篇結束*/
	return 0;
}
int Chap_Sixth_Two ()/*第六幕李昱篇*/
{
	int BoyX, GirlX;

	blit ( Boy2_6_1, Boy, 0, 0, 0, 0, Boy2_6_1->w, Boy2_6_1->h );
	blit ( Girl1_6_2, Girl, 0, 0, 0, 0, Girl1_6_2->w, Girl1_6_2->h );

	BoyX = appear ( RIGHT, 640, 1 );
	ChangFace ( 2, 6, 1);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 103);
	GirlX = appear ( LIFT, BoyX, 0 );
	ChangFace ( 0, 6, 2);/*千語說話*/
	Print_words( 200, 255, 0, 0, 104);
	ChangFace ( 2, 6, 1);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 105);

	stop_sample(Music6_2);
	play_sample( Music6_3, 255, 0, 1000, 1);

	blit ( BigMap_6_3, BigMap, 0, 0, 0, 0, BigMap_6_3->w, BigMap_6_3->h );
	blit ( Boy2_6_2, Boy, 0, 0, 0, 0, Boy2_6_2->w, Boy2_6_2->h );
	blit ( Girl1_6_1, Girl, 0, 0, 0, 0, Girl1_6_1->w, Girl1_6_1->h );

	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 106);
	BoyX = appear ( 640, 640, 1 );
	BoyX = appear ( RIGHT, 640, 1 );
	ChangFace ( 2, 6, 2);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 107);
	GirlX = appear ( LIFT, BoyX, 0 );
	ChangFace ( 0, 6, 1);/*千語說話*/
	Print_words( 200, 255, 0, 0, 108);
	ChangFace ( 2, 6, 2);/*李昱說話*/
	Print_words( 200, 255, 255, 255, 109);

/*第六幕李昱篇結束*/
	return 1;
}
int Chap_Sixth_Three ()/*第六幕洛維篇*/
{
	int BoyX, GirlX;

	blit ( Boy3_6_1, Boy, 0, 0, 0, 0, Boy3_6_1->w, Boy3_6_1->h );
	blit ( Girl1_6_2, Girl, 0, 0, 0, 0, Girl1_6_2->w, Girl1_6_2->h );

	BoyX = appear ( RIGHT, 640, 1 );
	ChangFace ( 3, 6, 1);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 96);
	GirlX = appear ( LIFT, BoyX, 0 );
	ChangFace ( 0, 6, 1);/*千語說話*/
	Print_words( 200, 255, 0, 0, 97);
	ChangFace ( 3, 6, 1);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 98);

	stop_sample(Music6_2);
	play_sample( Music6_3, 255, 0, 1000, 1);

	blit ( BigMap_6_3, BigMap, 0, 0, 0, 0, BigMap_6_3->w, BigMap_6_3->h );
	blit ( Boy3_6_2, Boy, 0, 0, 0, 0, Boy3_6_2->w, Boy3_6_2->h );
	blit ( Girl1_6_1, Girl, 0, 0, 0, 0, Girl1_6_1->w, Girl1_6_1->h );

	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 99);

	BoyX = appear ( 640, 640, 1 );

	BoyX = appear ( RIGHT, 640, 1 );
	ChangFace ( 3, 6, 2);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 100);
	GirlX = appear ( LIFT, BoyX, 0 );
	ChangFace ( 0, 6, 1);/*千語說話*/
	Print_words( 200, 255, 0, 0, 101);
	ChangFace ( 3, 6, 2);/*洛維說話*/
	Print_words( 200, 255, 255, 255, 102);

/*第六幕洛維篇結束*/
	return 2;
}

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

int Chap_Seven ( int i, int like )
{

	int GirlX,BoyX;
	int n = 48;

	play_sample( Music7, 255, 0, 1000, 1);

	blit ( BigMap_7, BigMap, 0, 0, 0, 0, BigMap_7->w, BigMap_7->h );
	blit ( Girl1_7, Girl, 0, 0, 0, 0, Girl1_7->w, Girl1_7->h );
	blit ( FaceG1_7, Face, 0, 0, 0, 0, FaceG1_7->w, FaceG1_7->h );
	if ( i == 0 )/**********此為Chap6中所選擇之男角**********/
	{blit ( Boy1_7, Boy, 0, 0, 0, 0, Boy1_7->w, Boy1_7->h );}
	else if ( i == 1 )
	{blit ( Boy2_7, Boy, 0, 0, 0, 0, Boy2_7->w, Boy2_7->h );}
	else if ( i == 2 )
	{blit ( Boy3_7, Boy, 0, 0, 0, 0, Boy3_7->w, Boy3_7->h );}
	
	Start ();

	GirlX = GirlMove ( 0 - 320 , MIDDLE, 640, 0 );
	Print_words( 200, 255, 0, 0, 110);/*千語說話*/
	play_sample( Music7_1, 255, 0, 1000, 0);	/*敲門聲*/
	Print_words( 200, 255, 0, 0, 111);/*千語說話*/
	GirlX = GirlMove ( GirlX, 640, 640, 1 );
	play_sample( Music7_2, 255, 0, 1000, 0);	/*開門聲*/
	GirlX = GirlMove ( GirlX, LIFT, 640, 1 );
	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 112);
	BoyX = BoyMove ( 640, RIGHT, GirlX, 1 );
	Print_words( 200, 255, 255, 0, 113);/*旁白*/
	BoyX = BoyMove ( BoyX, MIDDLE, GirlX, 0 );
	ChangFace ( i + 1 , 7, 0);/*男生說話*/
	Print_words( 200, 255, 255, 255, 114);
	ChangFace ( 0, 7, 0);/*千語說話*/
	Print_words( 200, 255, 0, 0, 115);
	ChangFace ( i + 1, 7, 0);/*男生說話*/
	Print_words( 200, 255, 255, 255, 116);

	clear_bitmap( screen );/*生日片段*/
	blit ( BigMap_7_4, buffer, 0, 0, 0, 0, BigMap_7_2->w, BigMap_7_2->h );
	blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );

	ChangFace ( -1, -1, -1);/*旁白*/
	Print_words( 200, 255, 255, 0, 117);

	BoyX = 	appear ( RIGHT, LIFT, 1 );
	ChangFace ( 0, 7, 0);/*千語說話*/
	Print_words( 200, 255, 255, 255, 118);

	blit ( Bleak, buffer, 0, 0, 0, 0, Bleak->w, Bleak->h );
	blit ( Bleak, buffer2, 0, 0, 0, 0, Bleak->w, Bleak->h );
	while ( !key[KEY_ENTER] )
	{
		blit ( CubeChoose1, buffer, 0, (7-4)*207, 112, 48, CubeChoose->w, 208 );
		blit ( HandChoose, buffer, 256-64, 0, 48, n, 64, HandChoose->h );
		BleakColor ();
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
		if (key[KEY_Z])
		{n = ONE;}
		else if (key[KEY_X])
		{n=TWO;}
	}

/*	for ( k=256-64; k>=0; k=k-64)
	{
		blit ( Bleak, buffer, 0, 0, 0, 0, Bleak->w, Bleak->h );
		blit ( HandChoose, buffer, k, 0, 48, n, 64, HandChoose->h );
		blit ( CubeChoose, buffer, 0, 0, 112, 48, CubeChoose->w, CubeChoose->h );
		blit ( CubeChoose, buffer, 0, 0, 112, 120, CubeChoose->w, CubeChoose->h );
		blit ( CubeChoose, buffer, 0, 0, 112, 192, CubeChoose->w, CubeChoose->h );
		blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
		clear_bitmap( buffer );
	}*/
	if (n == ONE)
	{n = 1;}
	else if (n == TWO)
	{n = 2;}
	stop_sample(Music7);

	while ( !key[KEY_ESC])
	{
		switch (n)
		{
			case 1:/*最好結局*//*我...我好高興，本來以為只是單戀而已...沒想到...*/
				if ( like >= 2 )
				{
					play_sample( Music7_3, 255, 0, 1000, 1);
					blit ( BigMap_7_1, buffer, 0, 0, 0, 0, BigMap_7_1->w, BigMap_7_1->h );
					blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
					clear_bitmap( buffer );
				}
				if ( like <= 1 )/*第二結局*/
				{
					play_sample( Music7_4, 255, 0, 1000, 1);
					blit ( BigMap_7_2, buffer, 0, 0, 0, 0, BigMap_7_2->w, BigMap_7_2->h );
					blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
					clear_bitmap( buffer );
				}
				break;
			case 2:/*不好結局*//*謝謝你...但是我有喜歡的人了...對不起...*/
				play_sample( Music7_5, 255, 0, 1000, 1);
				blit ( BigMap_7_3, buffer, 0, 0, 0, 0, BigMap_7_3->w, BigMap_7_3->h );
				blit ( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
				clear_bitmap( buffer );
				break;
		}
	}
	stop_sample(Music7_3);
	stop_sample(Music7_4);
	stop_sample(Music7_5);


	return 0;
}

int Print_words(int X, int R,int G, int B, int line){
	BITMAP *Word=create_bitmap(400,100);
	BITMAP *Speak2 = create_bitmap ( 640 , 156 );
	BITMAP *Speak = load_bitmap ("SPEAK.bmp" , NULL );
	clear_to_color(Word,makecol(0,0,0));
	/*print_cfont(BITMAP的指標,X位置,Y位置,字顏色的R,字顏色的G,字顏色的B,要顯示的列數編碼);*/
//	print_cfont(buffer,10,10,0,255,255,6);
	blit ( Speak, Speak2, 0, 0, 0, 0, Speak->w, Speak->h );
	print_cfont(Speak2, X, 30, R, G, B, line);
	blit ( Speak2, screen, 0, 0, 0, 480 - 156, Speak->w, Speak->h );
	PutFace ();
	//	masked_blit(buffer,screen,0,0,0,0,640,480);
	while (!key[KEY_DOWN]){}
	while (!key[KEY_SPACE]){}
	destroy_bitmap (Speak);
	destroy_bitmap (Speak2);
	destroy_bitmap (Word);
	return 0;
}
//		Print_words(200,255,255,255,6);









/*********************************************************************************************/
/*********************************************************************************************/
/**************************************宜洵的部分↑*******************************************/
/*********************************************************************************************/
/*********************************************************************************************/
