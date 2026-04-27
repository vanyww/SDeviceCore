#pragma once

#define SDM_PASS(...) __VA_ARGS__

#define SDM_EVAL(action, ...) SDM_EVAL_HELPER_0(action, __VA_ARGS__)
#define SDM_EVAL_HELPER_0(action, ...) action(__VA_ARGS__)

#define SDM_CONCAT(a0, a1) SDM_CONCAT_HELPER_0(a0, a1)
#define SDM_CONCAT_HELPER_0(a0, a1) a0##a1

#define SDM_STRINGIFY(a0) SDM_STRINGIFY_HELPER_0(a0)
#define SDM_STRINGIFY_HELPER_0(a0) #a0

#define SDM_IS_PARENTHESISED(a0) SDM_IS_PARENTHESISED_HELPER_0(SDM_IS_PARENTHESISED_HELPER_1 a0, 1, 0)
#define SDM_IS_PARENTHESISED_HELPER_0(...) SDM_IS_PARENTHESISED_HELPER_0_0(__VA_ARGS__)
#define SDM_IS_PARENTHESISED_HELPER_0_0(u0, u1, is_parenthesised, ...) is_parenthesised
#define SDM_IS_PARENTHESISED_HELPER_1(...) ,

#define SDM_ARGUMENTS_COUNT(...)                                                                                       \
   SDM_ARGUMENTS_COUNT_HELPER_0(, ##__VA_ARGS__,                                                                       \
         31, 30, 29, 28, 27, 26, 25, 24,                                                                               \
         23, 22, 21, 20, 19, 18, 17, 16,                                                                               \
         15, 14, 13, 12, 11, 10,  9,  8,                                                                               \
          7,  6,  5,  4,  3,  2,  1,  0)
#define SDM_ARGUMENTS_COUNT_HELPER_0(                                                                                  \
    u0,  u1,  u2,  u3,  u4,  u5,  u6,  u7,                                                                             \
    u8,  u9, u10, u11, u12, u13, u14, u15,                                                                             \
   u16, u17, u18, u19, u20, u21, u22, u23,                                                                             \
   u24, u25, u26, u27, u28, u29, u30, u31, count, ...) count

#define SDM_OPTIONAL_EXPAND(condition, if_case, else_case)                                                             \
   SDM_CONCAT(SDM_OPTIONAL_EXPAND_HELPER_0_, condition)(if_case, else_case)
#define SDM_OPTIONAL_EXPAND_HELPER_0_0(if_case, else_case) else_case
#define SDM_OPTIONAL_EXPAND_HELPER_0_1(if_case, else_case) if_case

