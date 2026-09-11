%module inertialFilterF32
%{
   #include "inertialFilter.h"
%}

%include <architecture/_GeneralModuleFiles/sys_model.i>
%include <architecture/_GeneralModuleFiles/swig_conly_data.i>
%include <architecture/_GeneralModuleFiles/swig_eigen.i>

%include "inertialFilter.h"

%include "msgPayloadDef/STAttMsgF32Payload.h"
%include "msgPayloadDef/IMUSensorBodyMsgF32Payload.h"
%include "msgPayloadDef/NavAttMsgF32Payload.h"
%include "msgPayloadDef/FilterMsgF32Payload.h"
%include "msgPayloadDef/FilterResidualsMsgF32Payload.h"
