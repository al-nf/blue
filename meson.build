project('blue', 'c')

inc_local = include_directories('inc')

host_system = host_machine.system()

if host_system == 'windows'
  inc_sdl3 = include_directories('C:/SDL3/include')

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
elif host_system == 'darwin'
  sdl3_dep = dependency('sdl3', required: false)

  if not sdl3_dep.found()
    sdl3_framework = '/Library/Frameworks/SDL3.framework'
    inc_sdl3 = include_directories(sdl3_framework / 'Headers')

    executable(
      'main',
      ['src/main.c', 'src/platform.c', 'src/core.c'],
      include_directories: [inc_sdl3, inc_local],
      link_args: ['-F/Library/Frameworks', '-framework', 'SDL3'],
    )
  else
    executable(
      'main',
      ['src/main.c', 'src/platform.c', 'src/core.c'],
      include_directories: [inc_local],
      dependencies: [sdl3_dep],
    )
  endif
elif host_system == 'linux'
  sdl3_dep = dependency('sdl3')

  executable(
    'main',
    ['src/main.c', 'src/platform.c', 'src/core.c'],
    include_directories: [inc_local],
    dependencies: [sdl3_dep],
  )
else
  error('Unsupported operating system: ' + host_system)
endif
