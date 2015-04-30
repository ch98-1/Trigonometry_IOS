//Copyright (C) 2014-2015  Corwin Hansen
#ifndef MAIN_H//include protection
	#define MAIN_H


#include <stdio.h>//input and output
#include <stdlib.h>//standard stuff
#include <math.h>//all the math functions
#include <string.h>//string related things
#include <time.h>//time on system
#include "SDL.h"//include sdl
#include "SDL_ttf.h"//include sdl_ttf
#include "SDL_image.h"//include sdl_image


#define FULLLSCREEN //define if fullscreen
//#define FPS //print out fps

#ifdef FULLLSCREEN
#define WINDOWFLAGS SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS        //fullscreen borderless window
#define WIDTH display.w //width and height of window
#define HEIGHT display.h
#else
#define WINDOWFLAGS SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE        //resizable window
#define WIDTH display.w/2 //width and height of window
#define HEIGHT display.h/2;
#endif

#define PEN_SIZE 0.0078125
#define CLICK_RANGE 0.05
#define DEGREE 57.295779513
#define DEGREESIGN 176
#define PI 3.14159265358979323846
#define TEXT_INPUT_SHIFT 0 //y shift when inputting text

#define WINDOW_NAME "Trigonometry"
#define DELAY 10 //default delay
#define DELAY_SLOW 100 //dealy while in background

//paths
#define RESOURCES "" //media resources path. 
#define FONTS "" //fonts path. Inside media resources path.
#define FONT "OpenSans-Regular.ttf" //font path

//defalut points
#define PAX 0.0
#define PAY 0//base is 0 for a and b
#define PBX 1.0
#define PBY 0
#define PCX 0.5
#define PCY (-(0.5*sqrt(3.0)))//equilateral triangle



SDL_Window *window;//sdl window
SDL_Renderer *renderer;//sdl renderer
SDL_Event e;//event

int width, height, maxside;//width and hight and smallest of 2 side of window
double ws, hs;//width and height scaled to maxside
time_t lasttime;//last time mesured
unsigned long int lastframe;//last frame recorded
unsigned long int frame;//number of frames from start
unsigned long int fps;//frames per second

SDL_Texture *somethingwentwrong;//image to display if something goes wrong

SDL_Texture *Background;//image to display on background



SDL_Texture *Angle_A;//textures for angle and line values
SDL_Texture *Angle_B;
SDL_Texture *Angle_C;
SDL_Texture *Line_a;
SDL_Texture *Line_b;
SDL_Texture *Line_c;
SDL_Texture *Line_h;
SDL_Texture *Area;//text for area values


SDL_Texture *DEG_RAD;//if using degrees or radians


SDL_Texture *Text_A;//text for labels
SDL_Texture *Text_B;
SDL_Texture *Text_C;
SDL_Texture *Text_a;
SDL_Texture *Text_b;
SDL_Texture *Text_c;
SDL_Texture *Text_h;
SDL_Texture *pen;//pen to draw with


double ix, iy;//image x and y

double lmx, lmy;//last mouse position

double tax, tay, tbx, tby, tcx, tcy;//triangle that will be drawn on screen

double lAx, lAy, lBx, lBy, lCx, lCy, lax, lay, lbx, lby, lcx, lcy, lhx, lhy;//center points for labels on the triangle

double scale;//scale up or down
double xshift;//shift in x direction
double yshift;//shift in y direction
double XShiftAll;//shift everything drawn in x direction
double YShiftAll;//shift everything drawn in x direction



typedef struct point{
	double x, y;//x and y position
	int known;//if value is certain
}Point;

typedef struct line{
	double l;//length
	int priority;//priority of this value
	int known;//if value is certain
}Line;

typedef struct angle{
	double a;//angle in radians
	int priority;//priority of this value
	int known;//if value is certain
}Angle;

typedef union value{//value
	Point p;//point
	Line l;//line length
	Angle a;//angle
}Value;

Value pointa, pointb, pointc;//point a, b and c of the triangle to do calculations on
Value linea, lineb, linec;//line a, b and c of triangle to calculate on
Value anglea, angleb, anglec;//angle a, b and c of triangle to calculate on
Value lineh;//height of triangle

Value *Selected;//selected object being edited
SDL_Texture **SelectedTexture;//selected texture

char SelectedValue[1024];//selected value

int deg;//if in degrees







uint32_t delay;//amount of delay for each frame
double MouseX, MouseY;//x and y position of mouse / touch normalised


//fonts for different sizes (1/n of maxside)
TTF_Font* font_4;
TTF_Font* font_6;
TTF_Font* font_8;
TTF_Font* font_16;
TTF_Font* font_24;
TTF_Font* font_32;
TTF_Font* font_46;
TTF_Font* font_64;


int EventFilter(void* userdata, SDL_Event* e);//event filter
void Quit(void);//quit everything
void GetDisplay(void);//get display
void Clicked(void);//x and y positions clicked
void Draged(void);//draged function to call when mouse is moved while it is down
void Resize(void);//recalculate numbers related to size and load texts
SDL_Texture* GetTexture(const char *file);//make texture from this file
TTF_Font* GetFont(const char *file, int size);//get font from file
SDL_Texture* GetTextTexture(TTF_Font* font, const char* text, int r, int g, int b);//make texture from font text and rgb
void DrawBase(void);//draw basic stuff
void DrawText(SDL_Texture *texture, double x, double y, SDL_Rect *rect, int center);//draw rect of texture at x and y position normalised. Null rect for whole texture. set center to 1 to center to x and y. Draws texture at full size
void DrawIMG(SDL_Texture *texture, double x, double y, SDL_Rect *rect, double w, double h, int center);//draw rect of texture at x and y position normalised at scale from maxside. Null rect for whole texture. set center to 1 to center to x and y
void DrawTriangle(double ax, double ay, double bx, double by, double cx, double cy);//draw triangle for those points with 1 as maxside
void DrawLine(double ax, double ay, double bx, double by);//draw line for those points with 1 as maxside
void GetKnown(void);//recalculate known values
void Calculate(void);//calculate values in the triangle
int IsLine(Value *value);//check if value is any of 3 lines
void GetPoints(void);//get points from angle and value
void GetAngles(void);//get the third angle

#endif