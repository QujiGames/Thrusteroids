

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



