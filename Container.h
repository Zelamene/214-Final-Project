/**
 * @file Container.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract class representing a container for plants.
 */

#ifndef CONTAINER_H
#define CONTAINER_H

/**
 * @class Container
 * @brief Abstract representation of a plant container.
 *
 * Serves as a base for specific container types like Crate.
 */
class Container
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~Container() {}

     /**
     * @brief default constructor.
     */
    Container() = default;
};

#endif // CONTAINER_H
