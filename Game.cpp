echo # Game.cpp >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/FrancisWWL/Game.cpp.git
git push -u origin master

// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

double	g_dElapsedTime;
double	g_dDeltaTime;
bool	g_abKeyPressed[K_COUNT];
COORD	g_cCharLocation;
COORD	g_cConsoleSize;

//p1 data
int p1heart;p1coordx;p1coordy;

//bullet(20)
int b1directx;b1directy;b1coordx;b1coordy;
int b2directx;b2directy;b2coordx;b2coordy;
int b3directx;b3directy;b3coordx;b3coordy;
int b4directx;b4directy;b4coordx;b4coordy;
int b5directx;b5directy;b5coordx;b5coordy;
int b6directx;b6directy;b6coordx;b6coordy;
int b7directx;b7directy;b7coordx;b7coordy;
int b8directx;b8directy;b8coordx;b8coordy;
int b9directx;b9directy;b9coordx;b9coordy;
int b10directx;b10directy;b10coordx;b10coordy;
int b11directx;b11directy;b11coordx;b11coordy;
int b12directx;b12directy;b12coordx;b12coordy;
int b13directx;b13directy;b13coordx;b13coordy;
int b14directx;b14directy;b14coordx;b14coordy;
int b15directx;b15directy;b15coordx;b15coordy;
int b16directx;b16directy;b16coordx;b16coordy;
int b17directx;b17directy;b17coordx;b17coordy;
int b18directx;b18directy;b18coordx;b18coordy;
int b19directx;b19directy;b19coordx;b19coordy;
int b20directx;b20directy;b20coordx;b20coordy;
bool b1autotarget;b1bullet;
bool b2autotarget;b2bullet;
bool b3autotarget;b3bullet;
bool b4autotarget;b4bullet;
bool b5autotarget;b5bullet;
bool b6autotarget;b6bullet;
bool b7autotarget;b7bullet;
bool b8autotarget;b8bullet;
bool b9autotarget;b9bullet;
bool b10autotarget;b10bullet;
bool b11autotarget;b11bullet;
bool b12autotarget;b12bullet;
bool b13autotarget;b13bullet;
bool b14autotarget;b14bullet;
bool b15autotarget;b15bullet;
bool b16autotarget;b16bullet;
bool b17autotarget;b17bullet;
bool b18autotarget;b18bullet;
bool b19autotarget;b19bullet;
bool b20autotarget;b20bullet;

//monster(4)
int m1heart;m1coordx;m1coordy;
int m2heart;m2coordx;m2coordy;
int m3heart;m3coordx;m3coordy;
int m4heart;m4coordx;m4coordy;
bool m1autotarget;
bool m2autotarget;
bool m3autotarget;
bool m4autotarget;

//bosses(1)
int boss1heart;boss1coordx;bosscoordy;
int bossb1bullet;bossb1directx;bossb1directy;bossb1coordx;bossb1coordy;
bool boss1autotarget;

//passive
enum charms
{
	
}

//active
enum items
{
	
}

//active
enum monsters
{
	
}

//active
enum bosses
{
	
}

//--------------------------------------------------------------
// Purpose	: Initialisation function
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

	// set the name of your console window
    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(79, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    g_cConsoleSize.X = csbi.srWindow.Right + 1;
    g_cConsoleSize.Y = csbi.srWindow.Bottom + 1;

    // set the character to be in the center of the screen.
    g_cCharLocation.X = g_cConsoleSize.X / 2;
    g_cCharLocation.Y = g_cConsoleSize.Y / 2;

    g_dElapsedTime = 0.0;
}

//--------------------------------------------------------------
// Purpose	: Reset before exiting the program
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

//--------------------------------------------------------------
// Purpose	: Getting all the key press states
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void getInput( void )
{    
    g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
    g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

//--------------------------------------------------------------
// Purpose	: Update function
// Input	: dt = deltatime
// Output	: void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    // Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
    if (g_abKeyPressed[K_UP] && g_cCharLocation.Y > 0)
    {
        Beep(1440, 30);
        g_cCharLocation.Y--; 
    }
    if (g_abKeyPressed[K_LEFT] && g_cCharLocation.X > 0)
    {
        Beep(1440, 30);
        g_cCharLocation.X--; 
    }
    if (g_abKeyPressed[K_DOWN] && g_cCharLocation.Y < g_cConsoleSize.Y - 1)
    {
        Beep(1440, 30);
        g_cCharLocation.Y++; 
    }
    if (g_abKeyPressed[K_RIGHT] && g_cCharLocation.X < g_cConsoleSize.X - 1)
    {
        Beep(1440, 30);
        g_cCharLocation.X++; 
    }

    // quits the game if player hits the escape key
    if (g_abKeyPressed[K_ESCAPE])
        g_bQuitGame = true;    
}

//--------------------------------------------------------------
// Purpose	: Render function is to update the console screen
// Input	: void
// Output	: void
//--------------------------------------------------------------
void render( void )
{
    // clear previous screen
    colour(0x0F);
    cls();

    //render the game

    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
	
	for (int i = 0; i < 12; ++i)
	{
		gotoXY(3*i,i+1);
		colour(colors[i]);
		std::cout << "WOW";
	}

    // render time taken to calculate this frame
    gotoXY(70, 0);
    colour(0x1A);
    std::cout << 1.0 / g_dDeltaTime << "fps" << std::endl;
  
    gotoXY(0, 0);
    colour(0x59);
    std::cout << g_dElapsedTime << "secs" << std::endl;

    // render character
    gotoXY(g_cCharLocation);
    colour(0x0C);
    std::cout << (char)1;
}
