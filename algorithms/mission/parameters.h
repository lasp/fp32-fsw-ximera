#ifndef MISSION_PARAMETERS_H
#define MISSION_PARAMETERS_H

// Mission sizing constants. This is the single source of the array bounds shared by the
// algorithms, their C boundary types and the message payloads -- both in the standalone
// freestanding build and, via xmera_provide_mission_parameters() in algorithms/CMakeLists.txt, in
// an Xmera build. Nothing merges values into it, so it states every constant Xmera knows about,
// including the ones no fp32 algorithm uses.

// SWIG parses this header to expose the constants to Python, and its preprocessor reads the quote
// in a digit separator such as 5'000 as the start of a character literal, silently dropping the
// constants that follow. Turn clang-format off so IntegerLiteralSeparator does not introduce them.

// clang-format off
#define MAX_NUM_CSS_SENSORS 8
#define MAX_EFF_CNT 8
#define RW_EFF_CNT 4

// Not used by any fp32 algorithm; sized for the Xmera modules that own these payloads.
#define MAX_KEY_POINTS 5000

#define MAX_SICP_POINTS 5000
#define SICP_POINT_DIM 3
#define MAX_SICP_ITERATIONS 250

#define MAX_NUMBER_REGIONS 3
// clang-format on

#endif  // MISSION_PARAMETERS_H
