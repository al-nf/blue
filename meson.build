project('blue', 'c')

sources = files('src/core.c', 'src/main.c', 'src/platform.c')

inc_local = include_directories('inc')

host_system = host_machine.system()

extra_includes = []
extra_deps = []
extra_link_args = []

if host_system == 'windows'
  extra_includes += include_directories('C:/SDL3/include')
  extra_link_args += [
    'C:/SDL3/lib/x64/SDL3.lib',
    'user32.lib',
    'gdi32.lib',
    'dxguid.lib',
    'winmm.lib',
  ]
elif host_system == 'darwin'
  sdl3_dep = dependency('sdl3', required: false)

  if sdl3_dep.found()
    extra_deps += sdl3_dep
  else
    extra_includes += include_directories('/Library/Frameworks/SDL3.framework/Headers')
    extra_link_args += ['-F/Library/Frameworks', '-framework', 'SDL3']
  endif
elif host_system == 'linux'
  extra_deps += dependency('sdl3')
else
  error('Unsupported operating system: ' + host_system)
endif

executable(
  'main',
  sources,
  include_directories: [inc_local] + extra_includes,
  dependencies: extra_deps,
  link_args: extra_link_args,
)

executable(
  'simpletest',
  ['src/core.c', 'src/platform.c', 'src/test.c'],
  include_directories: [inc_local] + extra_includes,
  dependencies: extra_deps,
  link_args: extra_link_args,
)
