  //  抄袭而来，哈哈哈  /u/naihe/myobj/naihe_b.c
  //  by naihe  2002-04-09

#include <ansi.h>
  inherit BULLETIN_BOARD;

  void create()
  {
          set_name(YEL"破纸"NOR, ({ "paper" }) );
                  set("location", "/u/naihe/naihe_room");
          set("board_id", "naihe_b");
          set("long", "一张发黄的破纸，上面写着许多密密麻麻的小字。\n" );
          setup();
          set("capacity", 200);
          replace_program(BULLETIN_BOARD);
  }

