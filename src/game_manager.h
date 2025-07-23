// game_manager.h
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

using namespace godot;

class GameManager : public Node {
    GDCLASS(GameManager, Node)

private:
    Button* start_button;
    AnimatedSprite2D* cowboy;
    AnimatedSprite2D* alien;

protected:
    static void _bind_methods();

public:
    GameManager();
    ~GameManager();

    void _ready() override;
    void _on_start_button_pressed();
    void change_character_animations();
};

#endif