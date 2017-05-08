#ifndef OPS_MODE_OPS_STATE_TYPES_HPP
#define OPS_MODE_OPS_STATE_TYPES_HPP

#include "ops_mode-types.hpp"

namespace Ops_Mode {
    namespace Ops_State {
	struct Ops_State_Type {
	    ::Ops_Mode::Ops_Mode_Type::Enum Ops_State;
	    ::Ops_Mode::Ops_Mode_Quality_Type::Enum Ops_Quality;	    
	};
    }
}

#endif //OPS_MODE_TYPES_HPP
