//Board//8/01/2001
//by jiuer 

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
 set_name(HIW"*** "HIW"ת������"HIW"*** "NOR, ({ "board" }) );
  set("location", "/u/angelo/histroom");
           set("poster_level", "(apprentice)");
          set("intermud", 1); 
          set("board_id", "trans_b");
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
