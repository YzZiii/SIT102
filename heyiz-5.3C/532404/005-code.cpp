#include "splashkit.h"
#include "player.h"
#include "power_up.h"

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}
void drawhud(const player_data & player)
{
    load_bitmap("fuel", "fuel.png");
    load_bitmap("battery", "battery.png");
    load_bitmap("shield", "shield.png");
    load_bitmap("coin", "coin.png");

    fill_rectangle(COLOR_LIGHT_BLUE, 0, 0, 800, 135, option_to_screen());
    
    draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 0, 10, option_to_screen());
    draw_text("FUEL: ", COLOR_BLACK, 38, 70, option_to_screen());
    draw_text("SCORE: ", COLOR_WHITE, 0, 0, option_to_screen());
    
    draw_bitmap("full", 20, 75, option_part_bmp(0, 0, bitmap_width("full") * 0.25, bitmap_height("full"), option_to_screen()));
    draw_bitmap("shield", 400, 20, option_to_screen());
    draw_bitmap("battery", 600, 20, option_to_screen());
    draw_bitmap("coin", 600, 300);
}

/**
 * Entry point.
 *
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 800, 800);
    load_resources();

    player_data player;
    player = new_player();
    power_up_data power;
    power = new_power_up(100, 100); // rnd(screen_width()),rnd(screen_height())

    while (not quit_requested())
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(player);

        // Perform movement and update the camera
        update_player(player);
        update_power_up(power);

        // Redraw everything
        clear_screen(COLOR_BLACK);

        drawhud(player);

        // including something stationary - it doesn't move
        // fill_rectangle(COLOR_WHITE, 400, 400, 10, 10);

        // as well as the player who can move
        draw_player(player);
        draw_power_up(power);

        refresh_screen(60);
    }

    return 0;
}