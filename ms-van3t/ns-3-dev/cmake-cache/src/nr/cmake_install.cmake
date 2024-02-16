# Install script for directory: /home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-nr-optimized.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-nr-optimized.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-nr-optimized.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/lib/libns3-dev-nr-optimized.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-nr-optimized.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-nr-optimized.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-nr-optimized.so"
         OLD_RPATH "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-nr-optimized.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ns3" TYPE FILE FILES
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-phy-rx-trace.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-mac-rx-trace.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-point-to-point-epc-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-bearer-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-bearer-stats-connector.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-bearer-stats-simple.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/beamforming-helper-base.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/ideal-beamforming-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/realistic-beamforming-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/node-distribution-scenario-interface.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/grid-scenario-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/hexagonal-grid-scenario-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/file-scenario-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/cc-bwp-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-radio-environment-map-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-spectrum-value-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/scenario-parameters.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/three-gpp-ftp-m1-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-mac-scheduling-stats.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/helper/nr-sl-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-net-device.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-gnb-net-device.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-ue-net-device.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-gnb-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-ue-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-spectrum-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-interference.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-pdu-info.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-header-vs.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-header-vs-ul.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-header-vs-dl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-header-fs.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-header-fs-ul.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-header-fs-dl.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-short-bsr-ce.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-phy-mac-common.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-tdma-rr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-tdma-pf.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ofdma-rr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ofdma-pf.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-control-messages.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-spectrum-signal-parameters.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-radio-bearer-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-amc.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-sched-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-csched-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-phy-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-lte-mi-error-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-gnb-mac.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-ue-mac.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-rrc-protocol-ideal.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-harq-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/bandwidth-part-gnb.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/bandwidth-part-ue.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/bwp-manager-gnb.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/bwp-manager-ue.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/bwp-manager-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-harq-process.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-harq-vector.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-harq-rr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-cqi-management.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-lcg.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ns3.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-tdma.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ofdma.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ofdma-mr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-tdma-mr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ue-info.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ue-info-mr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ue-info-rr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-ue-info-pf.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-error-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-t1.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-t2.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-ir.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-cc.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-ir-t1.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-ir-t2.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-cc-t1.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-eesm-cc-t2.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-error-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-ch-access-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/beam-id.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/beamforming-vector.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/beam-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/ideal-beamforming-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/realistic-beamforming-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/sfnsf.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/lena-error-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-srs.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-mac-scheduler-srs-default.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-ue-power-control.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/realistic-bf-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/beam-conf-id.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-bwp-manager-ue.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-chunk-processor.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-comm-preconfig-resource-pool-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-comm-resource-pool-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-interference.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-mac-pdu-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-phy-mac-common.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-sci-f1a-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-sci-f2a-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-sci-f2-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-csched-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-harq.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-sched-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-scheduler-dst-info.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-scheduler-lcg.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-scheduler-ns3.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-mac-scheduler-simple.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/model/nr-sl-ue-phy-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/utils/file-transfer-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/utils/file-transfer-application.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/utils/three-gpp-channel-model-param.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/nr/utils/distance-based-three-gpp-spectrum-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/include/ns3/nr-module.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/cmake-cache/src/nr/examples/cmake_install.cmake")

endif()

