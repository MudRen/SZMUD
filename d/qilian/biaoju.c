// Code of ShenZhou
// Room: /d/qilian/biaoju.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
	set("short", "��ӥ�ھ�");
	set("long", @LONG
��������ӥ�ھֵ���������ֻ��Ƥ̫ʦ��һ���ſ�����������������ͷ��
ǽ�Ϲ��ż���ë̺�����е�ë̺������һֻ�޴��ѩɽ��ͷӥ����ѩɽ�ϰ��裬
���ƺ������������η��
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"lanzhou",
	]));

	set("objects", ([
		"/clone/npc/xibei" : 1,
	]));

	set("cost", 0);
        set("no_fight", 1);
	setup();
	replace_program(ROOM);
}

