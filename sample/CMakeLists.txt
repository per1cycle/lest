function(add_sample name)
  add_executable(${name} ${name}.cc)
  target_link_libraries(${name} liblest)
    
endfunction(add_sample name)

add_sample(sample0_unittest)
add_sample(sample1_unittest)
add_sample(sample2_unittest)
add_sample(sample3_unittest)
add_sample(sample4_unittest)