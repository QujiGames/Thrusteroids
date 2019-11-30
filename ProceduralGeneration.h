
int Level_Seed(int min, int max);

void Bounding_Box(char(*Terrain), int width, int height);

void Level_Generator(char(*Terrain), int width, int height, int starting_position);


void Level_Generator2(char(*Terrain), int width, int height, int screen_width, int screen_height, float* xTrans, float* yTrans, int starting_position);


void Draw_Wall(char(*Terrain), int width, int height, int starting_position);

void Draw_Wall2(char(*Terrain), int width, int height, int starting_position);

void Draw_Wall3(char(*Terrain), int width, int height, int starting_position);

void Level_Constructor(char(*Terrain), int width, int height, int starting_position, int map_size);


void Wall_Unit(char(*Terrain), int width, int height, int starting_position, int length, int bias, int orientation);

void Star_Field(char(*Terrain), int width, int height);

int Blob_Position(int new_radius, int previous_radius, int previous_origin, int xblob);

void Blob_Generator(char(*aBlob), char(*aLevel), int xblob, int yblob, int level_width, int level_height, int xTrans, int yTrans);

void Draw_Circle(char(*Terrain), int radius, int starting_position, int level_width, int level_height);

void IntroduceChaos(char* (aBlob), int level_width, int level_height);

void Draw_Filled_Circle(char(*Terrain), int radius, int starting_position, int level_width, int level_height);

//void Draw_Rectanguloid(char(*Terrain), int radius, int starting_position, int level_width, int level_height);

void Draw_Part_Circle(char(*Terrain), int radius, int starting_position, int level_width, int level_height, int angle);