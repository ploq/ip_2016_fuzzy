#ifndef OPS_MODE_OPS_STATE_REQUIRER_I_OPS_STATE_REQUIRER_HPP
#define OPS_MODE_OPS_STATE_REQUIRER_I_OPS_STATE_REQUIRER_HPP

#include "ops_mode-ops_state-requirer-i_ops_state.hpp"

namespace Ops_Mode {

namespace Ops_State {

namespace Requirer {

class I_Ops_State_Requirer {
public:
    I_Ops_State_Requirer();
    virtual ~I_Ops_State_Requirer() =0;
    virtual Ops_Mode::Ops_State::Requirer::I_Ops_State& Get_Port() = 0;

private:
    I_Ops_State_Requirer(const I_Ops_State_Requirer&);
    const I_Ops_State_Requirer& operator=(const I_Ops_State_Requirer&);
};

} // NS: Requirer

} // NS: Ops_State

} // NS: Ops_Mode


#endif //OPS_MODE_OPS_STATE_REQUIRER_I_OPS_STATE_REQUIRER_HPP
