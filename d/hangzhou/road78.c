// Code of ShenZhou
// Ǯ������
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", HIC"Ǯ������"NOR);
    set("long", @LONG
Ǯ������ÿ�����ʮ���ǹ۳��ĺ����ӡ�������ʮ�˳���׳����
���ޡ�����ˮ��ʱ��Զ�������Ὥ�������ģ�����ب��ɽ��������
��������ɲ�Ǽ䣬�������ڣ��������꣬�������ţ������ڣ�����
��������ת�ۣ����Լݳ��硣���������ɽ��˪ѩ�С���׳�����ơ�
��������ɽ�㵽����������
LONG	);

    set("exits", ([ /* sizeof() == 2 */ 
                   "east" : __DIR__"village",
                   "westup" : __DIR__"liuhe1", 
                   "north" : __DIR__"road77",  
                 ])
       );
	set("objects",([
                "/d/taishan/npc/jian-ke" : 1,
        ]));
	set("cost", 1);
        set("fjing", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
