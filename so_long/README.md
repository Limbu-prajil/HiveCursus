# So_long

**So_long** is a simple 2D game where a player navigates through a map, collecting items and reaching an exit. It is developed as part of a coding project using the **MiniLibX** graphics library.

## Table of Contents

- [Project Description](#project-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Controls](#game-controls)
- [Makefile Commands](#makefile-commands)
- [Game Assets](#game-assets)
- [Project Structure](#project-structure)
- [Credits](#credits)

## Project Description

**So_long** is a simple 2D game where you must navigate a maze-like map to collect all available items (Collectibles) and then reach the exit. The map consists of walls, open spaces, a player, an exit, and collectible items. The game follows specific rules where the player must collect all items before exiting the map.

## Features

- **2D game using MiniLibX**
- Player navigation with keyboard controls
- Collectibles and an exit
- Collision detection with walls
- A well-defined map structure

## Installation

### Requirements

- **GCC** or another C compiler
- **MiniLibX** library
- **Make** tool
- **X11** (for Linux users) or **macOS** graphics support for MiniLibX

### Clone the Repository

```bash
git clone https://github.com/yourusername/so_long.git
cd so_long
```

### Install MiniLibX (If not already installed)

For **macOS**:
```bash
brew install minilibx
```

For **Linux**:
```bash
sudo apt-get install libx11-dev libxext-dev libbsd-dev
```

## Usage

After installing the necessary dependencies, you can compile the project using the **Makefile**. Run the following command to build the project:

```bash
make
```

### Running the Game

Once compiled, you can run the game by providing a map file as an argument:

```bash
./so_long maps/map.ber
```

## Game Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **ESC**: Exit the game

## Makefile Commands

- **`make`**: Compile the project.
- **`make clean`**: Remove object files.
- **`make fclean`**: Remove object files and the executable.
- **`make re`**: Recompile the project from scratch.

## Game Assets

The game uses specific assets such as the player, walls, collectibles, and exit icons. These are represented by XPM images, which are rendered on the game window using MiniLibX.

### Example of Game Map Format (`.ber` file)

The map must follow a specific structure and use the following characters:

- **1**: Wall
- **0**: Empty space (walkable area)
- **C**: Collectible item
- **E**: Exit
- **P**: Player start position

Example map file:

```
111111
1P0C01
100001
1C0E01
111111
```

## Project Structure

Here’s an overview of the project structure:

```
so_long/
│
├── src/                # Source code files
│   ├── *.c          # Main game logic
│
├── inc/           # Header files
│   ├── so_long.h       # Main header file
│
├── img/             # Game assets (XPM files for player, walls, etc.)
│   ├── player.xpm
│   ├── wall.xpm
│   └── collectible.xpm
│   └── gas.ber
│
├── maps/               # Example maps for the game
│   └── map.ber
│   └── map2.ber
│
├── Makefile            # Makefile for building the project
└── README.md           # Project documentation
```

## Credits

- This project is part of the **42 School** curriculum.
- Developed by [digitalpool](https://github.com/digitalpool).
