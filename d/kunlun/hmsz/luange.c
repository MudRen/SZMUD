// luange.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "ů��");
                  set("long",@long
������һ��ů��֮�С�����һ����Ϊ���䣬ů����ȴ��ů�紺��
���ֲ����δ�����̿�𣬵������г���ԻͲ��ã�������϶���
�Ž�����档
long);
                 set("exits",([
"east" : __DIR__"tingwai",
"west" : __DIR__"hmttang",
  "enter" : __DIR__"pianting",
]));

              setup();
              replace_program(ROOM);
}
