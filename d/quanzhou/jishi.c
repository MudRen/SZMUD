// Code of ShenZhou
// jishi.c ����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�����Ǿ������ճ�������Ʒ���̷��Ƽ��ĳ�����������ƷӦ�о��У�������
  Ŀ��ͬʱ����Ҳ��������������˵��������ס����ϡ���ʯ���Ǳ����̼�������
������Ʒ����Ϊ���Ƕ�֪��һ�������˵���ԭ�������ü��������󡣲���
����Ϊ�����ﳤ����������������������Ϣ���������¾����ּۻ��۵�������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"tumen",
		"west" : __DIR__"xinmen",
		"south" : __DIR__"hjting",
	]));

	set("objects", ([ 
                __DIR__"npc/butou" : 1,
		__DIR__"npc/xiao-fan" : 1,
        ]));
        set("fanhua", 4);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
