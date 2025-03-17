
#include "lest.h"
#include <iostream>

int main(int argc, char **argv)
{
    LOG << "Running test from " << __FILE__;
    return RUN();
}
