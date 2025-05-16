function(add_lest_test TARGET SOURCE)
    add_executable(${TARGET} ${SOURCE})
    target_link_libraries(${TARGET} liblest)
endfunction(add_lest_test)

add_lest_test(test-assert test-assert.cc)
