#ifndef MDV_H
#define MDV_H

#define MAX_SECTORS 255

#include <stdint.h>

typedef struct {
  uint8_t preamble[12];   // 10*0, 2*ff
  uint8_t ff;
  uint8_t snum;
  char name[10];
  uint16_t rnd;
  uint16_t csum;
} __attribute__((packed)) hdr_t;

typedef struct {
  uint8_t bh_preamble[12];   // 10*0, 2*ff
  uint8_t file;
  uint8_t block;
  uint16_t bh_csum;

  uint8_t data_preamble[8];   // 6*0, 2*ff
  uint8_t data[512];
  uint16_t data_csum;

  uint8_t extra_byte[120];
} __attribute__((packed)) sector_t;

typedef struct {
  uint32_t length;
  uint8_t access;
  uint8_t type;        // 0=regular, 1=exec
  uint32_t info[2];
  uint16_t name_len;   // file name length
  char name[36];
  uint32_t last_update;
  uint32_t version;
  uint32_t last_backup;
} __attribute__((packed)) file_t;

typedef struct {
  hdr_t hdr;
  sector_t sec;
} mdv_entry_t;

typedef struct {
  int32_t long_id;   // signature
  int32_t extra_id;  // extra signature
  file_t file;
} __attribute__((packed)) zip_extra_qdos_t;

typedef struct {
  uint8_t flags;
  int32_t last_modified;
  int32_t last_access;
  int32_t creation;
} __attribute__((packed)) zip_extra_ur_t;

#endif // MDV_H

