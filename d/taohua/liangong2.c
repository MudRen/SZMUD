// Code of ShenZhou
//Kane
// modified by sdong to anti-robot, 7/12/1999
//����(discuss <����> <����> )���� by maco 9/2/1999

inherit ROOM;

#include "discuss.h"
#include <ansi.h>

//int in_ask, answer;
//int bCheckingRobot;
//object partner;

void create()
{
	set("short", "������");
	set("long", @LONG
�����һ������ӵ������������Ӷ��벿ɢ���ż������ţ�������Ӵ������ɣ���
����Ϣ�������ڹ�֮�á����벿��������ŷ�����ʮ���Եķ�λ���󣬴������ϰ��
�Ŷݼ����á��������һЩ���顣
LONG
	);
	 set("exits", ([
		"west" : __DIR__"changlang",
	]));

	 set("objects", ([
		__DIR__"obj/tiexiao" : 1,
		__DIR__"obj/zhuxiao" : 1,
		__DIR__"obj/yijing3" : 1,
		__DIR__"obj/bagua" : 1,
	]));

	set("no_fight", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_discuss", "discuss");
	add_action("do_answer", "answer");
	add_action("do_answer", "da");
}
