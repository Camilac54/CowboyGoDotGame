// game_manager.cpp
#include "game_manager.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GameManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_start_button_pressed"), &GameManager::_on_start_button_pressed);
}

GameManager::GameManager() {
    start_button = nullptr;
    cowboy = nullptr;
    alien = nullptr;
}

GameManager::~GameManager() {}

void GameManager::_ready() {
    // Get references to your nodes
    alien = get_node<AnimatedSprite2D>("AlienGuy");
    cowboy = get_node<AnimatedSprite2D>("CowboyGuy");
    start_button = get_node<Button>("StartButton");

    
    // Connect the button signal
    if (start_button) {
        start_button->connect("pressed", Callable(this, "_on_start_button_pressed"));
    }
}

void GameManager::_on_start_button_pressed() {
    if (start_button) {
        start_button->set_visible(false);
    }
    change_character_animations();
}

void GameManager::change_character_animations() {
    if (cowboy) {
        cowboy->play("CowboyGuyFighting"); // Replace with your actual animation name
    }
    if (alien) {
        alien->play("AlienGuyFighting"); // Replace with your actual animation name
    }
}