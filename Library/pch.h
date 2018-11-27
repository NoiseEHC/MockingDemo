#ifndef PCH_H
#define PCH_H

#include <vector>
#include <iostream>
#include <fstream>
#include <thread>
#include <atomic>
#include <utility>
#include <string>

#include <fmt/core.h>

#if _DEBUG
#define MOCKABLE virtual
#define FINAL
#else
#define MOCKABLE
#define FINAL final
#endif

#endif //PCH_H
