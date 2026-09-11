#include "thrDesatDutyCycleAlgorithm_c.h"
#include "thrDesatDutyCycleAlgorithm.h"
#include "utilities/fsw/opaqueHandle.h"

#include <algorithm>
#include <array>

uint32_t ThrDesatDutyCycleAlgorithm_getMaxThrusterCount(void) { return kMaxThrusterCount; }

bool ThrDesatDutyCycleAlgorithm_validateConfig(uint32_t firingPeriods, uint32_t settlingPeriods) {
    try {
        (void)ThrDesatDutyCycleConfig::create(firingPeriods, settlingPeriods);
        return true;
    } catch (const fsw::invalid_argument&) {
        return false;
    }
}

ThrDesatDutyCycleAlgorithmHandle* ThrDesatDutyCycleAlgorithm_create(uint32_t firingPeriods, uint32_t settlingPeriods) {
    return fsw::createHandle<::ThrDesatDutyCycleAlgorithm, ThrDesatDutyCycleAlgorithmHandle>(
        ThrDesatDutyCycleConfig::create(firingPeriods, settlingPeriods));
}

void ThrDesatDutyCycleAlgorithm_destroy(ThrDesatDutyCycleAlgorithmHandle* self) {
    fsw::deleteHandle<::ThrDesatDutyCycleAlgorithm>(self);
}

void ThrDesatDutyCycleAlgorithm_setConfig(ThrDesatDutyCycleAlgorithmHandle* self,
                                          uint32_t firingPeriods,
                                          uint32_t settlingPeriods) {
    fsw::fromHandle<::ThrDesatDutyCycleAlgorithm>(self)->setConfig(
        ThrDesatDutyCycleConfig::create(firingPeriods, settlingPeriods));
}

void ThrDesatDutyCycleAlgorithm_reInitialize(ThrDesatDutyCycleAlgorithmHandle* self) {
    fsw::fromHandle<::ThrDesatDutyCycleAlgorithm>(self)->reInitialize();
}

ThrDesatDutyCycleForceCmd_c ThrDesatDutyCycleAlgorithm_update(ThrDesatDutyCycleAlgorithmHandle* self,
                                                              const ThrDesatDutyCycleForceCmd_c* thrusterForceCmd) {
    std::array<float, kMaxThrusterCount> thrusterForceCmdCpp{};
    std::copy(
        std::begin(thrusterForceCmd->thrForce), std::end(thrusterForceCmd->thrForce), thrusterForceCmdCpp.begin());

    const std::array<float, kMaxThrusterCount> gated =
        fsw::fromHandle<::ThrDesatDutyCycleAlgorithm>(self)->update(thrusterForceCmdCpp);

    ThrDesatDutyCycleForceCmd_c out{};
    std::copy(gated.begin(), gated.end(), std::begin(out.thrForce));

    return out;
}
