#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>
struct wav {
	uint32_t SR;
	uint16_t BPS;
	uint16_t NC;
	uint8_t USR[4];
	uint8_t UBPS[2];
	uint8_t UNC[2];
};
void samra(FILE* ptr, struct wav* wav) {
	char a[24];
	fseek(ptr, 0, SEEK_SET);
	fread(a, 24, 1, ptr);
	fread(wav->USR, 4, 1, ptr);
	wav->SR = wav->USR[0] | (wav->USR[1] << 8) | (wav->USR[2] << 16) | (wav->USR[3] << 24);
}
void bipesam(FILE* ptr, struct wav* wav) {
	char a[34];
	fseek(ptr, 0, SEEK_SET);
	fread(a, 34, 1, ptr);
	fread(wav->UBPS, 2, 1, ptr);
	wav->BPS = wav->UBPS[0] | (wav->UBPS[1] << 8);
}
void nuca(FILE* ptr, struct wav* wav) {
	char a[22];
	fseek(ptr, 0, SEEK_SET);
	fread(a, 22, 1, ptr);
	fread(wav->UNC, 2, 1, ptr);
	wav->NC = wav->UNC[0] | (wav->UNC[1] << 8);
}
int main() {
	FILE* ptr;
	fopen_s(&ptr, "sample.wav", "r");
	struct wav wav;

	samra(ptr, &wav);
	printf("Sample rate: %d Hz\n", wav.SR);

	bipesam(ptr, &wav);
	printf("Bits per sample: %d\n", wav.BPS);

	nuca(ptr, &wav);
	printf("Number of channels: %d\n", wav.NC);
	return 0;

}
