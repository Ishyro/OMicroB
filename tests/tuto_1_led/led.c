#define OCAML_STACK_WOSIZE               200
#define OCAML_STATIC_HEAP_WOSIZE         123
#define OCAML_DYNAMIC_HEAP_WOSIZE         77
#define OCAML_FLASH_HEAP_WOSIZE           53
#define OCAML_STACK_INITIAL_WOSIZE         3
#define OCAML_RAM_GLOBDATA_NUMBER          0
#define OCAML_FLASH_GLOBDATA_NUMBER        0
#define OCAML_BYTECODE_BSIZE              52
#define OCAML_PRIMITIVE_NUMBER             3
#define OCAML_VIRTUAL_ARCH                32
#define OCAML_STARTING_OOID                2
#define OCAML_NO_FLASH_HEAP                0
#define OCAML_NO_FLASH_GLOBALS             0

#define OCAML_GC_MARK_AND_COMPACT

#include </home/ishyro/Documents/Info/M1/S2/OMicroB/src/byterun/vm/values.h>

#define OCAML_ACC1                        0
#define OCAML_PUSH                        1
#define OCAML_PUSHACC2                    2
#define OCAML_PUSHACC5                    3
#define OCAML_POP                         4
#define OCAML_ASSIGN                      5
#define OCAML_MAKEBLOCK2                  6
#define OCAML_GETFIELD0                   7
#define OCAML_SETFIELD0                   8
#define OCAML_BRANCHIF_1B                 9
#define OCAML_CHECK_SIGNALS              10
#define OCAML_C_CALL2                    11
#define OCAML_C_CALL3                    12
#define OCAML_CONST0                     13
#define OCAML_CONST1                     14
#define OCAML_CONST2                     15
#define OCAML_PUSHCONST0                 16
#define OCAML_PUSHCONSTINT_1B            17
#define OCAML_NEQ                        18
#define OCAML_GTINT                      19
#define OCAML_OFFSETINT_1B               20
#define OCAML_STOP                       21

value ocaml_stack[OCAML_STACK_WOSIZE];
value ocaml_ram_heap[OCAML_STATIC_HEAP_WOSIZE + OCAML_DYNAMIC_HEAP_WOSIZE];
value ocaml_ram_global_data[OCAML_RAM_GLOBDATA_NUMBER];

PROGMEM value const ocaml_flash_heap[OCAML_FLASH_HEAP_WOSIZE] = {
  /*  0 */  Make_header(0, 0, Color_white),
  /*  1 */  Make_header(2, Object_tag, Color_white),
  /*  2 */  Val_flash_block(&ocaml_flash_heap[5]),
  /*  3 */  Val_int(-1),
  /*  4 */  Make_header(4, String_tag, Color_white),
  /*  5 */  Make_string_data('O', 'u', 't', '_'),
  /*  6 */  Make_string_data('o', 'f', '_', 'm'),
  /*  7 */  Make_string_data('e', 'm', 'o', 'r'),
  /*  8 */  Make_string_data('y', '\0', '\0', '\2'),
  /*  9 */  Make_header(2, Object_tag, Color_white),
  /* 10 */  Val_flash_block(&ocaml_flash_heap[13]),
  /* 11 */  Val_int(-3),
  /* 12 */  Make_header(2, String_tag, Color_white),
  /* 13 */  Make_string_data('F', 'a', 'i', 'l'),
  /* 14 */  Make_string_data('u', 'r', 'e', '\0'),
  /* 15 */  Make_header(2, Object_tag, Color_white),
  /* 16 */  Val_flash_block(&ocaml_flash_heap[19]),
  /* 17 */  Val_int(-4),
  /* 18 */  Make_header(5, String_tag, Color_white),
  /* 19 */  Make_string_data('I', 'n', 'v', 'a'),
  /* 20 */  Make_string_data('l', 'i', 'd', '_'),
  /* 21 */  Make_string_data('a', 'r', 'g', 'u'),
  /* 22 */  Make_string_data('m', 'e', 'n', 't'),
  /* 23 */  Make_string_data('\0', '\0', '\0', '\3'),
  /* 24 */  Make_header(2, Object_tag, Color_white),
  /* 25 */  Val_flash_block(&ocaml_flash_heap[28]),
  /* 26 */  Val_int(-6),
  /* 27 */  Make_header(5, String_tag, Color_white),
  /* 28 */  Make_string_data('D', 'i', 'v', 'i'),
  /* 29 */  Make_string_data('s', 'i', 'o', 'n'),
  /* 30 */  Make_string_data('_', 'b', 'y', '_'),
  /* 31 */  Make_string_data('z', 'e', 'r', 'o'),
  /* 32 */  Make_string_data('\0', '\0', '\0', '\3'),
  /* 33 */  Make_header(2, Object_tag, Color_white),
  /* 34 */  Val_flash_block(&ocaml_flash_heap[37]),
  /* 35 */  Val_int(-9),
  /* 36 */  Make_header(4, String_tag, Color_white),
  /* 37 */  Make_string_data('S', 't', 'a', 'c'),
  /* 38 */  Make_string_data('k', '_', 'o', 'v'),
  /* 39 */  Make_string_data('e', 'r', 'f', 'l'),
  /* 40 */  Make_string_data('o', 'w', '\0', '\1'),
  /* 41 */  Make_header(2, 0, Color_white),
  /* 42 */  Val_int(1),
  /* 43 */  Val_flash_block(&ocaml_flash_heap[45]),
  /* 44 */  Make_header(2, 0, Color_white),
  /* 45 */  Val_int(2),
  /* 46 */  Val_flash_block(&ocaml_flash_heap[48]),
  /* 47 */  Make_header(2, 0, Color_white),
  /* 48 */  Val_int(3),
  /* 49 */  Val_flash_block(&ocaml_flash_heap[51]),
  /* 50 */  Make_header(2, 0, Color_white),
  /* 51 */  Val_int(4),
  /* 52 */  Val_unit
};

