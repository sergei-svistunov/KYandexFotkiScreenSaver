#ifndef CHTTP_H_
#define CHTTP_H_

#include "curl/curl.h"
#include "curl/easy.h"

class CHTTP {
public:
    CHTTP();
    virtual ~CHTTP();
    bool Get(const char * URL, const char * FileName);
private:
    CURL* _curl;
};

#endif /* CHTTP_H_ */

