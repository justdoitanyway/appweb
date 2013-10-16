/*
    ${NAME} Controller
 */
#include "esp.h"

static void create${TITLE}() { 
    renderResult(updateRec(createRec("${TABLE}", params())));
}

static void get${TITLE}() { 
    renderRec(readRec("${TABLE}", param("id")));
}

static void init${TITLE}() { 
    renderRec(createRec("${TABLE}", 0));
}

static void list${TITLE}() {
    renderGrid(readTable("${TABLE}"));
}

static void remove${TITLE}() { 
    renderResult(removeRec("${TABLE}", param("id")));
}

static void update${TITLE}() { 
    renderResult(updateRec(setFields(readRec("${TABLE}", param("id")), params())));
}

ESP_EXPORT int esp_controller_${APP}_${NAME}(HttpRoute *route, MprModule *module) {
    espDefineAction(route, "${NAME}-create", create${TITLE});
    espDefineAction(route, "${NAME}-get", get${TITLE});
    espDefineAction(route, "${NAME}-init", init${TITLE});
    espDefineAction(route, "${NAME}-list", list${TITLE});
    espDefineAction(route, "${NAME}-remove", remove${TITLE});
    espDefineAction(route, "${NAME}-update", update${TITLE});
${DEFINE_ACTIONS}    return 0;
}