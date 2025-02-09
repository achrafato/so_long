# So Long - 2D Game Project

A simple 2D game using the MinilibX graphics library. Navigate through a map collecting items while avoiding enemies.

## 🎮 Game Overview

A 2D game where the player must collect all collectibles and reach the exit while potentially avoiding enemies. Built using the MinilibX library for graphical rendering.

## 🗺️ Features

### Mandatory Part
- Map rendering with walls, collectibles, and exit
- Player movement (up, down, left, right)
- Collectible counting
- Move counter
- Clean exit handling
- Map validation
- Error management

### Bonus Features
- Enemy patrols with animations
- Move counter directly on screen
- Player sprite animations
- Additional visual effects

## 🎨 Textures
```
textures/
├── animation_enemy_1.xpm   # Enemy animation frames
├── animation_enemy_2.xpm
├── back.xpm                # Player directions
├── front.xpm
├── left.xpm
├── right.xpm
├── coin.xpm                # Collectibles
├── ground_1.xpm           # Ground tiles
├── nimbus.xpm             # Player sprites
├── rock.xpm               # Obstacles
└── wall_*.xpm             # Wall variations
```

## 📁 Project Structure

### Mandatory Implementation
```
mandatory/
├── so_long.c          # Main program
├── so_long.h          # Header file
├── arr_utils.c        # Array utilities
├── check_xpm.c        # Texture validation
├── cordinations.c     # Position handling
├── movements.c        # Player movement
├── parsing_*.c        # Map parsing
├── render_pixels_*.c  # Rendering functions
└── struct_utils.c     # Structure utilities
```

### Bonus Implementation
```
so_long_bonus/
├── so_long_bonus.c
├── so_long_bonus.h
├── enemy_animation_and_movements.c
└── [bonus feature files]
```

## 🗺️ Map Format
- 1: Wall
- 0: Empty space
- P: Player starting position
- E: Exit
- C: Collectible
- X: Enemy (bonus)

Example:
```
1111111111
10C0000001
1000P00C01
1000011111
1000000001
1E00000001
1111111111
```

## 🛠️ Compilation & Usage

### Requirements
- MinilibX library
- Mac OS X or Linux
- Make

### Compilation
```bash
make        # Compile mandatory part
make bonus  # Compile with bonus features
```

### Running the Game
```bash
./so_long maps/map_1.ber        # Mandatory version
./so_long_bonus maps/map_2.ber  # Bonus version
```

## 🎮 Controls
- `W` or `↑`: Move up
- `S` or `↓`: Move down
- `A` or `←`: Move left
- `D` or `→`: Move right
- `ESC`: Quit game

## ⚠️ Error Handling
- Invalid map format
- Missing textures
- Memory allocation failures
- Invalid file extension
- Invalid map configuration
- Missing map components

## 🔍 Game Mechanics
- Collect all items before reaching exit
- Avoid enemies (bonus version)
- Minimize move count
- Navigate through obstacles
- Strategic path planning

## 🧪 Map Validation
- Rectangular shape
- Closed borders
- Valid path existence
- Required elements presence
- Valid character set
- Proper file extension (.ber)

## 🎯 Performance Optimizations
- Efficient rendering
- Memory management
- Collision detection
- Animation handling

## 📜 License

This project is part of the 42 curriculum and is provided as-is.
