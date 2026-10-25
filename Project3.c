#include "drawing.h"
#include <stdio.h>

typedef struct {
  int r;
  int g;
  int b;
} Color;

void neba (Color palette[], int num_layers, int layer_height, int screen_width) 
{
  int current_row = 1;
  for (int layer = 0; layer < num_layers; layer++) 
  {
    set_color(palette[layer].r, palette[layer].g, palette[layer].b);

    for (int row = 0; row < layer_height; row++) 
    {
      move_to(current_row, 1);
      for (int col = 0; col < screen_width; col++) 
      {
        draw_pixel();
        move_right();
      }
      current_row++;
    }
  }
}

void right_n(int count) {
  for (int i = 0; i < count; i++) {
    move_right();
    draw_pixel();
  }
}

void left_n(int count) {
  for (int i = 0; i < count; i++) {
    move_left();
    draw_pixel();
  }
}

void up_n(int count) {
  for (int i = 0; i < count; i++) {
    move_up();
    draw_pixel();
  }
}

void down_n(int count) {
  for (int i = 0; i < count; i++) {
    move_down();
    draw_pixel();
  }
}

void stinky (int count, int r, int g, int b, int row, int col)
{
  set_color(r, g, b);
  int current_col = col;
  move_to(row, col);
  for (int i = 0; i < count; i++) {
    move_to(row, current_col);
    draw_pixel();
    down_n(1);
    right_n(1);
    up_n(1);
    right_n(1);
    down_n(1);
    current_col += 6;
  }
}

void stinky2 (int count, int r, int g, int b, int row, int col)
{
  set_color(r, g, b);
  move_to(row, col);
  for (int i = 0; i < count; i++) {
    draw_pixel();
    down_n(1);
    right_n(1);
    up_n(1);
  }
}

void zed (int r, int g, int b, int row, int col, int width, int height)
{
  set_color(r, g, b);
  move_to(row, col);
  for (int i = 0; i < height; i++) 
  {
    for (int j = 0; j < width; j++) 
    {
      draw_pixel();
      move_right();
    }
    move_to(row + i + 1, col);
  }
}

int main() 
{
  // Keep this line here
  clear_screen();
  // Load the input - what should be drawn.

  // Put your drawing code here
  //neba
  Color sky[] = {
    {0,   0,   0},
    {58,  12,  85},
    {120, 10,  75},
    {165, 15,  95},
    {175, 75,  15},
    {220, 115, 10},
    {220, 115, 90}
  };
  int layers_count = sizeof(sky) / sizeof(sky[0]); 
  int row_per_color = 2;                            
  int width = 75;  
  neba(sky, layers_count, row_per_color, width);
  //kremel
  stinky(13, 215, 25, 20, 9, 1);
  stinky2(74, 215, 25, 20, 11, 1);
  zed(215, 25, 20, 7, 7, 9, 4); //barva(r g b) souřadnice(y x) šířka výška (6-7)
  zed(215, 25, 20, 4, 9, 5, 3); //barva(r g b) souřadnice(y x) šířka výška (6-7)
  zed(215, 25, 20, 5, 62, 9, 6); //barva(r g b) souřadnice(y x) šířka výška (6-7)





  // Keep this line here
  end_drawing();

  return 0;
}