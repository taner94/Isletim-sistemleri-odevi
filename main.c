#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#define BUF_SIZE 8192

int main(int argc) {
	char kaynak[10];
	char hedef [10];
	int filedes_input, filedes_output;
g	ssize_t returned_input, returned_output;
	char buf[BUF_SIZE];
	//kaynak dosya
	printf("kaynak dosya adini giriniz : ");
	scanf("%s",&kaynak);
	filedes_input=open(kaynak, O_RDONLY);
	if(filedes_input==-1)
	{gg
		perror("KAYNAK DOSYA BULUNAMADI!!");
		return 2;
	}
	//Hedef dosya
	printf("hedef dosya adini gitiniz:");
	scanf("%s", &hedef);
	filedes_output=open(hedef, O_WRONLY);g
	if(filedes_output==-1)
	{
		perror("KAYNAK DOSYA BULUNAMADI!!");
		return 3;
	}

	while((returned_input=read(filedes_input, &buf, BUF_SIZE))>0)
	{
	returned_output=write(filedes_output, &buf,(ssize_t)returned_input);
		if(returned_output!=returned_input)
		{
			perror("DOSYA YAZILMADI");
			return 4;
		}	g
	}	
	close(filedes_input);
	close(filedes_output);
	return (EXIT_SUCCESS);	
}
