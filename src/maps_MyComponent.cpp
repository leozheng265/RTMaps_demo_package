#include "maps_MyComponent.hpp"

// Use the macros to declare the inputs
MAPS_BEGIN_INPUTS_DEFINITION(ComponentClass)
    //        (name,         , filter input type,       reader)
    MAPS_INPUT("vector_input", MAPS::FilterRealObjects, MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

// Use the macros to declare the outputs
MAPS_BEGIN_OUTPUTS_DEFINITION(ComponentClass)
    //         (name,            output type,          ,     , output buffer size)
    MAPS_OUTPUT("vector_output", MAPS::RealObject, NULL, NULL, 40)
MAPS_END_OUTPUTS_DEFINITION

// Use the macros to declare the properties
MAPS_BEGIN_PROPERTIES_DEFINITION(ComponentClass)
    // Property(   name,     initial value, must initialize, allow change in process)
    MAPS_PROPERTY("property", 0,            false,           false)
MAPS_END_PROPERTIES_DEFINITION

// Use the macros to declare the actions
MAPS_BEGIN_ACTIONS_DEFINITION(ComponentClass)
    //MAPS_ACTION("a_name", ComponentClass::ActionName)
MAPS_END_ACTIONS_DEFINITION

// Use the macros to declare this component (ComponentName) behaviour
MAPS_COMPONENT_DEFINITION(ComponentClass, ComponentName, ComponentVersion, 128, MAPS::Threaded, MAPS::Threaded,
    0,  // inputs
    1,  // outputs
    1,  // properties
    -1)  // actions

namespace
{
}

void ComponentClass::Dynamic()
{
}

void ComponentClass::Birth()
{
}

void ComponentClass::Core()
{
    // read property to a variable
    int property_value;
    GetProperty("property", property_value);

    // read from the first input port
//    int x, y, obj_id;
//    MAPSIOElt* vector_elt = StartReading(Input(0));
//    if (vector_elt) {
//        for(int j = 0; j < vector_elt->VectorSize() - 1; ++j) {
//            MAPSRealObject& real_object = vector_elt[0].RealObject(j);
//            x = real_object.x;
//            y = real_object.y;
//            obj_id = real_object.id;
//        }
//    }
//    StopReading(Input(0));

    // write to output
    MAPSIOElt* out_list = StartWriting(Output("vector_output"));
    if (out_list) {
        out_list->VectorSize() = 10;
        for (std::size_t i = 0; i < 10; ++i) {
            MAPSRealObject& obj = out_list->RealObject(i);

            obj.x = 1;
            obj.y = 1;
            obj.id = 1;

            // setting the kind of the real object
            // To be modified to accommodate for other object types
            obj.kind = obj.Vehicle;
            obj.vehicle.width = 1;
            obj.vehicle.height = 1;
            obj.vehicle.length = 2;

        }
        StopWriting(out_list);
    }

}

void ComponentClass::Death()
{
}
