#include "cipher.h"
#define TWENTY_SIX 26
#define ZERO 0

void cipher (char s[], int k) {
	//making k non negative between 0 and 26
	k = ((k % TWENTY_SIX) + TWENTY_SIX) % TWENTY_SIX;

	for (int i = ZERO; s[i] != '\0'; i++)
	{
		//lowercase
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = 'a' + (((s[i] - 'a') + k) % TWENTY_SIX);
		}
		//UPPERCASE
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = 'A' + (((s[i] - 'A') + k) % TWENTY_SIX);
		}
	}

}
void decipher (char s[], int k) {
	cipher(s, (TWENTY_SIX - k));
}