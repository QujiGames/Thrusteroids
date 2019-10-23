
int Level_Seed(int min, int max);

void Bounding_Box(char(*Terrain), int width, int height);

void Level_Generator(char(*Terrain), int width, int height, int starting_position);


void Level_Generator2(char(*Terrain), int width, int height, int screen_width, int screen_height, float* xTrans, float* yTrans, int starting_position);


void Draw_Wall(char(*Terrain), int width, int height, int starting_position);

void Draw_Wall2(char(*Terrain), int width, int height, int starting_position);

void Draw_Wall3(char(*Terrain), int width, int height, int starting_position);

void Star_Field(char(*Terrain), int width, int height);