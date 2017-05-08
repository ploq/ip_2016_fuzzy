#ifndef OPS_MODE_OPS_STATE_PROVIDER_I_OPS_STATE_HPP
#define OPS_MODE_OPS_STATE_PROVIDER_I_OPS_STATE_HPP

#include <string>
#include "ops_mode-ops_state-types.hpp"

namespace Ops_Mode {
    namespace Ops_State {
	namespace Provider {
	    class I_Ops_State {
	    public:
		I_Ops_State(void);
		virtual ~I_Ops_State(void);

		virtual const Ops_Mode::Ops_State::Ops_State_Type& Get_Ops_State(void) const = 0;
		virtual void Put_Ops_State(const Ops_Mode::Ops_Mode_Type::Enum Ops_State, const Ops_Mode::Ops_Mode_Quality_Type::Enum Ops_State_qual) = 0;

		virtual const bool Will_data_on_Ops_State_be_sent() const = 0;
	    private:
		I_Ops_State(const I_Ops_State&);
		const I_Ops_State& operator=(const I_Ops_State&);
	    };
	} //NS:Provider
    } //NS:Ops_State
} //NS:Ops_Mode
#endif 

