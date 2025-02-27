#pragma once
#include <cstddef>
#include <type_traits>

namespace rust {
    inline namespace cxxbridge1 {
        // #include "rust/cxx.h"

#ifndef CXXBRIDGE1_RUST_OPAQUE
#define CXXBRIDGE1_RUST_OPAQUE
        class Opaque {
        public:
            Opaque() = delete;
            Opaque(const Opaque&) = delete;
            ~Opaque() = delete;
        };
#endif // CXXBRIDGE1_RUST_OPAQUE

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
        namespace detail {
            namespace {
                template <typename T, typename = std::size_t>
                struct is_complete : std::false_type {};
                template <typename T>
                struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
            } // namespace
        } // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

#ifndef CXXBRIDGE1_LAYOUT
#define CXXBRIDGE1_LAYOUT
        class layout {
            template <typename T>
            friend std::size_t size_of();
            template <typename T>
            friend std::size_t align_of();
            template <typename T>
            static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                std::size_t>::type
                do_size_of() {
                return T::layout::size();
            }
            template <typename T>
            static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                std::size_t>::type
                do_size_of() {
                return sizeof(T);
            }
            template <typename T>
            static
                typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
                size_of() {
                return do_size_of<T>();
            }
            template <typename T>
            static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                std::size_t>::type
                do_align_of() {
                return T::layout::align();
            }
            template <typename T>
            static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                std::size_t>::type
                do_align_of() {
                return alignof(T);
            }
            template <typename T>
            static
                typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
                align_of() {
                return do_align_of<T>();
            }
        };

        template <typename T>
        std::size_t size_of() {
            return layout::size_of<T>();
        }

        template <typename T>
        std::size_t align_of() {
            return layout::align_of<T>();
        }
#endif // CXXBRIDGE1_LAYOUT
    } // namespace cxxbridge1
} // namespace rust

struct ServiceWrapper;

#ifndef CXXBRIDGE1_STRUCT_ServiceWrapper
#define CXXBRIDGE1_STRUCT_ServiceWrapper
struct ServiceWrapper final : public ::rust::Opaque {
    ~ServiceWrapper() = delete;

private:
    friend ::rust::layout;
    struct layout {
        static ::std::size_t size() noexcept;
        static ::std::size_t align() noexcept;
    };
};
#endif // CXXBRIDGE1_STRUCT_ServiceWrapper

void on_connection(::ServiceWrapper* srv) noexcept;
