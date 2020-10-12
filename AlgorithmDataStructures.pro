TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += /std:c++17

SOURCES += \
    src/algorithms/ut8string.cc \
    src/data_structures/string.cc \
    src/main.cc \
    src/recursion/ascending_descending.cc \
    src/recursion/calling_order.cc \
    src/recursion/factorial.cc \
    src/recursion/indirect.cc \
    src/recursion/natural_summation.cc \
    src/recursion/nested.cc \
    src/recursion/power.cc \
    src/recursion/tail_head.cc \
    src/recursion/template_indirect.cc \
    src/recursion/tree_recursion.cc

HEADERS += \
    src/algorithms/binary_search.h \
    src/algorithms/numbers_util.h \
    src/algorithms/reserve_rotate_shift.h \
    src/algorithms/search.h \
    src/algorithms/slow_sorting.h \
    src/algorithms/sorting.h \
    src/algorithms/ut8string.h \
    src/algorithms/util.h \
    src/data_structures/array.h \
    src/data_structures/fixed_stack.h \
    src/data_structures/fixedarray.h \
    src/data_structures/linked_list.h \
    src/data_structures/queue.h \
    src/data_structures/stack.h \
    src/data_structures/string.h
