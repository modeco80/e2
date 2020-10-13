#include <staticrefl.h>
#include <string>
#include <vector>

namespace e2 {

	/**
	 * Doing things the .NET way since god knows when
	 */
	struct Object {	
	
		/**
		 * Dump something about this object
		 */
		virtual std::string ToString() {
			return "Object{}";
		}

	protected:

		// NOTE:cppx will kill this one for good
		std::vector<Reflection::Field> fields;

	};

}