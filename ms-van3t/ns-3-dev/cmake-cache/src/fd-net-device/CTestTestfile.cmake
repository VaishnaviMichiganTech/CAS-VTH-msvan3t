# CMake generated Testfile for 
# Source directory: /home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/fd-net-device
# Build directory: /home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/cmake-cache/src/fd-net-device
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest-raw-sock-creator "ns3-dev-raw-sock-creator-optimized")
set_tests_properties(ctest-raw-sock-creator PROPERTIES  WORKING_DIRECTORY "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/src/fd-net-device/" _BACKTRACE_TRIPLES "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build-support/macros-and-definitions.cmake;1337;add_test;/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/fd-net-device/CMakeLists.txt;164;set_runtime_outputdirectory;/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/fd-net-device/CMakeLists.txt;0;")
add_test(ctest-tap-device-creator "ns3-dev-tap-device-creator-optimized")
set_tests_properties(ctest-tap-device-creator PROPERTIES  WORKING_DIRECTORY "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/src/fd-net-device/" _BACKTRACE_TRIPLES "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build-support/macros-and-definitions.cmake;1337;add_test;/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/fd-net-device/CMakeLists.txt;199;set_runtime_outputdirectory;/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/fd-net-device/CMakeLists.txt;0;")
subdirs("examples")
