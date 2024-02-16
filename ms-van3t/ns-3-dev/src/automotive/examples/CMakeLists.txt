build_lib_example(
    NAME v2i-lte 
    SOURCE_FILES v2i-lte.cc
    LIBRARIES_TO_LINK
    ${libautomotive}
    ${liblte}
    ${libtraci}
    ${libcv2x}
    ${libnetanim}
)    
build_lib_example(
    NAME v2i-80211p
    SOURCE_FILES v2i-80211p.cc
    LIBRARIES_TO_LINK
    ${libautomotive}
    ${liblte}
    ${libtraci}
    ${libwave}
    ${libnetanim}
)
