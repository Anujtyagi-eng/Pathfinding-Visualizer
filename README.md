# 🧭 Pathfinding Visualizer - C++ & OpenGL

A dynamic visual representation of Dijkstra's pathfinding algorithm implemented in C++ using OpenGL and FreeGLUT. This educational tool demonstrates how the algorithm explores nodes to find the shortest path between two points while avoiding obstacles.

**Created by:** Anuj Tyagi  
**Institution:** Indian Institute of Technology Guwahati  
**Department:** Chemical Engineering  
**Date:** July 31, 2025

## 🛠️ Tech Stack

- **Language**: C++
- **Graphics**: OpenGL & FreeGLUT
- **Compiler**: MinGW g++
- **Platform**: Windows
- **Dependencies**: FreeGLUT library

---

## 🚀 Getting Started

### Prerequisites
- MinGW g++ compiler
- FreeGLUT library (included in `freeglut/` folder)

### Compilation
```bash
g++ -o pathfinder.exe graph.cpp -lfreeglut -lopengl32 -lglu32 -L./freeglut/lib -I./freeglut/include
```

### Running
```bash
./pathfinder.exe
```

---

## 🎮 Controls

| Key/Action | Function |
|------------|----------|
| **Enter** | Start from intro screen |
| **Left Click** | Place source (1st), destination (2nd), then monsters |
| **Right Click** | Remove nodes |
| **S** | Start pathfinding visualization |
| **R** | Reset/Restart |
| **ESC** | Exit application |

---

## 🎨 Visual Guide

| Color | Node Type | Description |
|-------|-----------|-------------|
| 🟣 **Purple** | Source | Starting point |
| 🟪 **Light Purple** | Destination | Target point |
| 🟥 **Red + X** | Monsters| Obstacles |
| 🟦 **Cyan** | Checked | Nodes explored by algorithm |
| 🟨 **Yellow** | Path | Final shortest path |

---

## 🔧 Algorithm Details

- **Algorithm**: Dijkstra's Shortest Path
- **Movement**: 8-directional (horizontal, vertical, diagonal)
- **Distance Weights**: 
  - Horizontal/Vertical: 1.0
  - Diagonal: 1.4 (√2)
- **Visualization Speed**: 60 FPS
- **Grid Size**: 40×40

---

## 📚 Educational Value

This visualizer helps understand:
- **Graph traversal algorithms**
- **Priority queue data structures**
- **Shortest path computation**
- **Real-time algorithm visualization**
- **OpenGL graphics programming**

---

## 🏗️ Project Structure

```
OpenGL-Pathfinding-Visualizer/
├── graph.cpp              # Main source code
├── pathfinder.exe          # Compiled executable
├── freeglut.dll           # Required DLL
├── freeglut/              # FreeGLUT library
├── README.md              # Documentation
└── LICENSE                # License file
```

---

## 🎯 Features

- ✅ Real-time pathfinding visualization
- ✅ Interactive node placement
- ✅ Obstacle detection and avoidance
- ✅ Unreachable destination detection
- ✅ Clean, educational interface
- ✅ Fullscreen visualization mode

---

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🙏 Acknowledgments

- **FreeGLUT** for OpenGL utilities
- **MinGW** for Windows compilation
- **OpenGL** for graphics rendering

---

**Made with ❤️ for educational purposes**