
// ����ܰ(Athena) 
// Room��/u/athena/hehuating.c 

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",MAG"�ɻ���"NOR);
	set("long", @LONG
�ɻ������������������䣬��ָ�ˬ������ȡ���䣺��һˮ
�����̣�ǧ���Ա�족֮ʫ�⡣��ǰ����ƽ̨���ٺɳأ�Ϊ��
���ͺ�����ʤ�����ʳơ��ɻ������������л�̨ͥԺ����ʯ����
���Գ�һ����
LONG	);
      
        set("exits", ([ 
	"east" : __DIR__"liuyuan",
        "west" : __DIR__"gumujiaohe",
	]));
	set("outdoors", "Sufu" );
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

