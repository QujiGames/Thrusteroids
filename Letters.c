#include "Console/Console.h"


void largeLetterA(int x, int y, int increment, int after_i)
{
	// start A

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i + 1, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end A
}


void largeLetterB(int x, int y, int increment, int after_i)
{
	// start B

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}

	// end 
}




void largeLetterC(int x, int y, int increment, int after_i)
{
	// start C

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	Console_SetRenderBuffer_Char(x + xpos + 8, y + 1, (char)219, 0x0001, 0x0004, 0x0002);
	Console_SetRenderBuffer_Char(x + xpos + 8, y + 8, (char)219, 0x0001, 0x0004, 0x0002);

	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end C
}





void largeLetterD(int x, int y, int increment, int after_i)
{
	// start D

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end D
}


void largeLetterE(int x, int y, int increment, int after_i)
{
	// start E

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	//end E
}


void largeLetterF(int x, int y, int increment, int after_i)
{
	// start F

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}

	//end F
}





void largeLetterG(int x, int y, int increment, int after_i)
{
	// start G

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i + 1, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 1; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 5 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end G
}



void largeLetterH(int x, int y, int increment, int after_i)
{
	// start H

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end H
}






void largeLetterI(int x, int y, int increment, int after_i)
{
	// start I

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end I
}



void largeLetterJ(int x, int y, int increment, int after_i)
{
	// start J

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	Console_SetRenderBuffer_Char(x + xpos, y + 8, (char)219, 0x0001, 0x0004, 0x0002);

	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end J
}



//
//
//
//void largeLetterK(int x, int y, int increment, int after_i)
//
//
//



void largeLetterL(int x, int y, int increment, int after_i)
{
	// start L

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}


	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end L
}


void largeLetterM(int x, int y, int increment, int after_i)
{
	// start M

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}

	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 4 + i, y + 4 - i, (char)219, 0x0001, 0x0004, 0x0002);
	}

	// end M
}




void largeLetterN(int x, int y, int increment, int after_i)
{
	// start N

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}

	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}


	// end N
}


void largeLetterO(int x, int y, int increment, int after_i)
{
	// start O

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 6; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 2 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 6; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end O
}








void largeLetterP(int x, int y, int increment, int after_i)
{
	// start P

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}

	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end P
}



void largeLetterQ(int x, int y, int increment, int after_i)
{
	// start Q

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 6; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 2 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 5; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 5 + i, y + 7 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}

	// end Q
}



void largeLetterR(int x, int y, int increment, int after_i)
{
	// start R

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 5; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end R
}





void largeLetterS(int x, int y, int increment, int after_i)
{
	// start S

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end S
}





void largeLetterT(int x, int y, int increment, int after_i)
{
	// start T

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 4, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end T
}











void largeLetterU(int x, int y, int increment, int after_i)
{
	// start U

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end U
}


