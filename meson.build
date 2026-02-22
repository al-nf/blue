project('blue', 'c')

inc_sdl3 = include_directories('C:/SDL3/include')
inc_local = include_directories('inc')

executable(
  'main',
  ['src/main.c', 'src/platform.c', 'src/core.c'],
  include_directories: [inc_sdl3, inc_local],
  link_args: [
    'C:/SDL3/lib/x64/SDL3.lib',
    'user32.lib',
    'gdi32.lib',
    'dxguid.lib',
    'winmm.lib',
  ],
)
