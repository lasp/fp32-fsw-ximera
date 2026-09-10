#ifndef MSG_DEFINITIONS_H
#define MSG_DEFINITIONS_H

#define MAX_NUM_CSS_SENSORS 32
#define MAX_EFF_CNT 36
#define RW_EFF_CNT 36

// FP32 algorithm specific constants
#define MAX_MEASUREMENT_NUMBER 5
#define MAX_MEASUREMENT_VECTOR 5

// The C boundary types size their arrays from the macros above so that they stay
// parseable as C. The typed constants below are for C++ callers only.
#ifdef __cplusplus

#include <cstdint>

inline constexpr std::uint32_t kMaxNumCssSensors = MAX_NUM_CSS_SENSORS;
inline constexpr std::uint32_t kMaxThrusterCount = MAX_EFF_CNT;
inline constexpr std::uint32_t kMimuCount = 3U;

#endif  // __cplusplus

#endif  // MSG_DEFINITIONS_H
