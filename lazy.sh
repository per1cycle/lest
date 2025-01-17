build_playground() {
    echo "Building playground"
    echo "Warning: this function should be called in the build directory"
    cmake ..
    make -j
    ./playground/playground
}

build_whole() {
    echo "Building lest..."

}