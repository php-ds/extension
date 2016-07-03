#ifndef PHP_DS_DEQUE_H
#define PHP_DS_DEQUE_H

#include "../../common.h"
#include "../../ds/ds_deque.h"

/**
 * Custom PHP object wrapped around an internal deque
 */
typedef struct _php_ds_deque_t {
    zend_object  std;
    ds_deque_t  *deque;
} php_ds_deque_t;

#define Z_DEQUE(z)   ((php_ds_deque_t*) Z_OBJ(z))->deque
#define Z_DEQUE_P(z) Z_DEQUE(*z)
#define THIS_DEQUE() Z_DEQUE_P(getThis())

#define ZVAL_DEQUE(z, d)  ZVAL_OBJ(z, deque_create_object_ex(d))
#define ZVAL_NEW_DEQUE(z) ZVAL_OBJ(z, deque_create_object_ex(ds_deque()))

#define RETURN_DEQUE(deque)              \
do {                                     \
    if (deque) {                         \
        ZVAL_DEQUE(return_value, deque); \
    } else {                             \
        ZVAL_NULL(return_value);         \
    }                                    \
    return;                              \
} while(0)

/**
 * Creates a new zend_object using an existing deque.
 */
zend_object *deque_create_object_ex(ds_deque_t *deque);

/**
 * Creates a new deque zend_object.
 */
zend_object *deque_create_object(zend_class_entry *ce);

/**
 * Creates an object clone of a deque.
 */
zend_object *deque_create_clone(ds_deque_t *deque);

/**
 * Serializses a deque object.
 */
int deque_serialize(zval *object, unsigned char **buffer, size_t *length, zend_serialize_data *data);

/**
 * Unserializes a string as a deque object.
 */
int deque_unserialize(zval *object, zend_class_entry *ce, const unsigned char *buffer, size_t length, zend_unserialize_data *data);

#endif
