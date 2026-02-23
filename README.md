## Prerequisites

### macOS
1. Install build tools and SDL3:
   ```
   brew install meson ninja pkg-config sdl3
   ```

### Windows
1. Install meson and ninja-build
2. Install Visual Studio (with C++ development tools)
3. Download SDL3 from GitHub (the file ending in `VC.zip`)
4. Extract SDL3 from the zip file, rename the folder to `SDL3`, then put it in `C:/`
5. Open "x64 Native Tools Command Prompt for VS" (you can close it after this step)

### Linux
1. Install meson and ninja
2. Install SDL3 development libraries (or build from source)

## Building

### macOS / Linux
```bash
meson setup build
meson compile -C build
./build/main
```

**Note for macOS:** If you installed SDL3 via Homebrew and get a pkg-config error, you may need to set the PKG_CONFIG_PATH:
```bash
PKG_CONFIG_PATH=/opt/homebrew/lib/pkgconfig meson setup build
meson compile -C build
./build/main
```

### Windows
1. Run:
   ```
   meson setup build
   ```
2. Copy `C:/SDL3/lib/x64/SDL3.dll` to the `build/` directory
3. Run:
   ```
   meson compile -C build
   ```
4. The compiled binary should be in `build/`
5. Run:
   ```
   ./build/main.exe
   ```

## Project Structure
```
blue/
├── inc/           # includes
│   ├── core.h
│   ├── platform.h
│   └── vec.h
├── src/           # sources
│   ├── main.c
│   ├── platform.c
│   └── core.c
├── meson.build    # build cfg
└── README.md
```