#define SDM_ARGUMENT_0(...)
#define SDM_ARGUMENT_1(a0, ...) a0
#define SDM_ARGUMENT_2(u0, ...) SDM_ARGUMENT_1(__VA_ARGS__)
#define SDM_ARGUMENT_3(u0, ...) SDM_ARGUMENT_2(__VA_ARGS__)
#define SDM_ARGUMENT_4(u0, ...) SDM_ARGUMENT_3(__VA_ARGS__)
#define SDM_ARGUMENT_5(u0, ...) SDM_ARGUMENT_4(__VA_ARGS__)
#define SDM_ARGUMENT_6(u0, ...) SDM_ARGUMENT_5(__VA_ARGS__)
#define SDM_ARGUMENT_7(u0, ...) SDM_ARGUMENT_6(__VA_ARGS__)
#define SDM_ARGUMENT_8(u0, ...) SDM_ARGUMENT_7(__VA_ARGS__)
#define SDM_ARGUMENT_9(u0, ...) SDM_ARGUMENT_8(__VA_ARGS__)
#define SDM_ARGUMENT_10(u0, ...) SDM_ARGUMENT_9(__VA_ARGS__)
#define SDM_ARGUMENT_11(u0, ...) SDM_ARGUMENT_10(__VA_ARGS__)
#define SDM_ARGUMENT_12(u0, ...) SDM_ARGUMENT_11(__VA_ARGS__)
#define SDM_ARGUMENT_13(u0, ...) SDM_ARGUMENT_12(__VA_ARGS__)
#define SDM_ARGUMENT_14(u0, ...) SDM_ARGUMENT_13(__VA_ARGS__)
#define SDM_ARGUMENT_15(u0, ...) SDM_ARGUMENT_14(__VA_ARGS__)
#define SDM_ARGUMENT_16(u0, ...) SDM_ARGUMENT_15(__VA_ARGS__)
#define SDM_ARGUMENT_17(u0, ...) SDM_ARGUMENT_16(__VA_ARGS__)
#define SDM_ARGUMENT_18(u0, ...) SDM_ARGUMENT_17(__VA_ARGS__)
#define SDM_ARGUMENT_19(u0, ...) SDM_ARGUMENT_18(__VA_ARGS__)
#define SDM_ARGUMENT_20(u0, ...) SDM_ARGUMENT_19(__VA_ARGS__)
#define SDM_ARGUMENT_21(u0, ...) SDM_ARGUMENT_20(__VA_ARGS__)
#define SDM_ARGUMENT_22(u0, ...) SDM_ARGUMENT_21(__VA_ARGS__)
#define SDM_ARGUMENT_23(u0, ...) SDM_ARGUMENT_22(__VA_ARGS__)
#define SDM_ARGUMENT_24(u0, ...) SDM_ARGUMENT_23(__VA_ARGS__)
#define SDM_ARGUMENT_25(u0, ...) SDM_ARGUMENT_24(__VA_ARGS__)
#define SDM_ARGUMENT_26(u0, ...) SDM_ARGUMENT_25(__VA_ARGS__)
#define SDM_ARGUMENT_27(u0, ...) SDM_ARGUMENT_26(__VA_ARGS__)
#define SDM_ARGUMENT_28(u0, ...) SDM_ARGUMENT_27(__VA_ARGS__)
#define SDM_ARGUMENT_29(u0, ...) SDM_ARGUMENT_28(__VA_ARGS__)
#define SDM_ARGUMENT_30(u0, ...) SDM_ARGUMENT_29(__VA_ARGS__)
#define SDM_ARGUMENT_31(u0, ...) SDM_ARGUMENT_30(__VA_ARGS__)
#define SDM_ARGUMENT_LAST(...) SDM_CONCAT(SDM_ARGUMENT_, SDM_ARGUMENTS_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define SDM_DROP_0(...) __VA_ARGS__
#define SDM_DROP_1(u0, ...) __VA_ARGS__
#define SDM_DROP_2(a0, u0, ...) a0, ##__VA_ARGS__
#define SDM_DROP_3(a0, ...) a0, SDM_DROP_2(__VA_ARGS__)
#define SDM_DROP_4(a0, ...) a0, SDM_DROP_3(__VA_ARGS__)
#define SDM_DROP_5(a0, ...) a0, SDM_DROP_4(__VA_ARGS__)
#define SDM_DROP_6(a0, ...) a0, SDM_DROP_5(__VA_ARGS__)
#define SDM_DROP_7(a0, ...) a0, SDM_DROP_6(__VA_ARGS__)
#define SDM_DROP_8(a0, ...) a0, SDM_DROP_7(__VA_ARGS__)
#define SDM_DROP_9(a0, ...) a0, SDM_DROP_8(__VA_ARGS__)
#define SDM_DROP_10(a0, ...) a0, SDM_DROP_9(__VA_ARGS__)
#define SDM_DROP_11(a0, ...) a0, SDM_DROP_10(__VA_ARGS__)
#define SDM_DROP_12(a0, ...) a0, SDM_DROP_11(__VA_ARGS__)
#define SDM_DROP_13(a0, ...) a0, SDM_DROP_12(__VA_ARGS__)
#define SDM_DROP_14(a0, ...) a0, SDM_DROP_13(__VA_ARGS__)
#define SDM_DROP_15(a0, ...) a0, SDM_DROP_14(__VA_ARGS__)
#define SDM_DROP_16(a0, ...) a0, SDM_DROP_15(__VA_ARGS__)
#define SDM_DROP_17(a0, ...) a0, SDM_DROP_16(__VA_ARGS__)
#define SDM_DROP_18(a0, ...) a0, SDM_DROP_17(__VA_ARGS__)
#define SDM_DROP_19(a0, ...) a0, SDM_DROP_18(__VA_ARGS__)
#define SDM_DROP_20(a0, ...) a0, SDM_DROP_19(__VA_ARGS__)
#define SDM_DROP_21(a0, ...) a0, SDM_DROP_20(__VA_ARGS__)
#define SDM_DROP_22(a0, ...) a0, SDM_DROP_21(__VA_ARGS__)
#define SDM_DROP_23(a0, ...) a0, SDM_DROP_22(__VA_ARGS__)
#define SDM_DROP_24(a0, ...) a0, SDM_DROP_23(__VA_ARGS__)
#define SDM_DROP_25(a0, ...) a0, SDM_DROP_24(__VA_ARGS__)
#define SDM_DROP_26(a0, ...) a0, SDM_DROP_25(__VA_ARGS__)
#define SDM_DROP_27(a0, ...) a0, SDM_DROP_26(__VA_ARGS__)
#define SDM_DROP_28(a0, ...) a0, SDM_DROP_27(__VA_ARGS__)
#define SDM_DROP_29(a0, ...) a0, SDM_DROP_28(__VA_ARGS__)
#define SDM_DROP_30(a0, ...) a0, SDM_DROP_29(__VA_ARGS__)
#define SDM_DROP_31(a0, ...) a0, SDM_DROP_30(__VA_ARGS__)
#define SDM_DROP_LAST(...) SDM_CONCAT(SDM_DROP_, SDM_ARGUMENTS_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define SDM_TAKE_0(...)
#define SDM_TAKE_1(a0, ...) a0
#define SDM_TAKE_2(a0, ...) a0, SDM_TAKE_1(__VA_ARGS__)
#define SDM_TAKE_3(a0, ...) a0, SDM_TAKE_2(__VA_ARGS__)
#define SDM_TAKE_4(a0, ...) a0, SDM_TAKE_3(__VA_ARGS__)
#define SDM_TAKE_5(a0, ...) a0, SDM_TAKE_4(__VA_ARGS__)
#define SDM_TAKE_6(a0, ...) a0, SDM_TAKE_5(__VA_ARGS__)
#define SDM_TAKE_7(a0, ...) a0, SDM_TAKE_6(__VA_ARGS__)
#define SDM_TAKE_8(a0, ...) a0, SDM_TAKE_7(__VA_ARGS__)
#define SDM_TAKE_9(a0, ...) a0, SDM_TAKE_8(__VA_ARGS__)
#define SDM_TAKE_10(a0, ...) a0, SDM_TAKE_9(__VA_ARGS__)
#define SDM_TAKE_11(a0, ...) a0, SDM_TAKE_10(__VA_ARGS__)
#define SDM_TAKE_12(a0, ...) a0, SDM_TAKE_11(__VA_ARGS__)
#define SDM_TAKE_13(a0, ...) a0, SDM_TAKE_12(__VA_ARGS__)
#define SDM_TAKE_14(a0, ...) a0, SDM_TAKE_13(__VA_ARGS__)
#define SDM_TAKE_15(a0, ...) a0, SDM_TAKE_14(__VA_ARGS__)
#define SDM_TAKE_16(a0, ...) a0, SDM_TAKE_15(__VA_ARGS__)
#define SDM_TAKE_17(a0, ...) a0, SDM_TAKE_16(__VA_ARGS__)
#define SDM_TAKE_18(a0, ...) a0, SDM_TAKE_17(__VA_ARGS__)
#define SDM_TAKE_19(a0, ...) a0, SDM_TAKE_18(__VA_ARGS__)
#define SDM_TAKE_20(a0, ...) a0, SDM_TAKE_19(__VA_ARGS__)
#define SDM_TAKE_21(a0, ...) a0, SDM_TAKE_20(__VA_ARGS__)
#define SDM_TAKE_22(a0, ...) a0, SDM_TAKE_21(__VA_ARGS__)
#define SDM_TAKE_23(a0, ...) a0, SDM_TAKE_22(__VA_ARGS__)
#define SDM_TAKE_24(a0, ...) a0, SDM_TAKE_23(__VA_ARGS__)
#define SDM_TAKE_25(a0, ...) a0, SDM_TAKE_24(__VA_ARGS__)
#define SDM_TAKE_26(a0, ...) a0, SDM_TAKE_25(__VA_ARGS__)
#define SDM_TAKE_27(a0, ...) a0, SDM_TAKE_26(__VA_ARGS__)
#define SDM_TAKE_28(a0, ...) a0, SDM_TAKE_27(__VA_ARGS__)
#define SDM_TAKE_29(a0, ...) a0, SDM_TAKE_28(__VA_ARGS__)
#define SDM_TAKE_30(a0, ...) a0, SDM_TAKE_29(__VA_ARGS__)
#define SDM_TAKE_31(a0, ...) a0, SDM_TAKE_30(__VA_ARGS__)

