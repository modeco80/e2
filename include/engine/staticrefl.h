// terrible static reflection
// maybe look at https://github.com/lock3/meta/wiki/Reflection-Introductory-Tutorial
// actually
// maybe i will do just that
// god i hope its not a pain to get working with CMake

#include <typeinfo>

namespace e2 {
	namespace Reflection {

		/**
		 * A ""reflection"" field.
		 * Allows some interaction with a structure.
		 */
		struct Field {
			/**
			 * Offset in bytes.
			 */
			int offset;

			/**
			 * Size of the type.
			 */
			int size;

			/**
			 * Name of the field.
			 */
			struct Name {
				size_t length;
				const char* name;
			} name;

			/**
			 * RTTI type information
			 */
			std::type_info typeinfo;
		};

	} // namespace Reflection

	/**
	 * Define a reflection field.
	 */
#define REFLECTION_FIELD(type, T, name) \
	{ offsetof(T, name), sizeof(type), { sizeof(#name - 1), #name }, typeid(type) }

} // namespace e2