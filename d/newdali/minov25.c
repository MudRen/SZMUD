// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov25.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��·��ɽ�������Ѽ������������ɽ��ͨ����ĵ��ݵش�������ɽ�ƽ�Ϊ
ƽ����ɽ����ż�����̣�͸�����ֵķ�϶������ȥ����Լ�ɼ�һ����ˮ��Щ��
���̡�
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov24",
		"eastdown" : __DIR__"minov26",
		]));
	set("area", "������");
	set("cost", 4);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
