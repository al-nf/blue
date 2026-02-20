project('blue', 'c')

inc_sdl3 = include_directories('C:/SDL3/include')

executable(
  'main',
  'main.c',
  include_directories: inc_sdl3,
  link_args: [
    'C:/SDL3/lib/x64/SDL3.lib',
    'user32.lib',
    'gdi32.lib',
    'dxguid.lib',
    'winmm.lib',
  ],
)
