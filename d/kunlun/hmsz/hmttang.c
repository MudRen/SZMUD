// hmttang.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "����");
                  set("long",@long
������һ����������,��߾��Ǻ�÷ɽׯ����,������һ��ů��.
long);
                 set("exits",([
"east" : __DIR__"luange",
"out" : __DIR__"hmgate",
]));

set("objects",([
                __DIR__"npc/qiaofu" :  1,
                __DIR__"npc/xiaofeng" :  1,
]));
              setup();
              replace_program(ROOM);
}
