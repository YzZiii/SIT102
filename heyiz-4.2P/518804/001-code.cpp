#include "splashkit.h"

#define RADIUS 50
#define STEPSIZE 3
int main()
{   
    double x;
    double y;
    open_window("Refine Shape Shifter", 800,600);
    
    x = screen_width() / 2; //400
    y = screen_height() / 2; //300

    while( not quit_requested())
    {
        process_events();
        if(key_down(LEFT_KEY))
        {   
            if (x- STEPSIZE-RADIUS >=0)
            {
                 x = x - STEPSIZE;
            }
        }

        if(key_down(RIGHT_KEY))
        {
            if (x+ STEPSIZE +RADIUS <= screen_width())
            {
                x = x + STEPSIZE;
            }
        }

        if(key_down(UP_KEY))
        {   
            if (y -STEPSIZE-RADIUS >=0)
            {
             y = y - STEPSIZE;   
            }
        }

        if(key_down(DOWN_KEY))
        {   
            if (y+STEPSIZE+RADIUS<=screen_height())
            {
              y = y + STEPSIZE;   
            }
        }
    clear_screen(COLOR_WHITE);
    fill_circle(COLOR_GREEN, x, y, RADIUS);
    refresh_screen(60);
    }
    return 0;
}