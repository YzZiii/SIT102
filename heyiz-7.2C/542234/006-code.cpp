#include "splashkit.h"
#include "power_up.h"


bitmap power_up_bitmap(power_up_kind kind)
{
    switch (kind)
    {
    case SHIELD:
        return bitmap_named("shield");
    case COIN:
        return bitmap_named("coin");
    case BATTERY:
        return bitmap_named("battery");
    case CASH:
        return bitmap_named("cash");
    case TIME:
        return bitmap_named("time");
    case FUEL:
    default:
        return bitmap_named("fuel");
    }
}

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    result.counter = 1;
    result.kind = static_cast<power_up_kind>(rnd(6));
    bitmap default_power_bitmap = power_up_bitmap(result.kind);
    result.power_up_sprite = create_sprite(default_power_bitmap);
    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2);
    return result;
}

void draw_power_up(const power_up_data & power_up_to_draw)
{
    draw_sprite( power_up_to_draw.power_up_sprite);
}

void update_power_up(power_up_data &power_up_to_update)
{   
    update_sprite(power_up_to_update.power_up_sprite);
    power_up_to_update.counter = power_up_to_update.counter - 0.000278;
}

