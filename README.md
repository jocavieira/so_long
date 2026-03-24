# 🕹️ so_long

A simple 2D game developed in C using the MiniLibX graphical library as part of the 42 School curriculum.

---

## 📖 About

**so_long** is a small tile-based 2D game where the player must collect all collectibles and reach the exit.

The project focuses on:
- Graphics programming with MiniLibX
- Event-driven programming
- Map parsing and validation
- Memory management
- Game loop implementation

---

## 🎮 Gameplay

- Move through the map using keyboard inputs
- Collect all collectibles (`C`)
- Reach the exit (`E`) after collecting everything
- Avoid walls (`1`)

---

## 🗺️ Map Format

Example:

111111
1P0C01
100001
1C0E01
111111

### Legend:
- `1` → Wall  
- `0` → Empty space  
- `P` → Player  
- `C` → Collectible  
- `E` → Exit  

---

## ⚙️ Installation

```bash
git clone https://github.com/jocavieira/so_long.git
cd so_long
make
```

---

## ▶️ Usage

```bash
./so_long maps/map.ber
```

---

## 🧠 Features

- ✔️ Map validation:
  - Rectangular shape
  - Surrounded by walls
  - Valid path (player can reach exit and collectibles)
- ✔️ Player movement with key inputs
- ✔️ Move counter in terminal
- ✔️ Sprite rendering with layering (floor + objects)
- ✔️ Clean window and memory management

---

## 🖼️ Graphics

This project uses **MiniLibX**, a lightweight graphical library provided by 42.
