#ifndef THR_FIRING_REMAINDER_TYPES_H
#define THR_FIRING_REMAINDER_TYPES_H

#include "msgPayloadDef/definitions.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Thrust pulsing regime selection. */
typedef enum {
    THR_FIRING_REMAINDER_ON_PULSING = 0,
    THR_FIRING_REMAINDER_OFF_PULSING = 1
} ThrFiringRemainderPulsingRegime;

/** @brief Thruster force command input (POD). */
typedef struct {
    float thrForce[MAX_EFF_CNT]; /*!< [N] Thruster force values */
} ThrFiringRemainderForceCmd;

/** @brief Thruster on-time command output (POD). */
typedef struct {
    float onTimeRequest[MAX_EFF_CNT]; /*!< [s] On-time requests */
} ThrFiringRemainderOnTimeCmd;

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // THR_FIRING_REMAINDER_TYPES_H
