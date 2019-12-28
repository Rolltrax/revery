#ifdef __linux__
#include <libnotify/notify.h>

#include "utilities.h"
#include <caml/mlvalues.h>

void revery_dispatchNotification_gtk(const char *title, const char *body, value onClickFunc, int mute) {
  (void)onClickFunc;
  (void)mute;
  NotifyNotification *notification = notify_notification_new(title, body, NULL);
  notify_notification_show(notification, NULL);
}

#endif