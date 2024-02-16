# Install script for directory: /home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-cv2x-optimized.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-cv2x-optimized.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-cv2x-optimized.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/lib/libns3-dev-cv2x-optimized.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-cv2x-optimized.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-cv2x-optimized.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-cv2x-optimized.so"
         OLD_RPATH "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3-dev-cv2x-optimized.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ns3" TYPE FILE FILES
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-common.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-spectrum-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-spectrum-signal-parameters.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-spectrum-value-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-amc.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-rrc.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-rrc.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rrc-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rrc-protocol-ideal.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rrc-protocol-real.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-sequence-number.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-am-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-tm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-um.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-am.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rlc-sdu-status-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-pdcp-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-pdcp.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-pdcp-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-pdcp-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_eps-bearer.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-radio-bearer-info.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-net-device.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-net-device.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-net-device.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-control-messages.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_lte-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_lte-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_epc-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_point-to-point-epc-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_phy-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_mac-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_phy-tx-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_phy-rx-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_radio-bearer-stats-calculator.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_radio-bearer-stats-connector.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_radio-environment-map-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_lte-hex-grid-enb-topology-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_lte-global-pathloss-database.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_lte-prose-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_lte-v2x-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_rem-spectrum-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_ff-mac-common.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_ff-mac-csched-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_ff-mac-sched-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-cmac-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-cmac-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-mac-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_rr-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-mac.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-mac.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-radio-bearer-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_eps-bearer-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-phy-tag.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-phy-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-cphy-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-phy-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-cphy-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-interference.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-chunk-processor.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_pf-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_fdmt-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_tdmt-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_tta-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_fdbet-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_tdbet-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_fdtbfq-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_tdtbfq-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_pss-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_cqa-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_trace-fading-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-gtpu-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-enb-application.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-sgw-pgw-application.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-vendor-specific-parameters.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-x2-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-x2-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-x2.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-tft.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-tft-classifier.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-mi-error-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-enb-s1-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-s1ap-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-s11-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-as-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-ue-nas.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-harq-phy.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_epc-mme.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-asn1-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-rrc-header.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-handover-management-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-handover-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_a2-a4-rsrq-handover-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_a3-rsrp-handover-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_no-op-handover-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-anr-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-anr.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ffr-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ffr-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ffr-rrc-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-fr-no-op-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-fr-hard-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-fr-strict-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-fr-soft-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ffr-soft-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ffr-enhanced-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ffr-distributed-algorithm.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-power-control.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ccm-rrc-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-ccm-rrc-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ccm-mac-sap.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-enb-component-carrier-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-ue-component-carrier-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_no-op-component-carrier-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_simple-ue-component-carrier-manager.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/helper/cv2x_cc-helper.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_component-carrier.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_component-carrier-ue.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_component-carrier-enb.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-sl-tft.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_sl-pool.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_sl-pool-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_sl-resource-pool-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_sl-v2x-resource-pool-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_sl-preconfig-pool-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_sl-v2x-preconfig-pool-factory.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-sl-chunk-processor.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-sl-interference.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_rr-sl-ff-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_lte-phy-error-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_3gpp-cal-mac-scheduler.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_3gpp-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_nist-parabolic-3d-antenna-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_cni-urbanmicrocell-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_nist-urbanmacrocell-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_nist-scm-urbanmacrocell-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_nist-indoor-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_nist-outdoor-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/cv2x/model/cv2x_nist-hybrid-propagation-loss-model.h"
    "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/include/ns3/cv2x-module.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/cmake-cache/src/cv2x/examples/cmake_install.cmake")

endif()

