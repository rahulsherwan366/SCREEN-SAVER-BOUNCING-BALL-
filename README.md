# SCREEN-SAVER-BOUNCING-BALL-# Screensaver
The screensaver application displays variable balls in a 3d environment with terrain. The balls collide with each other
and the environment dynamically, obeying the laws of physics.
## General Features
- The position, speed and colour of each ball is initially random.
- The positions of the balls are ensured to be non-overlapping.
- The balls collide elastically with the walls, fixed terrain and with each other.
## System Requirements
Screensaver runs on Linux based platforms only. It requires the following packages:
- GNU gcc compiler
- OPENGL utility library
- pthread library
## Usage Instructions
To run the main program, run: make execute num_thread = N
Where N is number of balls and is limited to 50.
Inside the GUI window, N number of bouncing balls will be seen on the screen. 6 buttons are included for various
uses.
## CAMERA/POV options: -
- Press “A” for default front view.
- Press “S” for bird eye view.
- Press “D” for Right Hand side view towards terrain.
- Press “W” for Left Hand side view behind mountains.TRANSPARENCY OPTIONS: -
- Press “J” to make the walls of cuboid opaque.
- Press “L” to increase transparency of walls.
- Press “I” to make the balls opaque.
- Press “K” to increase transparency of balls.
## FOG OPTIONS: -
- Press “H” for night/foggy view.
- Press “G” to day view.
- Press "Q" to exit window.
