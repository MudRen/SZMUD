// Code of ShenZhou
// Room: /dali/houshan.c
// AceP

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
���ߵ��˽������ĺ��棬����������ɽ�ĺ�ɽ��һ���ľ���С·ͨ������ɽ�ϣ�
�������Ӳݹ�ľ�ԡ�
LONG
	);

	set("exits", ([
		"south"  : __DIR__"jhg",
		"northup"  : __DIR__"yubi",
	]));

	set("cost", 3);
        set("outdoors", "dali");
	setup();
}
