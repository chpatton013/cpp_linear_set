package(default_visibility=["//visibility:public"])

cc_library(
    name="linear_set",
    srcs=["linear_set.h"],
    hdrs=["linear_set.h"],
)

cc_test(
    name="linear_set_test",
    srcs=["linear_set_test.cpp"],
    deps=[
        ":linear_set",
        "//external:gtest_main",
    ],
)

cc_library(
    name="linear_map",
    srcs=["linear_map.h"],
    hdrs=["linear_map.h"],
    deps=[":linear_set"],
)

cc_test(
    name="linear_map_test",
    srcs=["linear_map_test.cpp"],
    deps=[
        ":linear_map",
        "//external:gtest_main",
    ],
)
