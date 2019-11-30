#include "Letters.h"

void Write_Text(int x, int y, const char* text)
{
	int after_i = 0;
	
	for (int i = 0; text[i] != '\0'; ++i)
	{
		switch (text[i])
		{
			case 65:
				largeLetterA(x, y, i, after_i);
				break;
			case 66:
				largeLetterB(x, y, i, after_i);
				break;
			case 67:
				largeLetterC(x, y, i, after_i);
				break;
			case 68:
				largeLetterD(x, y, i, after_i);
				break;
			case 69:
				largeLetterE(x, y, i, after_i);
				break;
			case 70:
				largeLetterF(x, y, i, after_i);
				break;
			case 71:
				largeLetterG(x, y, i, after_i);
				break;
			case 72:
				largeLetterH(x, y, i, after_i);
				break;
			case 73:
				largeLetterI(x, y, i, after_i);
				after_i += 1;
				break;
			case 74:
				largeLetterJ(x, y, i, after_i);
				break;
			//case 75:
			//	largeLetterK(x, y, i, after_i);
			//	break;
			case 76:
				largeLetterL(x, y, i, after_i);
				break;
			case 77:
				largeLetterM(x, y, i, after_i);
				break;
			case 78:
				largeLetterN(x, y, i, after_i);
				break;
			case 79:
				largeLetterO(x, y, i, after_i);
				break;
			case 80:
				largeLetterP(x, y, i, after_i);
				break;
			case 81:
				largeLetterQ(x, y, i, after_i);
				break;
			case 82:
				largeLetterR(x, y, i, after_i);
				break;
			case 83:
				largeLetterS(x, y, i, after_i);
				break;
			case 84:
				largeLetterT(x, y, i, after_i);
				break;
			case 85:
				largeLetterU(x, y, i, after_i);
				break;
			case 86:
				largeLetterV(x, y, i, after_i);
				break;
			//case 87:
			//	largeLetterW(x, y, i, after_i);
			//	break;
			//case 88:
			//	largeLetterX(x, y, i, after_i);
			//	break;
			//case 89:
			//	largeLetterY(x, y, i, after_i);
			//	break;
			//case 90:
			//	largeLetterZ(x, y, i, after_i);
			//	break;
/*
			case 97:
				smallLetterA(x, y, i, after_i);
				break;
			case 98:
				smallLetterB(x, y, i, after_i);
				break;
			case 99:
				smallLetterC(x, y, i, after_i);
				break;
			case 100:
				smallLetterD(x, y, i, after_i);
				break;
			case 101:
				smallLetterE(x, y, i, after_i);
				break;
			case 102:
				smallLetterF(x, y, i, after_i);
				break;
			case 103:
				smallLetterG(x, y, i, after_i);
				break;
			case 104:
				smallLetterH(x, y, i, after_i);
				break;
			case 105:
				smallLetterI(x, y, i, after_i);
				after_i += 1;
				break;
			case 106:
				smallLetterJ(x, y, i, after_i);
				break;
				//case 107:
				//	smallLetterK(x, y, i, after_i);
				//	break;
			case 108:
				smallLetterL(x, y, i, after_i);
				break;
			case 109:
				smallLetterM(x, y, i, after_i);
				break;
			case 110:
				smallLetterN(x, y, i, after_i);
				break;
			case 111:
				smallLetterO(x, y, i, after_i);
				break;
			case 112:
				smallLetterP(x, y, i, after_i);
				break;
			case 113:
				smallLetterQ(x, y, i, after_i);
				break;
			case 114:
				smallLetterR(x, y, i, after_i);
				break;
			case 115:
				smallLetterS(x, y, i, after_i);
				break;
			case 116:
				smallLetterT(x, y, i, after_i);
				break;
			case 117:
				smallLetterU(x, y, i, after_i);
				break;
			case 118:
				smallLetterV(x, y, i, after_i);
				break;
				//case 119:
				//	smallLetterW(x, y, i, after_i);
				//	break;
				//case 120:
				//	smallLetterX(x, y, i, after_i);
				//	break;
				//case 121:
				//	smallLetterY(x, y, i, after_i);
				//	break;
				//case 122:
				//	smallLetterZ(x, y, i, after_i);
				//	break;

*/

			default:
				break;
		}
	}
}