PROGMEM value const ocaml_initial_static_heap[OCAML_STATIC_HEAP_WOSIZE] = {
  /*   0 */  Make_header(10, 0, Color_white),
  /*   1 */  Val_static_block(&ocaml_ram_heap[12]),
  /*   2 */  Val_static_block(&ocaml_ram_heap[23]),
  /*   3 */  Val_static_block(&ocaml_ram_heap[34]),
  /*   4 */  Val_static_block(&ocaml_ram_heap[45]),
  /*   5 */  Val_static_block(&ocaml_ram_heap[56]),
  /*   6 */  Val_static_block(&ocaml_ram_heap[67]),
  /*   7 */  Val_static_block(&ocaml_ram_heap[78]),
  /*   8 */  Val_static_block(&ocaml_ram_heap[89]),
  /*   9 */  Val_static_block(&ocaml_ram_heap[100]),
  /*  10 */  Val_static_block(&ocaml_ram_heap[111]),
  /*  11 */  Make_header(10, 0, Color_white),
  /*  12 */  Val_int(1),
  /*  13 */  Val_int(1),
  /*  14 */  Val_int(1),
  /*  15 */  Val_int(1),
  /*  16 */  Val_int(1),
  /*  17 */  Val_int(1),
  /*  18 */  Val_int(1),
  /*  19 */  Val_int(1),
  /*  20 */  Val_int(1),
  /*  21 */  Val_int(1),
  /*  22 */  Make_header(10, 0, Color_white),
  /*  23 */  Val_int(1),
  /*  24 */  Val_int(1),
  /*  25 */  Val_int(1),
  /*  26 */  Val_int(1),
  /*  27 */  Val_int(1),
  /*  28 */  Val_int(1),
  /*  29 */  Val_int(1),
  /*  30 */  Val_int(1),
  /*  31 */  Val_int(1),
  /*  32 */  Val_int(1),
  /*  33 */  Make_header(10, 0, Color_white),
  /*  34 */  Val_int(1),
  /*  35 */  Val_int(1),
  /*  36 */  Val_int(1),
  /*  37 */  Val_int(1),
  /*  38 */  Val_int(1),
  /*  39 */  Val_int(1),
  /*  40 */  Val_int(1),
  /*  41 */  Val_int(1),
  /*  42 */  Val_int(1),
  /*  43 */  Val_int(1),
  /*  44 */  Make_header(10, 0, Color_white),
  /*  45 */  Val_int(1),
  /*  46 */  Val_int(1),
  /*  47 */  Val_int(1),
  /*  48 */  Val_int(1),
  /*  49 */  Val_int(1),
  /*  50 */  Val_int(1),
  /*  51 */  Val_int(1),
  /*  52 */  Val_int(1),
  /*  53 */  Val_int(1),
  /*  54 */  Val_int(1),
  /*  55 */  Make_header(10, 0, Color_white),
  /*  56 */  Val_int(1),
  /*  57 */  Val_int(1),
  /*  58 */  Val_int(1),
  /*  59 */  Val_int(1),
  /*  60 */  Val_int(1),
  /*  61 */  Val_int(1),
  /*  62 */  Val_int(1),
  /*  63 */  Val_int(1),
  /*  64 */  Val_int(1),
  /*  65 */  Val_int(1),
  /*  66 */  Make_header(10, 0, Color_white),
  /*  67 */  Val_int(1),
  /*  68 */  Val_int(1),
  /*  69 */  Val_int(1),
  /*  70 */  Val_int(1),
  /*  71 */  Val_int(1),
  /*  72 */  Val_int(1),
  /*  73 */  Val_int(1),
  /*  74 */  Val_int(1),
  /*  75 */  Val_int(1),
  /*  76 */  Val_int(1),
  /*  77 */  Make_header(10, 0, Color_white),
  /*  78 */  Val_int(1),
  /*  79 */  Val_int(1),
  /*  80 */  Val_int(1),
  /*  81 */  Val_int(1),
  /*  82 */  Val_int(1),
  /*  83 */  Val_int(1),
  /*  84 */  Val_int(1),
  /*  85 */  Val_int(1),
  /*  86 */  Val_int(1),
  /*  87 */  Val_int(1),
  /*  88 */  Make_header(10, 0, Color_white),
  /*  89 */  Val_int(1),
  /*  90 */  Val_int(1),
  /*  91 */  Val_int(1),
  /*  92 */  Val_int(1),
  /*  93 */  Val_int(1),
  /*  94 */  Val_int(1),
  /*  95 */  Val_int(1),
  /*  96 */  Val_int(1),
  /*  97 */  Val_int(1),
  /*  98 */  Val_int(1),
  /*  99 */  Make_header(10, 0, Color_white),
  /* 100 */  Val_int(1),
  /* 101 */  Val_int(1),
  /* 102 */  Val_int(1),
  /* 103 */  Val_int(1),
  /* 104 */  Val_int(1),
  /* 105 */  Val_int(1),
  /* 106 */  Val_int(1),
  /* 107 */  Val_int(1),
  /* 108 */  Val_int(1),
  /* 109 */  Val_int(1),
  /* 110 */  Make_header(10, 0, Color_white),
  /* 111 */  Val_int(1),
  /* 112 */  Val_int(1),
  /* 113 */  Val_int(1),
  /* 114 */  Val_int(1),
  /* 115 */  Val_int(1),
  /* 116 */  Val_int(1),
  /* 117 */  Val_int(1),
  /* 118 */  Val_int(1),
  /* 119 */  Val_int(1),
  /* 120 */  Val_int(1),
  /* 121 */  Make_header(1, 0, Color_white),
  /* 122 */  Val_flash_block(&ocaml_flash_heap[42])
};

