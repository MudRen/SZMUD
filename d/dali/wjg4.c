// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�����µ�С�������ϵ���һ�Ծ��򣬶�������
�������������÷����գ�����˳��ȴ�ҳ�������÷
�գ������ϵĴ����ﶬ����ҳ��˶��Ĵ��������
�����˱��Ǹ����ˡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"wjg2.c",
	]));

	set("objects", ([
		__DIR__"npc/ganbaobao": 1,
		__DIR__"npc/yahuan": 1,
	]));

	set("cost", 1);
	setup();
}
