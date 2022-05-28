# Testing cmocka malloc / free wrapping

code.(c|h) represents the projects source and is build as library.
The fuction `foo` allocates memory. Comment out the `free` call to create a memory leak.

test.c is the cmocka test code. It calls `foo`

The test executable reuses the objects from the library and wrapps all malloc / calloc / realloc / free
calls to the cmocka test ones.

## Run
  $ meson build
  $ ninja -C build test  // the test suite terminates successfull
  // comment out the `free` call in `code.c`
  $ ninja -C build test  // the test suite fails now

## Notes
  The `shell.nix` is setting up the environment with NIX. You don't need it. Just install the listed
  packages.
