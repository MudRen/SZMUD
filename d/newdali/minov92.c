// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov92.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ��������ķ��ݡ�������ӵĽ��غ����򽲾���������ɽ�ƣ�һ����
ʯΪǽ�ͻ�����ľΪ�����ṹ���ºͺ��˷�����£�����ƽ����ʯ��Χǽ�����
Ժ����һȦ������ţ����С�
LONG);
	set("objects", ([
		__DIR__"npc/wymuyang.c" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov91",
		]));
	set("area", "��Ū��");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
