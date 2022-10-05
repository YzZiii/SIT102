#include "splashkit.h"

void draw_house_scene()
{
   clear_screen(COLOR_WHITE);
   fill_ellipse(COLOR_BRIGHT_GREEN, 0,400,800,400);
   fill_rectangle(COLOR_GRAY,300,300,200,200);
   fill_triangle(COLOR_RED, 250,300,400,150,550,300);
   
   refresh_screen(60);
   delay(1000);
}


void draw_circle_scene()
{
    clear_screen(COLOR_BLACK);
    fill_circle(COLOR_WHITE,400,300,300);
    fill_rectangle(COLOR_BLACK,400,300,20,300);
    fill_rectangle(COLOR_BLACK,400,300,300,20);
    refresh_screen(60);
}


int main()
{
    open_window("Shapes by Yizheng", 800, 600);

    draw_house_scene();
    delay(1000);
    //Draw the second scene here.hint: start by clearing the screen!
    draw_circle_scene();
    delay(1000);

    draw_house_scene();
    delay(1000);
    //Draw the second scene again here!
    draw_circle_scene();
    delay(1000);
    
    return 0;
}