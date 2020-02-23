project('util', 'c')

# Dependencies
cc = meson.get_compiler('c')
libc = cc.find_library('c')
libm = cc.find_library('m')

# Args
c_args = [
  '-std=c90',
  '-pedantic-errors',
  '-Wall',
  '-Wconversion'
]

# Library
libutil = library(
  'util',
  [
    'src/util_common.c',
    'src/util_core.c',
    'include/util.h'
  ],
  include_directories: 'include',
  c_args: c_args,
  link_args: [ '--no-standard-libraries' ],
  dependencies: [
    libc,
    libm
  ]
)

libutil_dep = declare_dependency(
  include_directories: 'include',
  link_with: [ libutil ],
  dependencies: [
    libc,
    libm
  ]
)
