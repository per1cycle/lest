# add generator for lest.
add_library(liblest SHARED
            lest.cc
            lest-assert.cc
			lest-compare.cc
			lest-log.cc
            lest-internal.cc
            lest-generator.cc
            lest-testing.cc)

if(LEST_GENERATE_REPORT)
    target_link_libraries(liblest xml2)
endif(LEST_GENERATE_REPORT)
