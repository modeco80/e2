#ifndef _CLASS_H
#define _CLASS_H

// aaand a restructure is about to kill this entire file
// oops

// Define the super-class for a class.
// Note that protection level guarding is included
// to catch any non-class scope of this macro being invoked.
//
// example usage:
//
// struct MyInterfaceImplementer : public MyInterface {
//		DEFINE_SUPERCLASS(IMyInterface)
// };
//
#define DEFINE_CLASS(base, previous_access_level) public: \
                            typedef base _base; \
                         previous_access_level:


// Constexpr function template to make a reference to TSuper
// (which will be T::_super) from the class this pointer.
// This ideally should compile down to simply a vtable access, 
// or even nothing in most cases..
template<typename T, typename TBase = typename T::_base>
constexpr TBase& __convert_to_base(T* that) {
	return *((TBase*)that);
}

// Casts the class this pointer to the defined super type,
// allowing you to do something akin to Java's `super` keyword.
// While we can access super methods and such in normal space,
// this allows us to triple check we're doing things only the base has.
#define base __convert_to_base(this)

#endif