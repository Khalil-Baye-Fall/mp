/*
 Stderr redirection

 Copyright (C) 2014 AMPL Optimization Inc

 Permission to use, copy, modify, and distribute this software and its
 documentation for any purpose and without fee is hereby granted,
 provided that the above copyright notice appear in all copies and that
 both that the copyright notice and this permission notice and warranty
 disclaimer appear in supporting documentation.

 The author and AMPL Optimization Inc disclaim all warranties with
 regard to this software, including all implied warranties of
 merchantability and fitness.  In no event shall the author be liable
 for any special, indirect or consequential damages or any damages
 whatsoever resulting from loss of use, data or profits, whether in an
 action of contract, negligence or other tortious action, arising out
 of or in connection with the use or performance of this software.

 Author: Victor Zverovich
 */

#ifndef TEST_ASL_STDERR_REDIRECT_H_
#define TEST_ASL_STDERR_REDIRECT_H_

#include "asl.h"

// Redirects Stderr to a file.
class StderrRedirect {
 private:
  std::FILE *saved_stderr;

 public:
  explicit StderrRedirect(const char *filename) : saved_stderr(Stderr) {
    Stderr = std::fopen(filename, "w");
  }
  ~StderrRedirect() {
    std::fclose(Stderr);
    Stderr = saved_stderr;
  }
};

#endif  // TEST_ASL_STDERR_REDIRECT_H_
