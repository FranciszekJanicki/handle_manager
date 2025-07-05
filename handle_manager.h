#ifndef HANDLE_MANAGER_HANDLE_MANAGER_H
#define HANDLE_MANAGER_HANDLE_MANAGER_H

#include <assert.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_HANDLE_MANAGER(HANDLE_NAME, KEY_TYPE, HANDLE_TYPE, NUM_HANDLES) \
                                                                                \
    void HANDLE_NAME##_manager_set_handle(KEY_TYPE key, HANDLE_TYPE handle);    \
                                                                                \
    HANDLE_TYPE HANDLE_NAME##_manager_get_handle(KEY_TYPE key);

#define DEFINE_HANDLE_MANAGER(HANDLE_NAME, KEY_TYPE, HANDLE_TYPE, NUM_HANDLES) \
    static HANDLE_TYPE HANDLE_NAME##_handles[NUM_HANDLES] = {0};               \
                                                                               \
    void HANDLE_NAME##_manager_set_handle(KEY_TYPE key, HANDLE_TYPE handle)    \
    {                                                                          \
        assert(key < NUM_HANDLES);                                             \
        assert(!HANDLE_NAME##_handles[key]);                                   \
        assert(handle);                                                        \
        HANDLE_NAME##_handles[key] = handle;                                   \
    }                                                                          \
                                                                               \
    HANDLE_TYPE HANDLE_NAME##_manager_get_handle(KEY_TYPE key)                 \
    {                                                                          \
        assert(key < NUM_HANDLES);                                             \
        assert(HANDLE_NAME##_handles[key]);                                    \
        return HANDLE_NAME##_handles[key];                                     \
    }

#ifdef __cplusplus
}
#endif

#endif // #ifndef HANDLE_MANAGER_HANDLE_MANAGER_H