#ifndef _LIBVCHAN_H
#define _LIBVCHAN_H

#include <libkvmchan.h>

typedef int EVTCHN;
typedef struct libkvmchan libvchan_t;

LIBKVMCHAN_EXPORTED libvchan_t *libvchan_server_init(int domain, int port, size_t read_min, size_t write_min);

LIBKVMCHAN_EXPORTED libvchan_t *libvchan_client_init(int domain, int port);

LIBKVMCHAN_EXPORTED int libvchan_write(libvchan_t *ctrl, const void *data, size_t size);
LIBKVMCHAN_EXPORTED int libvchan_send(libvchan_t *ctrl, const void *data, size_t size);
LIBKVMCHAN_EXPORTED int libvchan_read(libvchan_t *ctrl, void *data, size_t size);
LIBKVMCHAN_EXPORTED int libvchan_recv(libvchan_t *ctrl, void *data, size_t size);
LIBKVMCHAN_EXPORTED int libvchan_wait(libvchan_t *ctrl);
LIBKVMCHAN_EXPORTED void libvchan_close(libvchan_t *ctrl);
LIBKVMCHAN_EXPORTED EVTCHN libvchan_fd_for_select(libvchan_t *ctrl);
LIBKVMCHAN_EXPORTED int libvchan_is_open(libvchan_t *ctrl);

LIBKVMCHAN_EXPORTED int libvchan_data_ready(libvchan_t *ctrl);
LIBKVMCHAN_EXPORTED int libvchan_buffer_space(libvchan_t *ctrl);

#endif