#define SDM_IS_EMPTY(...) SDM_CONCAT(SDM_IS_EMPTY_HELPER_0_A, SDM_ARGUMENTS_COUNT(__VA_ARGS__))
#define SDM_IS_EMPTY_HELPER_0_A0 1
#define SDM_IS_EMPTY_HELPER_0_A1 0
#define SDM_IS_EMPTY_HELPER_0_A2 0
#define SDM_IS_EMPTY_HELPER_0_A3 0
#define SDM_IS_EMPTY_HELPER_0_A4 0
#define SDM_IS_EMPTY_HELPER_0_A5 0
#define SDM_IS_EMPTY_HELPER_0_A6 0
#define SDM_IS_EMPTY_HELPER_0_A7 0
#define SDM_IS_EMPTY_HELPER_0_A8 0
#define SDM_IS_EMPTY_HELPER_0_A9 0
#define SDM_IS_EMPTY_HELPER_0_A10 0
#define SDM_IS_EMPTY_HELPER_0_A11 0
#define SDM_IS_EMPTY_HELPER_0_A12 0
#define SDM_IS_EMPTY_HELPER_0_A13 0
#define SDM_IS_EMPTY_HELPER_0_A14 0
#define SDM_IS_EMPTY_HELPER_0_A15 0
#define SDM_IS_EMPTY_HELPER_0_A16 0
#define SDM_IS_EMPTY_HELPER_0_A17 0
#define SDM_IS_EMPTY_HELPER_0_A18 0
#define SDM_IS_EMPTY_HELPER_0_A19 0
#define SDM_IS_EMPTY_HELPER_0_A20 0
#define SDM_IS_EMPTY_HELPER_0_A21 0
#define SDM_IS_EMPTY_HELPER_0_A22 0
#define SDM_IS_EMPTY_HELPER_0_A23 0
#define SDM_IS_EMPTY_HELPER_0_A24 0
#define SDM_IS_EMPTY_HELPER_0_A25 0
#define SDM_IS_EMPTY_HELPER_0_A26 0
#define SDM_IS_EMPTY_HELPER_0_A27 0
#define SDM_IS_EMPTY_HELPER_0_A28 0
#define SDM_IS_EMPTY_HELPER_0_A29 0
#define SDM_IS_EMPTY_HELPER_0_A30 0
#define SDM_IS_EMPTY_HELPER_0_A31 0

