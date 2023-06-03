#pragma once

#include <maps.hpp>

#define ComponentClass   maps_MyComponent
#define ComponentName    "MyComponent"
#define ComponentVersion "1.0.0"

class ComponentClass : public MAPSComponent
{
    MAPS_COMPONENT_STANDARD_HEADER_CODE(ComponentClass)

    void Dynamic() override;
};
