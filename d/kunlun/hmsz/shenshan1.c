// shenshan1.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "����ɽ�");
                  set("long",@long
�����ɳ���棬����͸�ǣ�ȴҲ��ʵ�Ѱ�,��������ɽ��ת��תȥ��
,���涼�ǻ����ĸ��̲����ʯ��,��Ҳ�Ҳ�����ɽ��;����
long);
                 set("exits",([
"east" : __DIR__"shenshan1",
"south" : __DIR__"shenshan1",
"west" : __DIR__"shenshan1",
"north" : __DIR__"shenshan2",
]));

set("objects",([
                __DIR__"npc/injured_monkey" :  1,
                __DIR__"npc/gundog" :  2,
]));
set("outdoors", "kunlun");
        set("cost", 5);
setup();
replace_program(ROOM);
}
