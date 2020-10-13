#ifndef _ENTITY_H
#define _ENTITY_H

#include <engine/component.h>

#include <defs.h>
#include <vector>
#include <string>

namespace e2 {

	// test component
	struct MyComponent : public Component {
		DEFINE_COMPONENT_MEMBERS(MyComponent)

		void Awake() {
		
		}

		void Update(float timeDelta) {

		}

	};

	IMPL_COMPONENT_MEMBERS(MyComponent)

	/**
	 * An entity.
	 */
	struct Entity {
	
		/**
		 * Add a component of type to this entity.
		 */
		template<typename T, typename = std::is_base_of<Component, T>>
		void AddComponent() {
			auto component = T::Factory(this);
			if(component) {
				components.push_back(component);
			}
		}

		template<typename T, typename = std::is_base_of<Component, T>>
		void RemoveComponent() {
		
		}

		/**
		 * Get a component from the registered components of this entity.
		 * \tparam T Component type
		 */
		template<typename T, typename = std::is_base_of<Component, T>>
		T& GetComponent() {
		}

		/**
		 * Update all enabled and attached components.
		 */
		void Update();

	private:
		/**
		 * All of the registered components inside of this entity.
		 */
		std::vector<Component*> components;
	};

}

#endif