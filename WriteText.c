#include "Letters.h"

void Write_Text(int x, int y, const char* text)
{
	int after_i = 0;
	
	for (int i = 0; text[i] != '\0'; ++i)
	{
		switch (text[i])
		{
			case 84:
				largeLetterT(x, y, i, after_i);
				break;
			case 83:
				largeLetterS(x, y, i, after_i);
				break;
			case 82:
				largeLetterR(x, y, i, after_i);
				break;
			case 85:
				largeLetterU(x, y, i, after_i);
				break;
			case 69:
				largeLetterE(x, y, i, after_i);
				break;
			case 79:
				largeLetterO(x, y, i, after_i);
				break;
			case 73:
				largeLetterI(x, y, i, after_i);
				after_i += 1;
				break;
			case 68:
				largeLetterD(x, y, i, after_i);
				break;
			case 72:
				largeLetterH(x, y, i, after_i);
				break;
			case 65:
				largeLetterA(x, y, i, after_i);
				break;
			case 77:
				largeLetterM(x, y, i, after_i);
				break;
			case 71:
				largeLetterG(x, y, i, after_i);
				break;
			case 86:
				largeLetterV(x, y, i, after_i);
				break;

			default:
				break;
		}
	}
}