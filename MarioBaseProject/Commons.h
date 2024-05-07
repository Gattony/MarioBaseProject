#pragma once
struct Vector2D
{
    float x;
    float y;

    Vector2D()
    {
        x = 0.0f;
        y = 0.0f;
    }
    Vector2D(float inital_x, float inital_y)
    {
        x = inital_x;
        y = inital_y;
    }

};
struct Rect2D
{
    float x;
    float y;
    float width;
    float height;

    Rect2D(float x_pos, float y_pos, float width, float height)
    {
        x = x_pos;
        y = y_pos;
        this->width = width;
        this->height = height;
    }
};
enum FACING
{
    FACING_LEFT,
    FACING_RIGHT
};

enum SCREENS
{
    SCREEN_INTRO,
    SCREEN_MENU,
    SCREEN_LEVEL1,
    SCREEN_LEVEL2,
    SCREEN_GAMEOVER,
    SCREEN_HIGHSCORES
};
