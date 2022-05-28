project('cmocka_test', 'c')

cmocka = dependency('cmocka')

code = library(
  'code',
  files('code.c'),
)

memory_test = executable(
  'memory_test',
  files('test.c'),
  link_args : [
    '-Wl,--wrap=malloc',
    '-Wl,--wrap=calloc',
    '-Wl,--wrap=realloc',
    '-Wl,--wrap=free',
  ],
  dependencies : [ cmocka ],
  objects: code.extract_objects(files('code.c')),
)

test('main test', memory_test)
