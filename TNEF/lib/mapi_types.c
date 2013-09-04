/* This file generated by names.awk do not edit! */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "common.h"
#include "mapi_types.h"
char*
get_mapi_type_str(uint16 d)
{
    static char buf[128];
    static char* str;
    switch(d) {
    case szMAPI_UNSPECIFIED:
        str="MAPI Unspecified";
        break;
    case szMAPI_NULL:
        str="MAPI null property";
        break;
    case szMAPI_SHORT:
        str="MAPI short (signed 16 bits)";
        break;
    case szMAPI_INT:
        str="MAPI integer (signed 32 bits)";
        break;
    case szMAPI_FLOAT:
        str="MAPI float (4 bytes)";
        break;
    case szMAPI_DOUBLE:
        str="MAPI double";
        break;
    case szMAPI_CURRENCY:
        str="MAPI currency (64 bits)";
        break;
    case szMAPI_APPTIME:
        str="MAPI application time";
        break;
    case szMAPI_ERROR:
        str="MAPI error (32 bits)";
        break;
    case szMAPI_BOOLEAN:
        str="MAPI boolean (16 bits)";
        break;
    case szMAPI_OBJECT:
        str="MAPI embedded object";
        break;
    case szMAPI_INT8BYTE:
        str="MAPI 8 byte signed int";
        break;
    case szMAPI_STRING:
        str="MAPI string";
        break;
    case szMAPI_UNICODE_STRING:
        str="MAPI unicode-string (null terminated)";
        break;
    case szMAPI_SYSTIME:
        str="MAPI time (64 bits)";
        break;
    case szMAPI_CLSID:
        str="MAPI OLE GUID";
        break;
    case szMAPI_BINARY:
        str="MAPI binary";
        break;
    default:
        str=NULL;
        break;
    }
    if ( str )
    {
        sprintf(buf,"%s <%04x>",str,d);
    }
    else
    {
        sprintf(buf,"%04x",d);
    }
    return buf;
}
