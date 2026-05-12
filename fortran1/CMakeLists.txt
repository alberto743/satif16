cmake_minimum_required(VERSION 3.10)
project(attenuation
    VERSION 1.0.0
    LANGUAGES Fortran
)

include(GNUInstallDirs)
enable_testing()

add_executable(attenuation
    attenuation.f90
)

install(TARGETS attenuation
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


set(TEST_RUN_DIR "${CMAKE_CURRENT_BINARY_DIR}/test_attenuation_env")
file(MAKE_DIRECTORY "${TEST_RUN_DIR}")
add_test(NAME setup_test_attenuation
    COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/data.txt"
        "${TEST_RUN_DIR}"
)
add_test(NAME test_attenuation
    COMMAND attenuation
    WORKING_DIRECTORY "${TEST_RUN_DIR}"
)
