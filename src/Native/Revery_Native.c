#include <stdio.h>

#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>
#include <string.h>

#define UNUSED(x) (void)(x)

#ifdef WIN32
#include "ReveryWin32.h"
#elif __APPLE__
#include "ReveryCocoa.h"
#import "ReveryAppDelegate.h"
#else
#include "ReveryGtk.h"
#include <libnotify/notify.h>
#endif

CAMLprim value revery_initialize() {
#ifdef __APPLE__
  ReveryAppDelegate *delegate = [ReveryAppDelegate new];
  [NSApp setDelegate:delegate];
#elif __linux__
  gboolean res = notify_init("Revery");
  if (!res) {
    printf("WARNING: libnotify failed to initialize!\n");
  }
#endif
  return Val_unit;
}
