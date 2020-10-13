#include <engine/component.h>

namespace e2 {

	Component::Component(Entity* AttachedEntity)
		: entity(AttachedEntity) {
	}

} // namespace e2