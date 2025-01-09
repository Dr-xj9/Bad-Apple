#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define total_f 6569 //number of frames
#define CHUNK 3072 //processing 3KB at a time

void csrs(void);

int main(int argc, char*argv[]){
    
	FILE *fp ;
    size_t nread; //number of elements
	int i = 1, tpf; //time per frame
	int time_sec, count_t, min = 0, sec;
	char file_path[19], buf[CHUNK];
	clock_t start_t, curr_t;
	
	system("CHCP 932");//set code page to shift-jis
	system("mode con: cols=90 lines=50"); //resizing console

	printf("\n");
	printf("\t\t<================= BAD APPLE ====================>\n");
	printf("\t\t||                                              ||\n");
	printf("\t\t||                              -----------     ||\n");
	printf("\t\t||                    ^----^   | Saluditos |    ||\n");
	printf("\t\t||                   | O  o |   -----------     ||\n");
	printf("\t\t||                   <__ww__>                   ||\n");
	printf("\t\t||                                              ||\n");
	printf("\t\t||                                              ||\n");
	printf("\t\t<============== PRESIONA ENTER ==================>\n");
	getchar();

	system("cls");
	printf("\n  Cargando...");
	PlaySound("res\\BA.wav", NULL, SND_ASYNC);
	Sleep(514);
	PlaySound(NULL, 0, 0); //Pre-load

	PlaySound("res\\BA.wav", NULL, SND_ASYNC);

	system("cls");
	csrs();

	start_t = clock(); //starting the timer
	count_t = start_t;

	while (i <= total_f)
	{
	    curr_t = clock();
		time_sec = (curr_t - start_t) / CLOCKS_PER_SEC;
		min = time_sec/60;
		sec = time_sec%60; //acquiring elapsed time in mm:ss

		sprintf(file_path, "res\\BA%d.txt", i); //acquiring the .txt file path

		if (i % 30 == 0) //30 frames per second
			tpf = 43;
		else
			tpf = 33;

		if((curr_t - count_t) >= tpf)
		{
		    fp = fopen(file_path, "r");

		    while((nread = fread(buf, 1, sizeof buf, fp)) > 0)//reads data into the array pointed to
                fwrite(buf, 1, nread, stdout);// writes data to standard output(console)

		    fclose(fp);
			
			printf("\n ------------------------\n");
			printf(" | Tiempo: %02d:%02d  |\n | Frame.NO: %04d       |",min, sec, i);
			printf("\n ------------------------\n");
			csrs();

			i++;
			count_t += tpf;
		}
	}

	Sleep(1919);
	system("cls");
	printf("  FIN .\n");
	printf(" PRESIONA ENTER");
	getchar();
	return 0;
}

void csrs(void) //resetting the cursor
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0, 1 };
	SetConsoleCursorPosition(h,pos);
}