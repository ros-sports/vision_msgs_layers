// Copyright 2022 Kenji Brameld
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef VISION_MSGS_LAYERS__VISIBILITY_CONTROL_H_
#define VISION_MSGS_LAYERS__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define VISION_MSGS_LAYERS_EXPORT __attribute__ ((dllexport))
    #define VISION_MSGS_LAYERS_IMPORT __attribute__ ((dllimport))
  #else
    #define VISION_MSGS_LAYERS_EXPORT __declspec(dllexport)
    #define VISION_MSGS_LAYERS_IMPORT __declspec(dllimport)
  #endif
  #ifdef VISION_MSGS_LAYERS_BUILDING_LIBRARY
    #define VISION_MSGS_LAYERS_PUBLIC VISION_MSGS_LAYERS_EXPORT
  #else
    #define VISION_MSGS_LAYERS_PUBLIC VISION_MSGS_LAYERS_IMPORT
  #endif
  #define VISION_MSGS_LAYERS_PUBLIC_TYPE VISION_MSGS_LAYERS_PUBLIC
  #define VISION_MSGS_LAYERS_LOCAL
#else
  #define VISION_MSGS_LAYERS_EXPORT __attribute__ ((visibility("default")))
  #define VISION_MSGS_LAYERS_IMPORT
  #if __GNUC__ >= 4
    #define VISION_MSGS_LAYERS_PUBLIC __attribute__ ((visibility("default")))
    #define VISION_MSGS_LAYERS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define VISION_MSGS_LAYERS_PUBLIC
    #define VISION_MSGS_LAYERS_LOCAL
  #endif
  #define VISION_MSGS_LAYERS_PUBLIC_TYPE
#endif

#endif  // VISION_MSGS_LAYERS__VISIBILITY_CONTROL_H_
