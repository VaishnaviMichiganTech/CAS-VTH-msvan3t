# CMake generated Testfile for 
# Source directory: /home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/tap-bridge
# Build directory: /home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/cmake-cache/src/tap-bridge
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest-tap-creator "ns3-dev-tap-creator-optimized")
set_tests_properties(ctest-tap-creator PROPERTIES  WORKING_DIRECTORY "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build/src/tap-bridge/" _BACKTRACE_TRIPLES "/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/build-support/macros-and-definitions.cmake;1337;add_test;/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/tap-bridge/CMakeLists.txt;47;set_runtime_outputdirectory;/home/vaishnavi/project/V2I_WorkingVersion1.3/ms-van3t/ns-3-dev/src/tap-bridge/CMakeLists.txt;0;")
subdirs("examples")
