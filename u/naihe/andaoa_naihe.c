  //                标准描述长度示例                                   |
  // 暗道里的第一个房间 andaoa_naihe.c 未完成
  // by naihe  2002-05-15

#include <ansi.h>
  inherit ROOM;

  void create()
  {
          set("short", BLU"地下暗道"NOR);
          set("long", "暗道里黑乎乎的，什么也看不见，你只能摸索（grope）着往前走。\n");
          set("invalid_startroom",1);

          set("exits", ([
              "up": __DIR__"naihe_room",
  //          "down":__DIR__"andaob_naihe",
              ]));

          setup();
  }

  void init()
  {
          add_action("do_grope","grope");
  }

  string do_grope()
  {
          return "你摸来摸去，什么也摸不到。\n";
  }

