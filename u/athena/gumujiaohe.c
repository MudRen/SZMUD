
// ����ܰ(Athena) 
// Room��/u/athena/gumujiaohe.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",MAG"��ľ��ڭ"NOR);
	set("long", @LONG
��ľ��ڭ����԰�����棬һ�Ų�ͬͼ����©����ʹ��͸��©
�����������в���ˮ��ɽɫ�͸ߵʹ����¥�󣬴˴��;���ȴ��
���Ʋ���Ӱ��֮��������׿���ң������������ɪ¥������һ
�֡�ͥԺ��������Ϳռ䲻��֮�С�
LONG	);
        set("exits", ([ 
	"east" : __DIR__"hehuating",
	]));
        set("objects", ([
                __DIR__"obj/yushi" : 1,
]));
	set("outdoors", "Sufu" );
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
