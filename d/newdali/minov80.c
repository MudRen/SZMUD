// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov80.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������¥���в������Ჿ�������ã����г��Ϸ�Ҫ�ձ��ڴ˾������ڴ��£�
Ҳ�ڴ˽Ӵ������ͣ�����������ٸ�������ʹ�ߡ������Ա����ͼ�ڱڻ���
����Ƥëװ���ıڡ�
LONG);
	set("objects", ([
		__DIR__"npc/tyzuzhang" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov79",
		"up" : __DIR__"minov81",
		]));
	set("area", "³����");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
