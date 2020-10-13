#include <defs.h>
#include <string>
#include <map>

namespace e2 {

	// fwd decl
	struct Entity;



	/**
	 * Interface for all components to use.
	 */
	interface Component {
		/**
		 * Constructor for components.
		 * \param[in] AttachedEntity The entity that we are going to attach to.
		 */
		Component(Entity * AttachedEntity);

		//static Component* Factory(Entity* ent)

		/**
		 * \defgroup methods Component Overrides 
		 * @{
		 */

		/**
		 * This function is called when the component
		 * is awakened (enabled).
		 */
		virtual void Awake() = 0;

		/**
		 * Called when a game frame updates.
		 * \param timeDelta The current time delta.
		 */
		virtual void Update(float timeDelta) = 0;

		/** @} */

		/**
		 * Get the name of this component.
		 */
		virtual std::string GetName() = 0;

	   protected:
		/**
		 * The entity that this component is attached to.
		 */
		Entity* entity;

		/**
		 * Whether or not this component should be processed during runtime.
		 */
		bool Disabled = false;

	};

#define DEFINE_COMPONENT_MEMBERS(T)       \
	static Component* Factory(Entity* e); \
	std::string GetName();

/**
 * Implement some component members that do not change.
 */
#define IMPL_COMPONENT_MEMBERS(T)       \
	Component* T::Factory(Entity* e) {  \
		return new T();                 \
	}                                   \
	std::string T::GetName() override { \
		return #T;                      \
	}

} // namespace e2