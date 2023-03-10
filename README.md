# comet-buster
======
README
======

1. Compiling & running
2. Sprites conventions
3. Playing

======================
1. Compiling & running
======================

Compiling:
$> make

Running:
$> ./cometbuster

Cleaning:
$> make clean


======================
2. Sprites conventions
======================

Few sprites are provided (in sprites directory). Feel free to use your own
ones.

sprites sizes: 
  - spaceship 32x32
  - bullets: 4x4
  - comets: 64x64 (L) / 32x32 (M) / 16x16 (S)
  - screen: 640x480
  - nyancats: 32xYY (depends on the nyancat type)

spaceship rotation angle: 10° (for the moment)
 => 36 spaceships
 => 1152x32

Naming convention of sprites filenames:
Filename: <something understandable>-N_HxW.bmp
with N the number of frames in the sprite
     H the height of the sprite (usually 32 or 64)
     W the width of a frame

ex:
nyancat-technyancolor-left-12_32x51.bmp means that this sprite is:
  - the LSD nyancat flying to the left
  - composed of 12 frames
  - 32 px high
  - 51 px wide

==========
3. Playing
==========

Game control:
  - q or esc: quite the game
1st player:
  - up arrow: move forward
  - down arrow: move backward
  - left arrow: rotate left
  - right arrow: rotate right
  - space: fire

(TODO 2nd player, for instance:
  - w: move forward
  - s: move backward
  - a: rotate left
  - d: rotate right
  - left shift: fire)


Avoid, shoot and explode comets by smart use of hyperspace and guns. Large
comets divide into medium comets, which divide into small ones. Be careful, ETs
protect the space and they don't like intruders...

Hyperspace: up and down edges are connected, so do left and right ones. Fly to
the left, you will appear on the right. Asteroids and enemies also know the
secret of hyperspace...


========================================================

Enjoy :)

+      o     +              o   
    +             o     +       +
o          +
    o  +           +        +
+        o     o       +        o
-_-_-_-_-_-_-_,------,      o 
_-_-_-_-_-_-_-|   /\_/\  
-_-_-_-_-_-_-~|__( ^ .^)  +     +  
_-_-_-_-_-_-_-""  ""      
+      o         o   +       o
    +         +
o        o         o      o     +
    o           +
+      +     o        o      +  


