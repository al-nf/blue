# prereqs
1. install meson and ninja-build
2. install visual studio
3. install sdl3 from github (it should end in VC.zip)
3. open "x64 native tools command prompt for vs"
4. `meson setup build`
5. extract SDL3 from the zip file, rename it to SDL3, then put it in C:
6. copy C:/SDL3/lib/x64/SDL3.dll and put it in build/
7. `meson compile -C build"
8. the compiled binary should be in build/
