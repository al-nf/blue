project('blue', 'c')

inc_sdl3 = include_directories('C:/Users/alanf/SDL3-3.4.0/include')

executable(
  'main',
  'main.c',
  include_directories: inc_sdl3,
  link_args: [
    'C:/Users/alanf/SDL3-3.4.0/lib/x64/SDL3.lib',
    'user32.lib',
    'gdi32.lib',
    'dxguid.lib',
    'winmm.lib',
  ],
)
