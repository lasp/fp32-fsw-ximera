#ifndef F32XMERA_THR_DESAT_DUTY_CYCLE_TYPES_H
#define F32XMERA_THR_DESAT_DUTY_CYCLE_TYPES_H

#include "msgPayloadDef/definitions.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Bounded-array carrier for the per-thruster force command, used for both the gate's input and its
 *        output. It exists because a C function cannot return a bare array; the C++ algorithm passes the same
 *        data as a std::array. Entries beyond the installed thruster count describe no real thruster and are
 *        gated like the rest, so they stay zero for a zero input.
 */
typedef struct {
    float thrForce[MAX_EFF_CNT]; /*!< [N] per-thruster force command */
} ThrDesatDutyCycleForceCmd_c;

#ifdef __cplusplus
}  // extern "C"
#endif

#endif /* F32XMERA_THR_DESAT_DUTY_CYCLE_TYPES_H */
