#include "sqlite3.h"

/* 
 * Stub implementation of sqlite3_load_extension for WASM targets.
 * This will always return SQLITE_ERROR, as dynamic loading is not supported.
 */
#ifdef __WASM32__
int sqlite3_load_extension(
  sqlite3 *db,
  const char *zFile,
  const char *zProc,
  char **pzErrMsg
) {
  if (pzErrMsg) {
    *pzErrMsg = sqlite3_mprintf("load_extension is not supported on WASM targets");
  }
  return SQLITE_ERROR;
}

int sqlite3_enable_load_extension(sqlite3 *db, int onoff) {
  return SQLITE_ERROR;
}
#endif /* __WASM32__ */