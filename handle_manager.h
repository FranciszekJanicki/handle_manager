#ifndef HANDLE_MANAGER_HANDLE_MANAGER_H
#define HANDLE_MANAGER_HANDLE_MANAGER_H

#include <assert.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_HANDLE_MANAGER(HANDLE_NAME, HANDLE_KEY, HANDLE_VALUE, NUM_HANDLES) \
                                                      \
    void HANDLE_NAME##_manager_set(HANDLE_KEY key, HANDLE_VALUE value);    \
                                                      \
    HANDLE_VALUE HANDLE_NAME##_manager_get(HANDLE_KEY key);

#define DEFINE_HANDLE_MANAGER(HANDLE_NAME, HANDLE_KEY, HANDLE_VALUE, NUM_HANDLES)      \
    static HANDLE_VALUE HANDLE_NAME##_manager_handles[NUM_HANDLES] = {0}; \
                                                          \
    void HANDLE_NAME##_manager_set(HANDLE_KEY key, HANDLE_VALUE value)         \
    {                                                     \
        assert(key < (NUM_HANDLES));                       \
        assert(!HANDLE_NAME##_manager_handles[key]);              \
        assert(value);                                    \
        HANDLE_NAME##_manager_handles[key] = value;               \
    }                                                     \
                                                          \
    HANDLE_VALUE NAME##_manager_get(HANDLE_KEY key)                     \
    {                                                     \
        assert(key < (NUM_HANDLES));                       \
        assert(HANDLE_NAME##_manager_values[key]);               \
        return HANDLE_NAME##_manager_values[key];                \
    }

#ifdef __cplusplus
}
#endif

#endif // #ifndef HANDLE_MANAGER_HANDLE_MANAGER_H