void largeLetterV(int x, int y, int increment, int after_i)
{
	// start V

	int xpos = 0;

	if (after_i == 0)
	{
		xpos = 11 * increment;
	}
	else
	{
		xpos = 11 * increment - (8 * after_i);
	}

	for (int i = 0; i < 6; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 1 + i, y + 6 + i, (char)219, 0x0001, 0x0004, 0x0002);
		Console_SetRenderBuffer_Char(x + xpos + 5 + i, y + 8 - i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 5; i++)
	{
		Console_SetRenderBuffer_Char(x + xpos + 8, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end V
}




//void largeLetterW(int x, int y, int increment, int after_i)
//
//void largeLetterX(int x, int y, int increment, int after_i)
//
//void largeLetterY(int x, int y, int increment, int after_i)
//
//void largeLetterZ(int x, int y, int increment, int after_i)

































//void smallLetterA(int x, int y, int increment, int after_i)
//
//void smallLetterB(int x, int y, int increment, int after_i)
//
//void smallLetterC(int x, int y, int increment, int after_i)
//
//void smallLetterD(int x, int y, int increment, int after_i)
//
//void smallLetterE(int x, int y, int increment, int after_i)
//
//void smallLetterF(int x, int y, int increment, int after_i)
//
//void smallLetterG(int x, int y, int increment, int after_i)
//
//void smallLetterH(int x, int y, int increment, int after_i)
//
//void smallLetterI(int x, int y, int increment, int after_i)
//
//void smallLetterJ(int x, int y, int increment, int after_i)
//
//void smallLetterK(int x, int y, int increment, int after_i)
//
//void smallLetterL(int x, int y, int increment, int after_i)
//
//void smallLetterM(int x, int y, int increment, int after_i)
//
//void smallLetterN(int x, int y, int increment, int after_i)
//
//void smallLetterO(int x, int y, int increment, int after_i)
//
//void smallLetterP(int x, int y, int increment, int after_i)
//
//void smallLetterQ(int x, int y, int increment, int after_i)
//
//void smallLetterR(int x, int y, int increment, int after_i)
//
//void smallLetterS(int x, int y, int increment, int after_i)
//
//void smallLetterT(int x, int y, int increment, int after_i)
//
//void smallLetterU(int x, int y, int increment, int after_i)
//
//void smallLetterV(int x, int y, int increment, int after_i)
//
//void smallLetterW(int x, int y, int increment, int after_i)
//
//void smallLetterX(int x, int y, int increment, int after_i)
//
//void smallLetterY(int x, int y, int increment, int after_i)
//
//void smallLetterZ(int x, int y, int increment, int after_i)







/*

// array for letters (26), 9 wide, 10 tall

int arrAlphabetL[26][9*10];









arrAlphabetL[0][] = {	0,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1	};



arrAlphabetL[1][] = {	1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,0	};



arrAlphabetL[2][] = {	0,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,1,
						0,1,1,1,1,1,1,1,0	};

arrAlphabetL[3][] = {	1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,0	};

arrAlphabetL[4][] = {	1,1,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,1,1,1,1,1,1,1,1	};

arrAlphabetL[5][] = {	1,1,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0	};

arrAlphabetL[6][] = {	0,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						0,1,1,1,1,1,1,1,0	};

arrAlphabetL[7][] = {	1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1	};



// I !!! have to figure out how to display this
arrAlphabetL[8][] = {	1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0	};

arrAlphabetL[9][] = {	0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1	};


arrAlphabetL[10][] = {	1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,1,0,
						1,1,1,1,1,1,1,0,0,
						1,0,0,0,0,0,0,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1	};




arrAlphabetL[11][] = {	1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,1,1,1,1,1,1,1,1	};

arrAlphabetL[12][] = {	1,0,0,0,0,0,0,0,1,
						1,1,0,0,0,0,0,1,1,
						1,0,1,0,0,0,1,0,1,
						1,0,0,1,0,1,0,0,1,
						1,0,0,0,1,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1	};

arrAlphabetL[13][] = {	1,0,0,0,0,0,0,0,1,
						1,1,0,0,0,0,0,0,1,
						1,0,1,0,0,0,0,0,1,
						1,0,0,1,0,0,0,0,1,
						1,0,0,0,1,0,0,0,1,
						1,0,0,0,0,1,0,0,1,
						1,0,0,0,0,0,1,0,1,
						1,0,0,0,0,0,0,1,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1	};

arrAlphabetL[14][] = {	0,0,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,0,0	};

arrAlphabetL[15][] = {	1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0	};

arrAlphabetL[16][] = {	0,0,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,1,0,0,1,
						1,0,0,0,0,0,1,0,0,
						1,1,1,1,1,1,0,1,1	};

arrAlphabetL[17][] = {	1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1	};

arrAlphabetL[18][] = {	0,1,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						1,0,0,0,0,0,0,0,0,
						0,1,1,1,1,1,1,1,0,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,0	};

arrAlphabetL[19][] = {	1,1,1,1,1,1,1,1,1,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0	};

arrAlphabetL[20][] = {	1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						0,1,1,1,1,1,1,1,0	};

arrAlphabetL[21][] = {	1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						0,1,0,0,0,0,0,1,0,
						0,0,1,0,0,0,1,0,0,
						0,0,0,1,0,1,0,0,0,
						0,0,0,0,1,0,0,0,0	};

arrAlphabetL[22][] = {	1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,1,0,0,0,1,
						1,0,0,1,0,1,0,0,1,
						1,0,1,0,0,0,1,0,1,
						1,1,0,0,0,0,0,1,1,
						1,0,0,0,0,0,0,0,1	};

arrAlphabetL[23][] = {	1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						0,1,0,0,0,0,0,1,0,
						0,0,1,1,1,1,1,0,0,
						0,1,0,0,0,0,0,1,0,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1	};

arrAlphabetL[24][] = {	1,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,1,
						0,1,0,0,0,0,0,1,0,
						0,0,1,0,0,0,1,0,0,
						0,0,0,1,0,1,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,0,1,0,0,0,0	};

arrAlphabetL[25][] = {	1,1,1,1,1,1,1,1,1,
						0,0,0,0,0,0,0,0,1,
						0,0,0,0,0,0,0,1,0,
						0,0,0,0,0,0,1,0,0,
						0,0,0,0,0,1,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,1,0,0,0,0,0,
						0,0,1,0,0,0,0,0,0,
						0,1,0,0,0,0,0,0,0,
						1,1,1,1,1,1,1,1,1	};






*/