// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG
���Ƕػ�ʯ���е�һ�����ߣ�ǽ����һ����������ʱ�ڵıڻ���
���������򻭽�Ӱ�죬���ǵ����еף����Խ𡢺졢����ɫ�������塣
�������ݶ��Ƿ𾭹��£������ιӥ���������ߡ�
LONG);

  set("exits", ([ 
  "west" : __DIR__"dtongdao3",
]));
  set("objects", ([
                "/d/emei/obj/yugajing2" : 1,
                "/d/qilian/obj/fojing3" : 1,
                "/d/shaolin/obj/fojing20" : 1,
        ]));
	set("cost", 2);
  setup();
  replace_program(ROOM);
}

