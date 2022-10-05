#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"

void load_resources()
{
    load_resource_bundle("game_bundle","lost_in_space.txt");
}
/**
 * Entry point.
 *
 * Manages the initialisation of data, the event loop, and quitting.
 * https://video.deakin.edu.au/media/t/1_zkm0okc6
 */
int main()
{
    open_window("Lost In Space", 800, 800);
    load_resources();

    game_data game;
    game = new_game();
    

    while (not quit_requested())
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        update_game(game);// Perform a campaign and update the camera
        
        draw_game(game);////Redrawing everything

        refresh_screen(60);
    }

    return 0;
}