#ifndef JSONREADER_HPP
#define JSONREADER_HPP

#include <memory>
#include <string>
#include <iosfwd>
#include <streambuf>
#include <cstdint>
#include <map>
#include <utility>

struct _json_value;

namespace chesspp {
    namespace util {
        class JsonReader final{
            _json_value *json{nullptr};
        public:
            JsonReader() = delete;
            JsonReader(JsonReader const&) = delete;
            JsonReader &operator=(JsonReader const &) = delete;
            JsonReader (std::istream &s);
            JsonReader (std::istream &&s);
            JsonReader (JsonReader &&from);
            JsonReader &operator =(std::istream &&s);
            JsonReader &operator =(JsonReader &&from);
            ~JsonReader();
            enum class Type{
                None,
                Object,
                Array,
                Integer,
                Double,
                String,
                Boolean,
                Null
            };
            class NestedValue{
                friend class ::chesspp::util::JsonReader;
                _json_value const &value;
                NestedValue(_json_value const &) noexcept;
                NestedValue &operator=(NestedValue const &) noexcept = delete;
            public:
                NestedValue(NestedValue const &) = default;
                NestedValue(NestedValue &&) = default;
                NestedValue &operator=(NestedValue &&) = default;
                ~NestedValue() = default;
                Type type() const noexcept;
                /**
                 * Returns the parent NestedValue or throws
                 * ::std::domain_error.
                 * \return the parent NestedValue.
                 * \throws ::std::domain_error
                 */
                NestedValue parent() const;

                /**
                 * Returns a NestedValue within this one by name.
                 * Only works if type() == json_object
                 * \param name the name of the nested JSON value.
                 * \return the NestedValue by name.
                 */
                NestedValue operator[](std::string const &name) const noexcept(noexcept(name.c_str()));
                /**
                 * Returns a NestedValue within this one by name.
                 * Only works if type() == json_object
                 * \param name the name of the nested JSON value.
                 * \return the NestedValue by name.
                 */
                NestedValue operator[](char const *name) const noexcept;
                /**
                 * Returns the length of array values.
                 * \return The length of the array, or 0 if not an array.
                 */
                std::size_t length() const noexcept;
                /**
                 * Returns the nested value at the given array index.
                 * Only works if type() == json_array
                 * \param index The index within the array.
                 * \return the nested value at the given index.
                 */
                NestedValue operator[](std::size_t index) const noexcept;
                /**
                 * Provides a std::map-based view of
                 * an object value, mapping object keys
                 * to object values. Only works if
                 * type() == json_object
                 * \return a std::map of object keys ot obejct values
                 */
                std::map<std::string, NestedValue> object() const;
                /**
                 * Returns the string representation of this string value.
                 * Only works if type() == json_string
                 * \return The string
                 */
                operator std::string() const noexcept(noexcept(std::string("")));
                operator std::  int8_t() const noexcept;
                operator std:: uint8_t() const noexcept;
                operator std:: int16_t() const noexcept;
                operator std::uint16_t() const noexcept;
                operator std:: int32_t() const noexcept;
                operator std::uint32_t() const noexcept;
                operator std:: int64_t() const noexcept;
                operator std::uint64_t() const noexcept;
                /**
                 * Returns the boolean state of this bool value.
                 * Only works if type() == json_bool.
                 * \return The boolean.
                 */
                operator bool() const noexcept;
                /**
                 * Returns the floating-point value of this double.
                 * Only works if type() == json_double
                 * \return The double.
                 */
                operator double() const noexcept;

                /**
                 * Only for extreme use cases: returns the
                 * underlying json_value being wrapped.
                 * \return the underlying json_value
                 */
                _json_value const &implementation() noexcept
                {
                    return value;
                }
            };

            /**
             * Returns a NestedValue view into
             * this JSON.
             * \return a NestedValue view into this JSON.
             */
            NestedValue access() const noexcept;
            /**
             * Returns a NestedValue view into
             * this JSON.
             * \return a NestedValue view into this JSON.
             */
            NestedValue operator()() const noexcept
            {
                return access();
            }
            /**
             * Navigates through obejct values and array values
             * and returns a NestedValue at the destination.
             * \tparam Args The types for navigation, generally deduced by the compiler.
             * \param path The path to take to arrive at the destination. May be strings and indicies.
             */
            template<typename... Args>
            NestedValue navigate(Args... path) const
            {
                return navigate(access(), path...);
            }
        private:
            /**
             * Helper for the public navigate.
             */
            template<typename First, typename... Rest>
            NestedValue navigate(NestedValue v, First const &first, Rest const &... rest) const
            {
                return navigate(v[first], rest...);
            }
            /**
             * Helper for the public navigate.
             */
            template<typename Last>
            NestedValue navigate(NestedValue v, Last const &last) const
            {
                return v[last];
            }
        };
    }
}

#endif // JSONREADER_HPP
