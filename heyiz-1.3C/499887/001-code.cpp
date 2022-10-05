#include "splashkit.h"

//https://video.deakin.edu.au/media/t/1_jdbhzvkp


void load_resource()
{
    load_bitmap("watching","mouse.png");
    load_bitmap("playing","windows.png");
    load_sound_effect("player-hit", "freesound.ogg");
    load_sound_effect("player-hit","xpsound.wav"); 
}
void draw_bitmap_mouse()
{
    play_sound_effect("freesound.ogg");
    clear_screen(COLOR_WHITE);
    draw_bitmap("watching",450,300);
    refresh_screen(60);
    delay(1000);
}
void draw_bitmap_windows()
{   
    clear_screen(COLOR_BLACK);
    play_sound_effect("xpsound.wav");
    draw_bitmap("playing",320,200);
    refresh_screen(60);
    delay(6000);
}
int main()
{    
    open_window("Shape of yizheng", 1280,800);

    load_resource();
    
    draw_bitmap_mouse();
   
    delay(1000);

    draw_bitmap_windows();

    return 0;
}