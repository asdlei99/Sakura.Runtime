#include "SkrGui/framework/layer/container_layer.hpp"

namespace skr::gui
{
void ContainerLayer::visit_children(VisitFuncRef visitor) const SKR_NOEXCEPT
{
    for (auto child : _children)
    {
        visitor(child);
    }
}

void ContainerLayer::add_child(NotNull<Layer*> child) SKR_NOEXCEPT
{
    child->mount(this);
    _children.add(child);
}
bool ContainerLayer::has_children() const SKR_NOEXCEPT
{
    return !_children.is_empty();
}
void ContainerLayer::remove_all_children() SKR_NOEXCEPT
{
    for (auto child : _children)
    {
        child->unmount();
    }
    _children.clear();
}
} // namespace skr::gui