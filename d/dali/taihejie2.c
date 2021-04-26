// Code of ShenZhou
// Room: /d/newdali/taihejie2.c

inherit ROOM;

void create()
{
	set("short", "���Ĺ㳡");
	set("long", @LONG
�������������ǵ����ģ���ɫʯ���̳ɵĴ�����ķ����ӡ���
�������Σ�һȦΧ�Ķ���С�������ˣ��Ϳ����ֵġ�������������Ⱥ
��Ҳ�ٲ��˼����ܽ���֮�ˣ�һЩ����ԭ����δ�ŵ�������һЩ����
����֮���˷ܲ��ѡ��������������Ĵ�����Է��
LONG
	);

	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"crossing.c",
		"north" : __DIR__"taihejie4.c",
		"east" : __DIR__"jiulou",
		"west" : __DIR__"qiyuan1.c",
		]));

	set("objects", ([
		__DIR__"npc/yiren" : 1,
		]));

	set("no_clean_up", 0);

	setup();
}
