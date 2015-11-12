#ifndef _DAEMON_CLIENT_H_
#define _DAEMON_CLIENT_H_

#include <libuhuru/core.h>

struct client;

struct client *client_new(int client_sock, struct uhuru *uhuru);

void client_free(struct client *cl);

int client_process(struct client *cl);

#endif