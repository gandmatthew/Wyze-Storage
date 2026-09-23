#include "mongoose.h"

static void ev_handler(struct mg_connection *c, int ev, void *ev_data) {
  if (ev == MG_EV_HTTP_MSG) {
    struct mg_http_message *hm = (struct mg_http_message *) ev_data;
    if (mg_match(hm->uri, mg_str("/api/upload"), NULL)) {
      struct mg_http_part part;
      size_t ofs = 0;
      while ((ofs = mg_http_next_multipart(hm->body, ofs, &part)) > 0) {
        MG_INFO(("Chunk name: [%.*s] filename: [%.*s] length: %lu bytes",
                  (int) part.name.len, part.name.buf, (int) part.filename.len,
                  part.filename.buf, (unsigned long) part.body.len));
      }
      mg_http_reply(c, 200, "", "Thank you!");
    } else {
      mg_http_reply(c, 500, "", "{%m:%m}\n", MG_ESC("error"), MG_ESC("Unsupported URI")); 
    } 
  }
}

int main(void) {
  // Replace with IP address of WyzeCam
  char addr[] = "http://192.168.68.140:8000";

  struct mg_mgr mgr;
  mg_mgr_init(&mgr);
  mg_log_set(MG_LL_DEBUG);
  mg_http_listen(&mgr, addr, ev_handler, NULL);
  for (;;) {
      mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);
  return 0;
}

