project('libutil', 'c')

# Native libs
cc = meson.get_compiler('c')
libc = cc.find_library('c')

deps = [ libc ]

# C args
args = [
  '-std=c90',
  '-pedantic-errors',
  '-Wall',
  '-Wconversion',
  '--no-standard-libraries'
]

# Library
libutil = library(
  'util',
  'src/util.c',
  c_args: args,
  dependencies: deps
)

# External use
libutil_dirs = include_directories('src')
libutil_dep = declare_dependency(
  link_with: libutil,
  include_directories: libutil_dirs,
  dependencies: deps
)
