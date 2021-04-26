//angelo_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
  set_name(HIW"*** "HIW"±¿±¿¼ÇÊÂÂ¼"HIW"*** "NOR, ({ "board" }) );
    set("location", "/u/angelo/workroom");

            set("board_id", "angelo_b");

        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
