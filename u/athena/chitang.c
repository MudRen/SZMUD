
// ����ܰ(Athena) 
// Room��/u/athena/chitang.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",MAG"����"NOR);
	set("long", @LONG
һ�س�ˮӳ�����������С������Ȼˮ�У����۵�ʯ���ϼ�
�����ٻ���ض�����Կ�����Ϫ¥����¥�����ص�С������
ӳ�ڻ�ľɽʯ֮�䡣������ɽ���䣬���������������������
����ľ����������������㣬������Ƣ�����£�ˮ��������ʯ��
�أ��㲻��Ϊ�˾�����̾���ѡ�
LONG	);
        set("exits", ([ 
	"south" : __DIR__"zhibaixuan",
	]));
        set("objects", ([
                __DIR__"obj/rose" : 1,
]));
	set("outdoors", "Sufu" );
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
