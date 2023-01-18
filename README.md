# Log
A super simple header-only logger for C/C++

## Example
```c
#define LOG_LEVEL LOG_LEVEL_ALL
#include "log.h"

int main(void) {
    LOG_TRACE("This is a trace message");
    LOG_DEBUG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARN("This is a warning message");
    LOG_ERROR("This is an error message");
    LOG_FATAL("This is an error message, and will abort the program");
}
```

### Output
![](output.png)
