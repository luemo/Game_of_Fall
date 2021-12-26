#include<stdio.h>
#include<Allegro.h>
#include<math.h>
#define Extend 15

	BITMAP *font_map_sor[16];
	BITMAP *font_load;
	FILE *loadf;
	BITMAP *font_buffer;
	BITMAP *$Cfont_buf;
	FONT *semi_sign;

char string[100]={0};
int load_Cfont();
int	load_txt();
int line_chk();
int num_chk();
int print_to_buffer(int words);
int cloud=0;
int $Cfont_x;
int $Cfont_y;
int $Cfont_x_posi;
int $Cfont_R,$Cfont_G,$Cfont_B;
//int Cfont_color=255;

int init_Cfont(){
//	allegro_init();
//	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,200,0,0);
	font_load=create_bitmap_ex(8,16*16,16*256);
	font_buffer=create_bitmap(16,16);
	clear_to_color(font_buffer,makecol(255,0,255));
	loadf=fopen("load.txt","rb");
	load_Cfont();
	return 0;
}

BITMAP *ASK_NUM_PIC(){return font_map_sor[1];}
int load_Cfont(){
		semi_sign=load_font("./Cfont/mingliu.PCX", NULL, NULL);
		font_map_sor[1]=load_bitmap("./Cfont/number.bmp",NULL);
		font_map_sor[3]=load_bitmap("./Cfont/sign.bmp",NULL);
		font_map_sor[4]=load_bitmap("./Cfont/Cfont_4E00x4fff.bmp",NULL);
		font_map_sor[5]=load_bitmap("./Cfont/Cfont_5000x5fff.bmp",NULL);
		font_map_sor[6]=load_bitmap("./Cfont/Cfont_6000x6fff.bmp",NULL);
		font_map_sor[7]=load_bitmap("./Cfont/Cfont_7000x7fff.bmp",NULL);
		font_map_sor[8]=load_bitmap("./Cfont/Cfont_8000x8fff.bmp",NULL);
		font_map_sor[9]=load_bitmap("./Cfont/Cfont_9000x9fa5.bmp",NULL);
		font_map_sor[Extend]=load_bitmap("./Cfont/Cfont_4E00x4fff.bmp",NULL);
	return 0;
}
/**************************************************************************/
int print_cfont(BITMAP *Cfont_out,int x,int y,int R,int G,int B,int line){
	fseek(loadf,0,0);
	$Cfont_buf=Cfont_out;
	$Cfont_x=x;
	$Cfont_y=y;
	cloud=line;
	$Cfont_R=R;
	$Cfont_G=G;
	$Cfont_B=B;
	int words=0;
//	Cfont_color=color;
	words=
	load_txt();
//		textprintf(screen,font,150,160,makecol(255,255,255),"%d",words);
//		readkey();
//	print_to_buffer(words);
//	readkey();

	
//	loadf=fopen("load2.txt","w");
//	for(i=0;i<200;i++)
//	fprintf(loadf,"@##[%d]\n",i);
	return print_to_buffer(words);
}

