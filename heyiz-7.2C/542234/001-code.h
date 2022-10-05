#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
#include "player.h"
#include "power_up.h"

#include <string>
#include <vector>
using std::vector;
using namespace std;


/**
 * Struct will manage of the game's data
 */
struct game_data
{
    player_data player;
    vector<power_up_data> power_ups;
};

game_data new_game();;//Store the new_player() inside game_data

/**
 * loads the images and draw text.
 */
void draw_hud(const player_data & player);
/**
 * Create random power up and adds this into the game
 */
void add_power_up (game_data &game);
/**
 * Remove the pwoer up at the indicated index from the game's power ups vector
 * will remove a power up from the game
 */
void remove_power_up(game_data & game);
/**
 * When you touch a prop, it generates a sound effect.
 * Will apply the effect of the power up to the player
 */
void apply_power_up(game_data& game);
/**
 * Check if the player has hit a power up
 * when this happens the power up is removed from the game
 * and it has an effect on the player
 */
void check_collisions(game_data &game);
/**
 * Drawing into this procedure
 * it clear the screen, draw hud, the player
 * Redrawing everything, and refresh the screen
 */
void draw_game(game_data &game);
/**
 * will update the dynamic aspects of the game periodically
 */
void update_game(game_data &game);



#endif
