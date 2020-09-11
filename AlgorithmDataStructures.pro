TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += /std:c++17

SOURCES += src/main.cc \
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
    src/algorithms/search.h \
    src/algorithms/util.h \
    src/data_structures/array.h \
    src/data_structures/fixedarray.h
