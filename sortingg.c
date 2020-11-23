#include <stdio.h>
#include <stdlib.h>

struct peserta
{
	int nomor_urut, waktu;
};

typedef struct peserta peserta;

int main()
{
	int n, i, j, temp, min;
	printf("Jumlah peserta lomba lari: ");
	scanf("%d", &n);
	printf("\n");
	peserta *peserta = malloc(n * sizeof(peserta));
	
	for (int i=0; i<n; i++)
	{
		printf("Masukkan nomor peserta dan waktu yang ditempuhnya dalam detik ");
		scanf("%d %d", &peserta[i].nomor_urut, &peserta[i].waktu);
	}
	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(peserta[j].waktu < peserta[min].waktu){
				min=j;
			}
		}
		if(peserta[i].waktu != peserta[min].waktu){
			temp = peserta[i].nomor_urut;
			peserta[i].nomor_urut = peserta[min].nomor_urut;
			peserta[min].nomor_urut = temp;
		}
		if(peserta[i].waktu != peserta[min].waktu){
			temp = peserta[i].waktu;
			peserta[i].waktu = peserta[min].waktu;
			peserta[min].waktu = temp;
		}
	}
	printf("Urutan pemenang: \n");
	for(i=0; i<n; i++)
		printf("Peringkat Ke-%d adalah peserta nomor urut %d dengan waktu %d detik\n",i+1, peserta[i].nomor_urut, peserta[i].waktu);
	return 0;
}