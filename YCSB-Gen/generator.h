//
//  generator.h
//  YCSB-C
//
//  Created by Jinglei Ren on 12/6/14.
//  Copyright (c) 2014 Jinglei Ren <jinglei@ren.systems>.
//

#ifndef YCSB_C_GENERATOR_H_
#define YCSB_C_GENERATOR_H_

#include <cstdint>
#include <string>

#include "utils.h"

namespace ycsbc {

template <typename Value>
class Generator {
 public:
  uint64_t min_ = 0;
  uint64_t max_ = 0;
  virtual Value Next() = 0;
  virtual Value Last() = 0;
  virtual ~Generator() { }
};

} // ycsbc

#endif // YCSB_C_GENERATOR_H_
