// Code of ShenZhou
// Room: /d/dali/wuhua8.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����������ȣ�ͨ��������˵����ҡ�ëձ�Ѿ����ɴ��ף�����ľ��
�ϻ���л�����棬�����Щ��ʱ�˵��ֻ���ÿ���߰˲�������һ����̨������
���̴�ͭ�������γ�����֮����һ��
LONG);
	set("exits", ([
		"east" : __DIR__"wuhua3.c",
		"enter" : __DIR__"wuhua4.c",
		]));
	set("cost",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