int print_to_buffer(int words){
	int overtake[2];
	char word[8]={0};
	int i,j;
	int column=0;
	int row=0;
	int column_u=0;

	int font_pointer;
	int w;
	#define row_u 16

	$Cfont_x_posi=$Cfont_x;
	for(w=0;w<words;w++){
	word[0]=string[2*w];
	word[1]=string[2*w+1];
	
	//		textprintf(screen,font,50,50,makecol(255,255,255),"%x %x",word[1],word[0]);
	//		textprintf(screen,font,50,60,makecol(255,255,255),"%x",&loadf);
	//		readkey();
	if(string[2*w]==13 && string[2*w+1]==0){
		row++;
		w++;
		column=0;
		$Cfont_x_posi=$Cfont_x;
		continue;
	}
	if(string[2*w]==0 && string[2*w+1]==48){
		column_u=16;
		column++;
		$Cfont_x_posi+=column_u;
		continue;
	}
	
	for(i=0;i<2;i++){
		if(word[i]<0){
			word[i]=128+word[i];
	//				textprintf(screen,font,50,50,makecol(255,255,255),"%x %x",word[1],word[0]);
	//		readkey();
			overtake[i]=1;
			}
		else overtake[i]=0;
	}
	
		j=word[1]/16+overtake[1]*8;
		if( j>=5 && j<=9 ){
			font_pointer=j;
			column_u=16;
		}
		else if(j==4 && word[1]>=14){
			font_pointer=4;
			column_u=16;
			string[2*w+1]-=14;
			word[1]-=14;
		}
//		else if(j==0 && (string[2*w]>=48 && string[2*w]<=57) ){
//			font_pointer=1;
//			column_u=12;
//			string[2*w]-=48;
//			word[0]-=48;
//		}
		else if(j==15 && (word[1]+overtake[1]*128)%16>=15){		//全形符號判別
			font_pointer=3;
			column_u=16;
			string[2*w+1]-=15;
			word[1]-=15;
		}
		else if(j==3 && (word[0]<=16)){							//全形符號判別２
			font_pointer=3;
			column_u=16;
			string[2*w]+=96;
			word[0]+=96;
		}
		else if(j==15 && (word[1]+overtake[1]*128)%16>=15){
			font_pointer=3;
			column_u=16;
			string[2*w+1]-=15;
			word[1]-=15;
//			readkey();
		}
		else if(j==0 && (word[1]+overtake[1]*128)==0  &&
				word[0]+overtake[0]*128>=32 &&
				word[0]+overtake[0]*128<=126){
//			font_pointer=3;
			column_u=8;
			textprintf_ex($Cfont_buf,semi_sign,$Cfont_x_posi,$Cfont_y+row*row_u,makecol($Cfont_R,$Cfont_G,$Cfont_B),-1,"%c",word[0]);
			$Cfont_x_posi+=column_u;
//			readkey();
			continue;
		}
		else{
			continue;
			font_pointer=Extend;
			column_u=16;
		}
	
			for(i=0;i<16;i++){
				for(j=0;j<column_u/*預設為16*/;j++){

					if(font_map_sor[font_pointer]->
									line[	( (word[1])%16 )*256 + (word[0]/16)*16 +
											i+
											overtake[0]*128	]
										[3*(word[0]%16*16+j)+1]==0)
					{
						font_buffer->line[i][3*j]=$Cfont_B;
						font_buffer->line[i][3*j+1]=$Cfont_G;
						font_buffer->line[i][3*j+2]=$Cfont_R;
					}
	//				textprintf(screen,font,50,50,makecol(255,255,255),"%x %x",word[1],word[0]);
				}
			}

			masked_blit(	font_buffer		,$Cfont_buf		,0,0,
							$Cfont_x_posi	,$Cfont_y+row*row_u	,column_u/*16*/,row_u/*16*/);
					clear_to_color(font_buffer,makecol(255,0,255));
					column++;
					$Cfont_x_posi+=column_u;
	}//END OF WORD
	return $Cfont_x_posi;
}
int	load_txt(){
	int i;
	int words;
	int error_flag=0;
	int rule;
//	int cut;
	words=0;
	i=0;

//	fseek(loadf,sizeof(char)*2,0);
	char secrify;
	scanf("%c%c",&secrify,&secrify);
//	cut=0;
//
//cut++;
	rule=0;
	while(rule==0){
		rule=line_chk();
		if(rule==1){
			if( rule=num_chk() ){
			}
		}
	}
	if(rule==1){
//	fseek(loadf,sizeof(char)*2,1);
	i=0;
	rule=0;
	words=0;
	while(!feof(loadf)){
//		fscanf(loadf,"%c%c%c%c%c%c",&string[0],&string[1],&string[2],&string[3],&string[4],&string[5]);
		fscanf(loadf,"%c%c",&string[2*i],&string[2*i+1]);
		if(rule==0){
			if(string[2*i]==64 && string[2*i+1]==0){rule=1;}
		}
		else if(rule==1){
			if(string[2*i]==35 && string[2*i+1]==0){rule=2;}
			else{rule=0;}
		}
		else if(rule==2){
			if(string[2*i]==35 && string[2*i+1]==0){rule=4;}
			else{rule=0;}
		}
		else if(rule==4){
			if(string[2*i]==91 && string[2*i+1]==0){words=words-5;break;}
			else{rule=0;}
		}
//		fseek(loadf,sizeof(char),1);
//		textprintf(screen,font,50,50,makecol(255,255,255),"%x %x",string[2*i],string[2*i+1]);
//		readkey();
		words++;
		i++;
	}
	}
	else{
	string[0]='e';
	string[1]='r';
	string[2]='r';
	string[3]='0';
	string[4]='r';
	words=5;
	}
	return words;
}



int num_chk(){
	int k,tifa;
	int pow_int=0;
	int string_pointer[4]={0};
	tifa=0;
		do{
			fscanf(loadf,"%c%c",&string[0],&string[1]);
			if(string[0]==93 && string[1]==0){
				for(k=0;k<pow_int;k++){
					tifa=tifa+string_pointer[k]*pow(10, (pow_int-k)-1 );
//textprintf(screen,font,80,80,makecol(255,255,255),"!%d=ti",tifa);
//readkey();
				}
				if(tifa==cloud){
					return 1;

				}
				else{
					return 0;
				}
			}
			string_pointer[pow_int]=string[0]-48;
			pow_int++;
		}while(!feof(loadf));
				
return 3;
}

int line_chk(){
				fscanf(loadf,"%c%c",&string[0],&string[1]);
//textprintf(screen,font,80,80,makecol(255,255,255),"!%d %d",string[0],string[1]);
//readkey();
			if(feof(loadf)){return 3;}
			if(string[0]==64 && string[1]==0){
				fscanf(loadf,"%c%c",&string[0],&string[1]);
//textprintf(screen,font,80,80,makecol(255,255,255),"!%d %d",string[0],string[1]);
//readkey();
			if(feof(loadf)){return 3;}
			if(string[0]==35 && string[1]==0){
				fscanf(loadf,"%c%c",&string[0],&string[1]);
//textprintf(screen,font,80,80,makecol(255,255,255),"!%d %d",string[0],string[1]);
//readkey();
			if(feof(loadf)){return 3;}
			if(string[0]==35 && string[1]==0){
				fscanf(loadf,"%c%c",&string[0],&string[1]);
//textprintf(screen,font,80,80,makecol(255,255,255),"!%d %d",string[0],string[1]);
//readkey();
			if(feof(loadf)){return 3;}
			if(string[0]==91 && string[1]==0){

return 1;
			}//[
			}//#
			}//#
//			fseek(loadf,-1*sizeof(char)*2,1);
			}//@
return 0;
}

int close_Cfont(){
	int i;
	fclose(loadf);
	for(i=0;i<16;i++){
		destroy_bitmap(font_map_sor[i]);
	}
	destroy_bitmap(font_load);
return 0;
}