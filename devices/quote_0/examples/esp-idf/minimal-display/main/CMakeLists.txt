set(QUOTE_0_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../../..")

idf_component_register(
    SRCS
        "quote_0_minimal_display_example.c"
        "${QUOTE_0_ROOT}/firmware-resources/display/drivers/uc8251d_minimal.c"
    INCLUDE_DIRS
        "."
        "${QUOTE_0_ROOT}/firmware-resources/display/drivers"
)
