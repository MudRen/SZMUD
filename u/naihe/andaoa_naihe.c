  //                ��׼��������ʾ��                                   |
  // ������ĵ�һ������ andaoa_naihe.c δ���
  // by naihe  2002-05-15

#include <ansi.h>
  inherit ROOM;

  void create()
  {
          set("short", BLU"���°���"NOR);
          set("long", "������ں����ģ�ʲôҲ����������ֻ��������grope������ǰ�ߡ�\n");
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
          return "��������ȥ��ʲôҲ��������\n";
  }

