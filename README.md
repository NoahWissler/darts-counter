# darts-counter
it counts darts and more.

A simple Qt-based darts score counter application. It helps track scores during darts games (and more features coming soon!).
It is a usable MVP but is not currently being developed further – "it counts darts and more. not yet tho (mostly)." 😏

## Table of Contents

- [Screenshots](#Screenshots)
- [Features](#Features)
- [Download & Run (Pre-built)](#Download_&_Run_(Pre-built))
- [Building from Source](#Building_from_Source)
- [Notes](#Notes)
- [Contributing](#Contributing)
- [License](#License)
- [Conclusion](#Conclusion)

## Screenshots
![image alt](https://github.com/NoahWissler/darts-counter/blob/main/Darts%20Counter%20GitHub%20Screenshot.png?raw=true)

## Features

- Score tracking for darts games
- Clean UI with labels for player scores and buttons for input
- Custom stylesheet support (Darkeum theme but slightly modified)
- Custom window and executable icon (source at the bottom)
- Responsive layout (split into sections for display and controls)
More features planned!

## Download & Run Pre-built

For most users: Download the latest portable version from the Releases page.

- Unzip the folder.
- Run darts-counter.exe.
No installation needed – all Qt DLLs are included.

## Building from Source
This project uses CMake and Qt 6. It's developed and tested on Windows.

## Prerequisites

- CMake (3.21 or higher): Download from cmake.org.
- Qt 6: Install via the Qt Online Installer (open-source edition).
   - Recommended: A desktop kit like "Qt 6.x.x MinGW 64-bit" or "MSVC".

- Compiler:
   - MinGW (included with Qt installer) or
   - Microsoft Visual Studio (with C++ support) for MSVC kits.

- Git (to clone the repo).

## Steps

1. Clone the repository:
   git clone https://github.com/NoahWissler/darts-counter.git
   cd darts-counter
2. Recommended: Use Qt Creator
 - Open Qt Creator.
 - File → Open File or Project → Select CMakeLists.txt.
 - Configure with your Qt kit.
 - Switch to Release mode (bottom-left toolbar).
 - Build → Build All (Ctrl+B).

3. Command Line Build

   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH="C:/Qt/6.x.x/mingw_64" -DCMAKE_BUILD_TYPE=Release
   cmake --build . --config Release

   (Adjust the Qt path to your installation, e.g., msvc2019_64 for Visual Studio.)

The executable will be in the build directory.

## Running on Windows
The project automatically runs windeployqt in Release mode (via CMake post-build step) to copy
required Qt DLLs, plugins (e.g., platforms/qwindows.dll), and resources (like the stylesheet).

If DLLs are missing or the app won't start:
- Open a command prompt in the build folder.
- Run:
  windeployqt darts-counter.exe --release
  (Use the full path to windeployqt.exe if needed, e.g.,
   C:\Qt\6.x.x\mingw_64\bin\windeployqt.exe.)

After this, the folder is portable – you can zip it and share/run anywhere.

## Notes

- Custom icon: Embedded via .rc file (Windows only).
- Stylesheet: Darkeum.qss is copied/handled automatically.
- Layout: Uses nested layouts in .ui files for a split view (display on top, controls below).

## Contributing

Feel free to open issues or pull requests! Ideas for new features (e.g., multiple players,checkout suggestions, ...) are welcome.

## License

no license.

## Conclusion

Made with ❤️ (and a lot of frustration like always) by Noah Wissler
Enjoy throwing darts! 🎯

source of the icon:
<a href="https://www.flaticon.com/free-icons/dart" title="dart icons">Dart icons created by Smashicons - Flaticon</a>
