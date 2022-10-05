#include "splashkit.h"
#include "lost_in_space.h"
#include "player.h"
#include "power_up.h"

#include <vector>
using std::vector;
using namespace std;

void draw_hud(const player_data &player)//Draws tables and displays real-time fuel, coins and scores
{
    load_bitmap("green_bar_lines", "green_bar_lines.png");
    load_bitmap("battery", "battery.png");
    load_bitmap("shield", "shield.png");

    fill_rectangle(COLOR_LIGHT_BLUE, 0, 0, 800, 150, option_to_screen());
    draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 0, 10, option_to_screen());
    draw_text("FUEL: ", COLOR_WHITE, 38, 70, option_to_screen());
    draw_text("SCORE: " + to_string(player.score), COLOR_WHITE, 0, 0, option_to_screen());
    draw_text("coin: " + to_string(player.coin), COLOR_WHITE, 0, 20, option_to_screen());
    
    draw_bitmap("green_bar_lines", 20, 75, option_part_bmp(0, 0, bitmap_width("green_bar_lines") * player.fuel_pct, bitmap_height("green_bar_lines"), option_to_screen()));
    for (int i = 0; i < player.battery_number; i++)
    {
        draw_bitmap("battery", 340 + 70 * i, 50, option_to_screen());//When a battery is collided with, a battery picture is added
    }
}
game_data new_game() 
{
    game_data game;
    game.player = new_player(); //storing new_player() inside game_data
    game.power_ups.push_back(new_power_up(0,0));
    return game;
}

void draw_game(game_data &game)
{
    clear_screen(COLOR_BLACK);
    draw_hud(game.player);
    draw_player(game.player);

    for (int i = 0; i < game.power_ups.size(); i++)
    {
        draw_power_up(game.power_ups[i]);
    }
}

void add_power_up(game_data &game) //creates a random power up, and adding this into the game
{
    game.power_ups.push_back(new_power_up(rnd(-800, 800), rnd(-800, 800)));
}

void remove_power_up(game_data &game, int index)//remove elements
{

    if (index > 0 and index < game.power_ups.size())
    {
        int last_idx;
        last_idx = game.power_ups.size() - 1;
        game.power_ups[index] = game.power_ups[last_idx];
        game.power_ups.pop_back();
    }
}

void apply_power_up(player_data &player, power_up_data &power_up)//will apply the effect of the power up to the player
{
    switch (power_up.kind)
    {
    case FUEL:
        if (player.fuel_pct < 1)
        {
            player.fuel_pct = player.fuel_pct + 0.1;
        }
    case BATTERY:
        player.battery_number = player.battery_number + 1;
        break;
    case SHIELD:
        player.score = player.score + 1;
        break;
    case CASH:
        player.score = player.score + 1;
        break;
    case COIN:
        player.coin = player.coin + 1; 
        break;
    case TIME:
        player.score = player.score + 1;
        break;
    }
}

void check_collisions(game_data &game)//will check if the player has hit a power up
{
    for (int i = 0; i < game.power_ups.size(); i++)
    {
        if (sprite_collision(game.player.player_sprite, game.power_ups[i].power_up_sprite))
        {
            apply_power_up(game.player, game.power_ups[i]);
            remove_power_up(game, i);
            load_sound_effect("Got_it", "Got_it.wav");
            play_sound_effect("Got_it");
        }
    }
}

void update_game(game_data &game)//will update the dynamic aspects of the game periodically
{
    update_player(game.player);

    game.player.fuel_pct = game.player.fuel_pct - 0.000278;

    if (rnd() < 0.05)
    {
        add_power_up(game);
    }

    for (int i = 0; i < game.power_ups.size(); i++)
    {
        update_power_up(game.power_ups[i]);
        if (game.power_ups[i].counter < 0) // check if game.power.up.counter is less than 0, then del power up
        {
            remove_power_up(game, i);
        }
    }
    check_collisions(game);
}