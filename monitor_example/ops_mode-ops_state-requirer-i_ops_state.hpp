#ifndef OPS_MODE_OPS_STATE_REQUIRER_I_OPS_STATE_HPP
#define OPS_MODE_OPS_STATE_REQUIRER_I_OPS_STATE_HPP

#include <string>
#include "ops_mode-ops_state-types.hpp"

namespace Ops_Mode {
    namespace Ops_State {
	namespace Requirer {
	    class I_Ops_State {
	    public:
		I_Ops_State(void);
		virtual ~I_Ops_State(void);

		virtual const Ops_Mode::Ops_State::Ops_State_Type& Get_Ops_State(void) const = 0;
virtual const Ops_Mode::Ops_Mode_Type::Enum Get_Ops_State_Ops_State(void) const = 0;
		virtual void Ops_State_Ops_State_Changed(const Ops_Mode::Ops_Mode_Type::Enum New_Val) = 0;
		virtual const Ops_Mode::Ops_Mode_Quality_Type::Enum Get_Ops_State_Ops_State_Quality(void) const = 0;
		virtual void Ops_State_Ops_State_Quality_Changed(const Ops_Mode::Ops_Mode_Quality_Type::Enum New_Val) = 0;
	    private:
		I_Ops_State(const I_Ops_State&);
		const I_Ops_State& operator=(const I_Ops_State&);
	    };
	} //NS:Requirer
    } //NS:Ops_State
} //NS:Ops_Mode
#endif 