#define SDM_RANGE(count) SDM_CONCAT(SDM_RANGE_HELPER_0_A, count)
#define SDM_RANGE_HELPER_0_A0
#define SDM_RANGE_HELPER_0_A1 0
#define SDM_RANGE_HELPER_0_A2 SDM_RANGE_HELPER_0_A1, 1
#define SDM_RANGE_HELPER_0_A3 SDM_RANGE_HELPER_0_A2, 2
#define SDM_RANGE_HELPER_0_A4 SDM_RANGE_HELPER_0_A3, 3
#define SDM_RANGE_HELPER_0_A5 SDM_RANGE_HELPER_0_A4, 4
#define SDM_RANGE_HELPER_0_A6 SDM_RANGE_HELPER_0_A5, 5
#define SDM_RANGE_HELPER_0_A7 SDM_RANGE_HELPER_0_A6, 6
#define SDM_RANGE_HELPER_0_A8 SDM_RANGE_HELPER_0_A7, 7
#define SDM_RANGE_HELPER_0_A9 SDM_RANGE_HELPER_0_A8, 8
#define SDM_RANGE_HELPER_0_A10 SDM_RANGE_HELPER_0_A9, 9
#define SDM_RANGE_HELPER_0_A11 SDM_RANGE_HELPER_0_A10, 10
#define SDM_RANGE_HELPER_0_A12 SDM_RANGE_HELPER_0_A11, 11
#define SDM_RANGE_HELPER_0_A13 SDM_RANGE_HELPER_0_A12, 12
#define SDM_RANGE_HELPER_0_A14 SDM_RANGE_HELPER_0_A13, 13
#define SDM_RANGE_HELPER_0_A15 SDM_RANGE_HELPER_0_A14, 14
#define SDM_RANGE_HELPER_0_A16 SDM_RANGE_HELPER_0_A15, 15
#define SDM_RANGE_HELPER_0_A17 SDM_RANGE_HELPER_0_A16, 16
#define SDM_RANGE_HELPER_0_A18 SDM_RANGE_HELPER_0_A17, 17
#define SDM_RANGE_HELPER_0_A19 SDM_RANGE_HELPER_0_A18, 18
#define SDM_RANGE_HELPER_0_A20 SDM_RANGE_HELPER_0_A19, 19
#define SDM_RANGE_HELPER_0_A21 SDM_RANGE_HELPER_0_A20, 20
#define SDM_RANGE_HELPER_0_A22 SDM_RANGE_HELPER_0_A21, 21
#define SDM_RANGE_HELPER_0_A23 SDM_RANGE_HELPER_0_A22, 22
#define SDM_RANGE_HELPER_0_A24 SDM_RANGE_HELPER_0_A23, 23
#define SDM_RANGE_HELPER_0_A25 SDM_RANGE_HELPER_0_A24, 24
#define SDM_RANGE_HELPER_0_A26 SDM_RANGE_HELPER_0_A25, 25
#define SDM_RANGE_HELPER_0_A27 SDM_RANGE_HELPER_0_A26, 26
#define SDM_RANGE_HELPER_0_A28 SDM_RANGE_HELPER_0_A27, 27
#define SDM_RANGE_HELPER_0_A29 SDM_RANGE_HELPER_0_A28, 28
#define SDM_RANGE_HELPER_0_A30 SDM_RANGE_HELPER_0_A29, 29
#define SDM_RANGE_HELPER_0_A31 SDM_RANGE_HELPER_0_A30, 30

