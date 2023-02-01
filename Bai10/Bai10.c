#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

int main() {
	char ans[100], ins[101], state[13], state2[10], state3[15];
	int k, temp;
	printf("Ciphering or Deciphering (c/d): ");
	fgets(ans, sizeof(ans), stdin);
	while (((ans[0] != 'c') && (ans[0] != 'd')) || (strlen(ans) != 2))
	{
		printf("\n\nplease enter \'c\' or \'d\' only");
		printf("\nCiphering or Deciphering (c/d): ");
		fgets(ans, sizeof(ans), stdin);
	}

	char k0 = '\0';
	switch (ans[0]) {
	case 'c':
		strcpy_s(state, sizeof(state), "ciphering");
		strcpy_s(state2, sizeof(state2), "plain");
		strcpy_s(state3, sizeof(state3), "Encrypted");
		temp = 0;
		break;

	case 'd':
		strcpy_s(state, sizeof(state), "deciphering");
		strcpy_s(state2, sizeof(state2), "encrypted");
		strcpy_s(state3, sizeof(state3), "Deciphered");
		temp = 1;
		break;
	}
	printf("\nentering %s mode...", state);
	printf("\nenter %s text: ", state2);
	fgets(ins, sizeof(ins), stdin);
	printf("\nenter ott: ");
	scanf_s("%d", &k);
	k %= 26;
	k += 26;
	k %= 26;
	if (temp == 1) k = 26 - k;

	for (int i = 0; i < k; i++)
	{
		k0 += 1;
	}

	for (int i = 0; i < strlen(ins) - 1; i++) {

		if ((ins[i] >= 65) && (ins[i] <= 90)) {
			if (ins[i] + k > 90) ins[i] += -26 + k0;
			else if ((ins[i] + k >= 65) && (ins[i] + k <= 90)) ins[i] += k0;
		}
		else if ((ins[i] >= 97) && (ins[i] <= 122)) {
			if (ins[i] + k > 122) ins[i] += -26 + k0;
			else if ((ins[i] + k >= 97) && (ins[i] + k <= 122)) ins[i] += k0;
		}
	}
	printf("%s: %s", state3, ins);
	return 0;
}
