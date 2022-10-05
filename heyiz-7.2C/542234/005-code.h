#ifndef POWER_UP
#define POWER_UP

#include <string>
using std ::string;
#include <vector>
#include "splashkit.h"

#define SCREEN_BORDER 100

/**
 * Different options for the kind of ship.
 * Adjusts the image used.
 */
enum power_up_kind
{
    FUEL,
    BATTERY,
    COIN,
    SHIELD,
    CASH,
    TIME
};

/**
 * Struct for the actual power up data
 */
struct power_up_data
{   
    power_up_kind kind;
    sprite power_up_sprite;
    double counter;
};

/**
 * Actions a step update of the player - moving them and adjusting the camera.
 */
power_up_data new_power_up(double x, double y);

/**
 * loads the power up images.
 */
bitmap power_up_bitmap(power_up_kind kind);

/**
 * draw the power up images
 */
void draw_power_up(const power_up_data &power_up_to_draw);

/**
 * Update the power up to move and later be struck by the player
 */
void update_power_up(power_up_data &power_up_to_update);

#endif