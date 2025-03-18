/**
 * this sample unittest for a class which has member funciton.
 */

#include "lest.h"

// A simple string class.
class MyString {
 private:
  const char* c_string_;
  const MyString& operator=(const MyString& rhs);

 public:
  // Clones a 0-terminated C string, allocating memory using new.
  static const char* CloneCString(const char* a_c_string);

  ////////////////////////////////////////////////////////////
  //
  // C'tors

  // The default c'tor constructs a NULL string.
  MyString() : c_string_(nullptr) {}

  // Constructs a MyString by cloning a 0-terminated C string.
  explicit MyString(const char* a_c_string) : c_string_(nullptr) {
    Set(a_c_string);
  }

  // Copy c'tor
  MyString(const MyString& string) : c_string_(nullptr) {
    Set(string.c_string_);
  }

  ////////////////////////////////////////////////////////////
  //
  // D'tor.  MyString is intended to be a final class, so the d'tor
  // doesn't need to be virtual.
  ~MyString() { delete[] c_string_; }

  // Gets the 0-terminated C string this MyString object represents.
  const char* c_string() const { return c_string_; }

  size_t Length() const { return c_string_ == nullptr ? 0 : strlen(c_string_); }

  // Sets the 0-terminated C string this MyString object represents.
  void Set(const char* c_string);
};
// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.

#include <string.h>

// Clones a 0-terminated C string, allocating memory using new.
const char* MyString::CloneCString(const char* a_c_string) {
  if (a_c_string == nullptr) return nullptr;

  const size_t len = strlen(a_c_string);
  char* const clone = new char[len + 1];
  memcpy(clone, a_c_string, len + 1);

  return clone;
}

// Sets the 0-terminated C string this MyString object
// represents.
void MyString::Set(const char* a_c_string) {
  // Makes sure this works when c_string == c_string_
  const char* const temp = MyString::CloneCString(a_c_string);
  delete[] c_string_;
  c_string_ = temp;
}

TEST(MyString, Constructor)
{
    MyString empty_string;
    EQ(empty_string.Length(), 0);

    MyString str1("Hello");
    EQ(strcmp(str1.c_string(), "Hello"), 0);
    EQ(str1.Length(), 5);

    MyString str2("");
    EQ(strcmp(str2.c_string(), ""), 0);
    EQ(str2.Length(), 0);
}


TEST(MyString, SetMethod)
{
    MyString str;
    str.Set("NewString");
    EQ(strcmp(str.c_string(), "NewString"), 0);
    EQ(str.Length(), 9);

    str.Set("");
    EQ(strcmp(str.c_string(), ""), 0);
    EQ(str.Length(), 1);
}

