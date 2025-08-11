// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hdwr_pkg:srv/HumanSrv.idl
// generated code does not contain a copyright notice
#include "hdwr_pkg/srv/detail/human_srv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `human_action`
#include "rosidl_runtime_c/string_functions.h"

bool
hdwr_pkg__srv__HumanSrv_Request__init(hdwr_pkg__srv__HumanSrv_Request * msg)
{
  if (!msg) {
    return false;
  }
  // human_action
  if (!rosidl_runtime_c__String__init(&msg->human_action)) {
    hdwr_pkg__srv__HumanSrv_Request__fini(msg);
    return false;
  }
  return true;
}

void
hdwr_pkg__srv__HumanSrv_Request__fini(hdwr_pkg__srv__HumanSrv_Request * msg)
{
  if (!msg) {
    return;
  }
  // human_action
  rosidl_runtime_c__String__fini(&msg->human_action);
}

bool
hdwr_pkg__srv__HumanSrv_Request__are_equal(const hdwr_pkg__srv__HumanSrv_Request * lhs, const hdwr_pkg__srv__HumanSrv_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // human_action
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->human_action), &(rhs->human_action)))
  {
    return false;
  }
  return true;
}

bool
hdwr_pkg__srv__HumanSrv_Request__copy(
  const hdwr_pkg__srv__HumanSrv_Request * input,
  hdwr_pkg__srv__HumanSrv_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // human_action
  if (!rosidl_runtime_c__String__copy(
      &(input->human_action), &(output->human_action)))
  {
    return false;
  }
  return true;
}

hdwr_pkg__srv__HumanSrv_Request *
hdwr_pkg__srv__HumanSrv_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdwr_pkg__srv__HumanSrv_Request * msg = (hdwr_pkg__srv__HumanSrv_Request *)allocator.allocate(sizeof(hdwr_pkg__srv__HumanSrv_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hdwr_pkg__srv__HumanSrv_Request));
  bool success = hdwr_pkg__srv__HumanSrv_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hdwr_pkg__srv__HumanSrv_Request__destroy(hdwr_pkg__srv__HumanSrv_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hdwr_pkg__srv__HumanSrv_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hdwr_pkg__srv__HumanSrv_Request__Sequence__init(hdwr_pkg__srv__HumanSrv_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdwr_pkg__srv__HumanSrv_Request * data = NULL;

  if (size) {
    data = (hdwr_pkg__srv__HumanSrv_Request *)allocator.zero_allocate(size, sizeof(hdwr_pkg__srv__HumanSrv_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hdwr_pkg__srv__HumanSrv_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hdwr_pkg__srv__HumanSrv_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hdwr_pkg__srv__HumanSrv_Request__Sequence__fini(hdwr_pkg__srv__HumanSrv_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hdwr_pkg__srv__HumanSrv_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hdwr_pkg__srv__HumanSrv_Request__Sequence *
hdwr_pkg__srv__HumanSrv_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdwr_pkg__srv__HumanSrv_Request__Sequence * array = (hdwr_pkg__srv__HumanSrv_Request__Sequence *)allocator.allocate(sizeof(hdwr_pkg__srv__HumanSrv_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hdwr_pkg__srv__HumanSrv_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hdwr_pkg__srv__HumanSrv_Request__Sequence__destroy(hdwr_pkg__srv__HumanSrv_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hdwr_pkg__srv__HumanSrv_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hdwr_pkg__srv__HumanSrv_Request__Sequence__are_equal(const hdwr_pkg__srv__HumanSrv_Request__Sequence * lhs, const hdwr_pkg__srv__HumanSrv_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hdwr_pkg__srv__HumanSrv_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hdwr_pkg__srv__HumanSrv_Request__Sequence__copy(
  const hdwr_pkg__srv__HumanSrv_Request__Sequence * input,
  hdwr_pkg__srv__HumanSrv_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hdwr_pkg__srv__HumanSrv_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hdwr_pkg__srv__HumanSrv_Request * data =
      (hdwr_pkg__srv__HumanSrv_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hdwr_pkg__srv__HumanSrv_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hdwr_pkg__srv__HumanSrv_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hdwr_pkg__srv__HumanSrv_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
hdwr_pkg__srv__HumanSrv_Response__init(hdwr_pkg__srv__HumanSrv_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
hdwr_pkg__srv__HumanSrv_Response__fini(hdwr_pkg__srv__HumanSrv_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
hdwr_pkg__srv__HumanSrv_Response__are_equal(const hdwr_pkg__srv__HumanSrv_Response * lhs, const hdwr_pkg__srv__HumanSrv_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
hdwr_pkg__srv__HumanSrv_Response__copy(
  const hdwr_pkg__srv__HumanSrv_Response * input,
  hdwr_pkg__srv__HumanSrv_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

hdwr_pkg__srv__HumanSrv_Response *
hdwr_pkg__srv__HumanSrv_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdwr_pkg__srv__HumanSrv_Response * msg = (hdwr_pkg__srv__HumanSrv_Response *)allocator.allocate(sizeof(hdwr_pkg__srv__HumanSrv_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hdwr_pkg__srv__HumanSrv_Response));
  bool success = hdwr_pkg__srv__HumanSrv_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hdwr_pkg__srv__HumanSrv_Response__destroy(hdwr_pkg__srv__HumanSrv_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hdwr_pkg__srv__HumanSrv_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hdwr_pkg__srv__HumanSrv_Response__Sequence__init(hdwr_pkg__srv__HumanSrv_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdwr_pkg__srv__HumanSrv_Response * data = NULL;

  if (size) {
    data = (hdwr_pkg__srv__HumanSrv_Response *)allocator.zero_allocate(size, sizeof(hdwr_pkg__srv__HumanSrv_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hdwr_pkg__srv__HumanSrv_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hdwr_pkg__srv__HumanSrv_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hdwr_pkg__srv__HumanSrv_Response__Sequence__fini(hdwr_pkg__srv__HumanSrv_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hdwr_pkg__srv__HumanSrv_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hdwr_pkg__srv__HumanSrv_Response__Sequence *
hdwr_pkg__srv__HumanSrv_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdwr_pkg__srv__HumanSrv_Response__Sequence * array = (hdwr_pkg__srv__HumanSrv_Response__Sequence *)allocator.allocate(sizeof(hdwr_pkg__srv__HumanSrv_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hdwr_pkg__srv__HumanSrv_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hdwr_pkg__srv__HumanSrv_Response__Sequence__destroy(hdwr_pkg__srv__HumanSrv_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hdwr_pkg__srv__HumanSrv_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hdwr_pkg__srv__HumanSrv_Response__Sequence__are_equal(const hdwr_pkg__srv__HumanSrv_Response__Sequence * lhs, const hdwr_pkg__srv__HumanSrv_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hdwr_pkg__srv__HumanSrv_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hdwr_pkg__srv__HumanSrv_Response__Sequence__copy(
  const hdwr_pkg__srv__HumanSrv_Response__Sequence * input,
  hdwr_pkg__srv__HumanSrv_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hdwr_pkg__srv__HumanSrv_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hdwr_pkg__srv__HumanSrv_Response * data =
      (hdwr_pkg__srv__HumanSrv_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hdwr_pkg__srv__HumanSrv_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hdwr_pkg__srv__HumanSrv_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hdwr_pkg__srv__HumanSrv_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
