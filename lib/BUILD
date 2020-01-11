load(
    "@rules_proto//proto:defs.bzl",
    "proto_library",
)
load(
    "@rules_cc//cc:defs.bzl",
    "cc_library",
)
load(
    "@rules_cc//examples:experimental_cc_shared_library.bzl",
    "cc_shared_library",
)
load(
    "@com_google_protobuf//:protobuf.bzl",
    "cc_proto_library",
)

cc_shared_library(
    name = "name_utils_dynamic_lib",
    exports = [":name_utils"],
)

cc_library(
    name = "name_utils",
    srcs = ["name_utils.cc"],
    hdrs = ["name_utils.h"],
    linked_statically_by = ["//lib:name_utils_dynamic_lib"],
    deps = [
        ":name_cc_proto",
        "@com_google_absl//absl/strings",
        "@com_google_protobuf//:protobuf",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":name_cc_proto",
        ":name_utils",
    ],
)

cc_binary(
    name = "main_with_dynamic_deps",
    srcs = ["main.cc"],
    dynamic_deps = [
        ":name_utils_dynamic_lib",
    ],
)

proto_library(
    name = "name_proto",
    srcs = ["name.proto"],
)

cc_proto_library(
    name = "name_cc_proto",
    srcs = [
        "name.proto",
    ],
    linked_statically_by = ["//lib:name_utils_dynamic_lib"],
)
