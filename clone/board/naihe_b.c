  //  ��Ϯ������������  /u/naihe/myobj/naihe_b.c
  //  by naihe  2002-04-09

#include <ansi.h>
  inherit BULLETIN_BOARD;

  void create()
  {
          set_name(YEL"��ֽ"NOR, ({ "paper" }) );
                  set("location", "/u/naihe/naihe_room");
          set("board_id", "naihe_b");
          set("long", "һ�ŷ��Ƶ���ֽ������д��������������С�֡�\n" );
          setup();
          set("capacity", 200);
          replace_program(BULLETIN_BOARD);
  }

