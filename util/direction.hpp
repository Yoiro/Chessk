#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <iosfwd>

namespace chesspp
{
    namespace util
    {
        /**
         * Represents a direction.
         */
        enum class Direction
        {
            None,
            North,
            NorthEast,
            East,
            SouthEast,
            South,
            SouthWest,
            West,
            NorthWest
        };
        /**
         * Returns a new direction which is a rotation of the
         * provided direction.
         * \param d the direction to rotate.
         * \param r the number of times to rotate, may be negative.
         * \return the rotated direction.
         */
        Direction Rotate(Direction d, signed r) noexcept;
        /**
         * Serializes a direction to a stream in string format.
         * \param os The stream to serialize to.
         * \param d the Direction to serialize.
         * \return os
         */
        std::ostream &operator<<(std::ostream &os, Direction const &d) noexcept;
        std::istream &operator>>(std::istream &is, Direction &d);
    }
}

#endif // DIRECTION_HPP
