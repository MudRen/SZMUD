// Code of ShenZhou
// zhongxin ���Ĺ㳡
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���Ĺ㳡");
	set("long", @LONG
����Ȫ�ݵ����ĵش�������Ũ�������뻮һ����ɽ�˺���Ħ����࣬����
��������Ⱥ��ʱ���ɼ���ͬ��ɫ�ĺ��ˡ�Ȫ�������ֲ��ͩ������������ͩ�ǡ���
�ǡ�����˿��֮·������㡣������Ƶ�����̼֡�ʹ�ں��ڽ���ͽԶ������
�����˵أ����в����˾Ͷ����ڴˡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"citong_n3",
		"south" : __DIR__"citong_s1",
		"east" : __DIR__"citong_e1",
		"west" : __DIR__"citong_w1",
	]));

        set("objects", ([ 
		__DIR__"npc/butou" : 1,
		__DIR__"npc/huren" : 1,
		__DIR__"npc/mao-fan" : 1,
        ]));

        set("no_clean_up", 0);
        set("fanhua", 4);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
