#ifndef __TEA_h__
#define __TEA_h__


//TEA加密函数
void btea_encrypt( unsigned char* buf, unsigned char len, unsigned char* key );
//TEA解密函数
void btea_decrpyt( unsigned char* buf, unsigned char len, unsigned char* key );


#endif

