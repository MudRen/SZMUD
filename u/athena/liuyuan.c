
// ����ܰ(Athena) 
// Room��/u/athena/liuyuan.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"��԰"NOR);
	set("long", @LONG
��԰�����ݵ�һ������֮һ�����Խṹ���ֽ��ܡ����û���
��֡�װ�ξ������Ŷ����С����е�һ��԰��֮����
LONG	);
        set("exits", ([ 
	"west" : __DIR__"hehuating",
	"north" : __DIR__"zhibaixuan",
        "south"  : "u/athena/workroom", 
        "east" : __DIR__"shizilin",
	]));
	set("outdoors", "Sufu" );
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

