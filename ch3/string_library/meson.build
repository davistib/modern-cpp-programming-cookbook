project(
  'string_library',
  'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20']
)

executable(
  'main',
  'main.cpp',
  install : true
)

# Tests ############################################################################################

# TODO: compile as a static library and link to avoid recompilation

executable(
  'tests',
  'src/string_library_test.cpp',
  'test.cpp',
  install : true,
)