#define SDM_FOR_EACH(action, separator, ...)                                                                           \
   SDM_CONCAT(                                                                                                         \
         SDM_FOR_EACH_HELPER_1_A,                                                                                      \
         SDM_ARGUMENTS_COUNT(__VA_ARGS__))(                                                                            \
               action,                                                                                                 \
               separator,                                                                                              \
               ##__VA_ARGS__)
#define SDM_FOR_EACH_HELPER_0(action, argument) action(argument)
#define SDM_FOR_EACH_HELPER_1_A0(u0, u1, u2)
#define SDM_FOR_EACH_HELPER_1_A1(action, u0, argument)                                                                 \
   SDM_FOR_EACH_HELPER_0(action, argument)
#define SDM_FOR_EACH_HELPER_1_A2(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A1(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A3(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A2(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A4(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A3(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A5(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A4(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A6(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A5(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A7(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A6(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A8(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A7(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A9(action, separator, argument, ...)                                                     \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A8(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A10(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A9(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A11(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A10(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A12(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A11(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A13(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A12(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A14(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A13(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A15(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A14(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A16(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A15(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A17(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A16(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A18(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A17(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A19(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A18(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A20(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A19(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A21(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A20(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A22(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A21(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A23(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A22(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A24(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A23(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A25(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A24(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A26(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A25(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A27(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A26(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A28(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A27(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A29(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A28(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A30(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A29(action, separator, __VA_ARGS__)
#define SDM_FOR_EACH_HELPER_1_A31(action, separator, argument, ...)                                                    \
   SDM_FOR_EACH_HELPER_0(action, argument) SDM_PASS separator                                                          \
   SDM_FOR_EACH_HELPER_1_A30(action, separator, __VA_ARGS__)

#define SDM_AGGREGATE(accumulator, action, ...)                                                                        \
   SDM_CONCAT(                                                                                                         \
         SDM_AGGREGATE_HELPER_0_A,                                                                                     \
         SDM_ARGUMENTS_COUNT(__VA_ARGS__))(                                                                            \
               accumulator,                                                                                            \
               action,                                                                                                 \
               ##__VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A0(accumulator, context) accumulator
#define SDM_AGGREGATE_HELPER_0_A1(accumulator, action, argument) action(accumulator, argument)
#define SDM_AGGREGATE_HELPER_0_A2(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A1(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A3(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A2(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A4(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A3(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A5(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A4(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A6(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A5(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A7(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A6(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A8(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A7(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A9(accumulator, action, argument, ...)                                                  \
   SDM_AGGREGATE_HELPER_0_A8(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A10(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A9(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A11(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A10(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A12(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A11(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A13(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A12(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A14(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A13(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A15(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A14(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A16(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A15(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A17(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A16(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A18(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A17(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A19(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A18(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A20(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A19(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A21(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A20(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A22(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A21(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A23(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A22(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A24(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A23(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A25(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A24(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A26(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A25(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A27(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A26(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A28(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A27(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A29(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A28(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A30(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A29(action(accumulator, argument), action, __VA_ARGS__)
#define SDM_AGGREGATE_HELPER_0_A31(accumulator, action, argument, ...)                                                 \
   SDM_AGGREGATE_HELPER_0_A30(action(accumulator, argument), action, __VA_ARGS__)
