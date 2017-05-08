#ifndef OPS_MODE_OPS_STATE_PROVIDER_I_OPS_STATE_PROVIDER_HPP
#define OPS_MODE_OPS_STATE_PROVIDER_I_OPS_STATE_PROVIDER_HPP

#include "ops_mode-ops_state-provider-i_ops_state.hpp"

namespace Ops_Mode {

namespace Ops_State {

namespace Provider {

class I_Ops_State_Provider {
public:
    I_Ops_State_Provider();
    virtual ~I_Ops_State_Provider() =0;
    virtual Ops_Mode::Ops_State::Provider::I_Ops_State& Get_Port() = 0;

private:
    I_Ops_State_Provider(const I_Ops_State_Provider&);
    const I_Ops_State_Provider& operator=(const I_Ops_State_Provider&);
};

} // NS: Provider

} // NS: Ops_State

} // NS: Ops_Mode

#endif //OPS_MODE_OPS_STATE_PROVIDER_I_OPS_STATE_PROVIDER_HPP
