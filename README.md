# 🧭 Pathfinding Visualizer - C++ & OpenGL

A dy---

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
g++ -o pathfinder.exe graph.cpp -I"freeglut/include" -L"freeglut/lib" -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows
```

### Run
```bash
./pathfinder.exe
```

---

## 🔍 Algorithm Details

**Dijkstra's Algorithm Implementation:**
- **Single-source shortest path** algorithm
- **8-directional movement** (horizontal, vertical, diagonal)
- **Distance weights**: 1.0 for H/V moves, 1.4 for diagonal moves
- **Priority queue** for optimal node selection
- **Real-time visualization** at 60 FPS
- **Unreachable destination detection** with restart prompt

### Algorithm Features:
- ✅ **Guaranteed shortest path**
- ✅ **Handles unreachable destinations**
- ✅ **Interactive wall placement**
- ✅ **Real-time step-by-step visualization**

---tive Pathfinding Visualizer that demonstrates how Dijkstra's algorithm works in real-time. Built using **C++** and **OpenGL**, this project lets users create custom grids, place start/end points, add walls, and watch the shortest path unfold step by step.

**Created by Anuj Tyagi from IIT Guwahati, Department of Chemical Engineering**

## 🚀 Features

- 🟩 **Set Start & End Nodes**
- 🧠 **Visualize Dijkstra's Algorithm**
- 🎨 **Smooth OpenGL Rendering**
- 🖱️ **Mouse & Keyboard Interactions**
- 🔄 **Step-by-step Pathfinding Animation**
- 🚧 **Interactive Wall Placement**
- ⚠️ **Unreachable Destination Detection**
- 🔄 **Easy Reset Functionality**nding Visualizer - C++ & OpenGL

A dynamic, interactive Pathfinding Visualizer that demonstrates how Dijkstra's algorithm works in real-time. Built using **C++** and **OpenGL**, this project lets users create custom grids, place start/end points and watch the shortest path unfold step by step.

## 🚀 Features

- 🟩 **Set Start & End Nodes**
- 🧠 **Visualize Dijkstra’s Algorithm**
- 🎨 **Smooth OpenGL Rendering**
- 🖱️ **Mouse & Keyboard Interactions**
- 🔄 **Step-by-step Pathfinding Animation**

---

## 🎮 How to Use

| Action | Mouse/Keyboard |
|--------|----------------|
| **Start Application** | Press `Enter` on intro screen |
| **Place Source Node** | `Left Click` (first click) |
| **Place Destination Node** | `Left Click` (second click) |
| **Add Walls** | `Left Click` (after source & dest) |
| **Remove Nodes** | `Right Click` |
| **Start Pathfinding** | Press `S` or `s` |
| **Reset Grid** | Press `R` or `r` |
| **Quit Application** | Press `ESC` |

### 🎯 Visual Guide
- **🟣 Purple**: Source node
- **🟪 Light Purple**: Destination node  
- **🔴 Red with X**: Walls/obstacles
- **🔵 Cyan**: Nodes being explored
- **🟡 Yellow**: Final shortest path
- **⚠️ Red Message**: "DESTINATION UNREACHABLE! Press 'R' to Restart"

---

## 🛠️ Tech Stack

- **Language**: C++
- **Graphics**: OpenGL & GLUT
- **IDE/Compiler**: Visual Studio / g++ / Code::Blocks

---

## 🔍 Algorithms

Currently implemented:
- ✅ **Dijkstra’s Algorithm** (Guaranteed shortest path)
## 🎓 Educational Value

This project demonstrates:
- **Graph algorithms** in action
- **Priority queue** data structures
- **OpenGL graphics programming**
- **Real-time algorithm visualization**
- **Interactive application development**

Perfect for:
- 📚 **Computer Science students**
- 🎯 **Algorithm learning**
- 🎮 **Interactive demonstrations**
- 💻 **OpenGL programming practice**

---

## 📁 Project Structure

```
📦 OpenGL-Pathfinding-Visualizer/
├── 📄 graph.cpp              # Main source code
├── 📄 pathfinder.exe         # Compiled executable
├── 📄 freeglut.dll          # Required library
├── 📁 freeglut/             # FreeGLUT library files
├── 📁 demo/                 # Demo screenshots/GIFs
├── 📄 README.md             # Project documentation
└── 📄 LICENSE               # MIT License
```

---

## 🙌 Credits

- **Developer**: Anuj Tyagi
- **Institution**: Indian Institute of Technology Guwahati
- **Department**: Chemical Engineering
- **Graphics Library**: FreeGLUT and OpenGL
- **Algorithm**: Edsger W. Dijkstra's shortest path algorithm



