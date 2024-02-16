# Install script for directory: /home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-core-optimized.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-core-optimized.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-core-optimized.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/lib/libns3-dev-core-optimized.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-core-optimized.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-core-optimized.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-core-optimized.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ns3" TYPE FILE FILES
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/realtime-simulator-impl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/wall-clock-synchronizer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/int64x64-128.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/example-as-test.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/helper/csv-reader.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/helper/event-garbage-collector.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/helper/random-variable-stream-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/abort.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/ascii-file.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/ascii-test.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/assert.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/attribute-accessor-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/attribute-construction-list.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/attribute-container-accessor-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/attribute-container.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/attribute-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/attribute.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/boolean.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/breakpoint.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/build-profile.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/calendar-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/callback.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/command-line.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/config.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/default-deleter.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/default-simulator-impl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/deprecated.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/des-metrics.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/double.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/empty.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/enum.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/event-id.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/event-impl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/fatal-error.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/fatal-impl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/global-value.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/hash-fnv.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/hash-function.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/hash-murmur3.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/hash.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/heap-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/int-to-type.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/int64x64-double.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/int64x64.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/integer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/length.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/list-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/log-macros-disabled.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/log-macros-enabled.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/log.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/make-event.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/map-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/math.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/names.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/node-printer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/nstime.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/object-base.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/object-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/object-map.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/object-ptr-container.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/object-vector.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/object.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/pair.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/pointer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/priority-queue-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/ptr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/random-variable-stream.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/ref-count-base.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/rng-seed-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/rng-stream.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/show-progress.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/simple-ref-count.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/simulation-singleton.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/simulator-impl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/simulator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/singleton.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/string.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/synchronizer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/system-path.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/system-wall-clock-ms.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/system-wall-clock-timestamp.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/test.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/time-printer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/timer-impl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/timer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/trace-source-accessor.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/traced-callback.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/traced-value.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/trickle-timer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/tuple.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/type-id.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/type-name.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/type-traits.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/uinteger.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/unix-fd-reader.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/unused.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/valgrind.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/vector.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/core/model/watchdog.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/include/ns3/config-store-config.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/include/ns3/core-config.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/include/ns3/core-module.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/cmake-cache/src/core/examples/cmake_install.cmake")

endif()

