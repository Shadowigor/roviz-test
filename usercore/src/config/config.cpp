
#include "config/config.h"
#include "core/template_decl.h"

template<typename T>
Config<T>::Config(ConfigImpl *impl)
    : impl(impl)
{
}

template<typename T>
typename ConfigStorageType<T>::type Config<T>::value()
{
    if(this->impl == nullptr)
        return typename ConfigStorageType<T>::type();

    // Yes, that's a really ugly typecast, but if you don't fuck
    // up really hard, it should be impossible to fail.
    // Also, we lock to prevent an extremely unlikely race-condition.
    this->impl->lock();
    typename ConfigStorageType<T>::type val = *static_cast<typename ConfigStorageType<T>::type*>(this->impl->value());
    this->impl->unlock();

    return val;
}

template<typename T>
bool Config<T>::changed()
{
    if(this->impl == nullptr)
        return false;

    return this->impl->changed();
}

INSTANTIATE_CONFIG