PROGMEM value const ocaml_initial_stack[OCAML_STACK_INITIAL_WOSIZE] = {
  /* 0 */  Val_int(127),
  /* 1 */  Val_static_block(&ocaml_ram_heap[1]),
  /* 2 */  Val_static_block(&ocaml_ram_heap[122])
};

PROGMEM value const ocaml_flash_global_data[OCAML_FLASH_GLOBDATA_NUMBER] = {
};

value acc = Val_int(5);
value env = Val_unit;

#define OCAML_Out_of_memory        Val_flash_block(&ocaml_flash_heap[2])
#define OCAML_Failure              Val_flash_block(&ocaml_flash_heap[10])
#define OCAML_Invalid_argument     Val_flash_block(&ocaml_flash_heap[16])
#define OCAML_Division_by_zero     Val_flash_block(&ocaml_flash_heap[25])
#define OCAML_Stack_overflow       Val_flash_block(&ocaml_flash_heap[34])

#define OCAML_atom0                Val_flash_block(&ocaml_flash_heap[1])

PROGMEM opcode_t const ocaml_bytecode[OCAML_BYTECODE_BSIZE] = {
  /*  0 */  OCAML_C_CALL2, 0,
  /*  2 */  OCAML_CONST0,
  /*  3 */  OCAML_PUSHCONSTINT_1B, 9,
  /*  5 */  OCAML_PUSH,
  /*  6 */  OCAML_PUSHACC2,
  /*  7 */  OCAML_GTINT,
  /*  8 */  OCAML_BRANCHIF_1B, 21,
  /* 10 */  OCAML_CHECK_SIGNALS,
  /* 11 */  OCAML_CONST2,
  /* 12 */  OCAML_PUSHACC2,
  /* 13 */  OCAML_PUSHCONST0,
  /* 14 */  OCAML_PUSHACC5,
  /* 15 */  OCAML_C_CALL2, 1,
  /* 17 */  OCAML_C_CALL3, 2,
  /* 19 */  OCAML_ACC1,
  /* 20 */  OCAML_PUSH,
  /* 21 */  OCAML_OFFSETINT_1B, 1,
  /* 23 */  OCAML_ASSIGN, 2,
  /* 25 */  OCAML_ACC1,
  /* 26 */  OCAML_NEQ,
  /* 27 */  OCAML_BRANCHIF_1B, (opcode_t) -17,
  /* 29 */  OCAML_POP, 2,
  /* 31 */  OCAML_ACC1,
  /* 32 */  OCAML_GETFIELD0,
  /* 33 */  OCAML_PUSHCONSTINT_1B, 8,
  /* 35 */  OCAML_MAKEBLOCK2, 0,
  /* 37 */  OCAML_PUSHACC2,
  /* 38 */  OCAML_SETFIELD0,
  /* 39 */  OCAML_CONST1,
  /* 40 */  OCAML_PUSHCONST0,
  /* 41 */  OCAML_PUSHACC2,
  /* 42 */  OCAML_C_CALL2, 1,
  /* 44 */  OCAML_C_CALL2, 1,
  /* 46 */  OCAML_PUSHCONST0,
  /* 47 */  OCAML_C_CALL2, 0,
  /* 49 */  OCAML_POP, 2,
  /* 51 */  OCAML_STOP
};

#include </home/ishyro/Documents/Info/M1/S2/OMicroB/src/byterun/vm/runtime.c>

PROGMEM void * const ocaml_primitives[OCAML_PRIMITIVE_NUMBER] = {
  /*  0 */  (void *) &caml_avr_write_register,
  /*  1 */  (void *) &caml_array_get_addr,
  /*  2 */  (void *) &caml_array_set_addr,
};
