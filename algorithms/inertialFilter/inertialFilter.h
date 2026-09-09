#ifndef F32XMERA_INERTIALFILTER_H
#define F32XMERA_INERTIALFILTER_H

#include "inertialFilterAlgorithm.h"
#include "msgPayloadDef/FilterMsgF32Payload.h"
#include "msgPayloadDef/FilterResidualsMsgF32Payload.h"
#include "msgPayloadDef/IMUSensorBodyMsgF32Payload.h"
#include "msgPayloadDef/NavAttMsgF32Payload.h"
#include "msgPayloadDef/STAttMsgF32Payload.h"

#include <architecture/_GeneralModuleFiles/sys_model.h>
#include <architecture/messaging/messaging.h>

#include <Eigen/Core>

#include <cstdint>
#include <memory>

/*! @brief xmera adapter for the inertial SRuKF. Pack star-tracker attitude and gyro
 *  messages into the algorithm's input types, run update(), and write the output data to messages. */
class InertialFilter : public SysModel {
   public:
    InertialFilter();
    ~InertialFilter() override;

    void reset(uint64_t currentSimNanos) override;
    void updateState(uint64_t currentSimNanos) override;
    void reInitializeExceptPersistentStates();
    void reInitialize();

    // Public config properties -- set before reset(). The matrix/vector
    // properties are sized to their defaults (zero / identity) in the constructor.
    double alpha = 0.0;                    //!< [-] sigma-point spread tunable
    double beta = 0.0;                     //!< [-] prior-knowledge tunable
    Eigen::MatrixXd processNoise;          //!< [-] N x N process noise Q (defaults to zero)
    Eigen::VectorXd initialState;          //!< [-] N-element initial state seed (defaults to zero)
    Eigen::MatrixXd initialCovariance;     //!< [-] N x N initial covariance P0 (defaults to identity)
    double stMeasurementNoiseStd = 0.0;    //!< [-] star-tracker attitude measurement noise std (>= 0)
    double gyroMeasurementNoiseStd = 0.0;  //!< [rad/s] gyro measurement noise std (>= 0)

    ReadFunctor<STAttMsgF32Payload> stAttInMsg;                  //!< star-tracker attitude input (required)
    ReadFunctor<IMUSensorBodyMsgF32Payload> imuSensorBodyInMsg;  //!< majority-voted MIMU body rate input (optional)

    Message<NavAttMsgF32Payload> navAttOutMsg;                  //!< estimated attitude + rate output
    Message<FilterMsgF32Payload> filterOutMsg;                  //!< full filter state + covariance output
    Message<FilterResidualsMsgF32Payload> filterStResOutMsg;    //!< star-tracker residuals output
    Message<FilterResidualsMsgF32Payload> filterGyroResOutMsg;  //!< gyro residuals output

   private:
    void writeOutputMessages(uint64_t currentSimNanos,
                             filtering::inertialFilter::InertialFilterOutput const& filterOutput);

    std::unique_ptr<filtering::inertialFilter::InertialFilterAlgorithm> algorithm = nullptr;

    double lastStTimeTag = -1;  //!< [s] last ST payload timeTag consumed; -1 before reset
};

#endif
