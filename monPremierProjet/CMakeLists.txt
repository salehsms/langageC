project(projet) # nom du projet

set(SRCS main.cpp board.cpp view.cpp )
set(SRCS_TEST test_fn.cpp board.cpp)
set(SRCS_TMASK test_mask.cpp view.cpp mask.cpp board.cpp)

set(SRCS_THUMAN one_run_human_test.cpp view.cpp mask.cpp board.cpp game.cpp)

set(HEADERS types.hpp board.hpp view.hpp mask.hpp game.hpp)


add_executable(main ${SRCS} ${HEADERS} )
add_executable(test_fn ${SRCS_TEST} ${HEADERS})
add_executable(test_mask ${SRCS_TMASK} ${HEADERS})
add_executable(test_human ${SRCS_THUMAN} ${HEADERS})

