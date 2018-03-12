#include <stdio.h>
#include <stdlib.h>
#inculude <fcntl.h>
#inculude <sys/types.h>
#inculude <errno.h>
#difine BUF_SIZE 8192
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char kaynak[10];
	char hedef [10];
	int filedes_input, filedes_output;
	ssize_t returned_input, returned_output;
	char buf[BUF_SÝZE];
	printf("kaynak dosya adini giriniz : ");
	scanf("%s",&kaynak);
	filedes_input=open(kaynak, O_RDONLY);
			if(filedes_input==-1)
				{
					perror("KAYNAK DOSYA BULUNAMADI!!\N LUTFEN GECERLÝ DOSYA ADINI GIRINIZ...\N");
					return 2;
				}
printf("hedef dosya adini gitiniz:");
scanf("%s", &hedef);
filedes_output=open(hedef, O_WRONLY);
			if(filedes_output==-1)
				{
					perror("KAYNAK DOSYA BULUNAMADI!!\N LUTFEN GECERLÝ DOSYA ADINI GIRINIZ...\N");
					return 3;
				}
while((returned_output=write(filedes_input, &buf, BUF_SIZE))>0)
				{
				returned_output=write(filedes_output, &buf,(ssize_t)returned_input);
					if(returned_output!=returned_input)
						{
							perror("DOSYA YAZILMADI");
							return 4;
						}	
				}	
close(filedes_input);
close(filedes_output);
return (EXIT_SUCCESS);	
	
	return 0;
}
