
// Code of ShenZhou
// Room: yuzf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǳ�������֮һ��������ʯ�壬��������Ʒ�������·�̡��˷�
���ʣ���һ��������������������أ��߲����ʣ���ν���Ʒ�֮�������˷�
ɽ·��᫣��ұ���·����Ϊ��ɽ�����һ�����ϡ�
LONG    );

        set("exits", ([ 
              "northwest" : __DIR__"lumf",
              "eastdown" : __DIR__"tianchi",
              "northeast" : __DIR__"baiyf",
              "southeast" : __DIR__"tiyf",
        ]));

        set("objects",([
                __DIR__"npc/tian" : 1,
        ]));
        
        set("fjing", 1);
        set("outdoors", "changbai");

        set("count", random(3)+1);

        setup();
}
int valid_leave(object me, string dir)
{
    if (dir=="southdown") {
        say (me->name()+"˳�������С·�����������Ӳ��ְ�·�ڸ�������\n");
        me->set_temp("new_valid_dest", "/d/changbai/fen");
	delete("exits/southdown");
               return 1;
    }
    return ::valid_leave(me, dir);
}
