// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov30.c

inherit ROOM;

void create()
{
	set("short", "ɣ��");
	set("long", @LONG
һ��Ƭɣ���������ڵ�ɽ�Ļ���ɽ���ϡ����ϡ���˿�ǰ��������Ҫ��ҵ��
���ĸ�Ů����֯˿����֯�Լ����ŵĶ�ȹ��Ҳ�������ٽ����佻��Щ������Ʒ��
һȺ���Ĺ��������ּ�æ�Ų�ժɣҶ��
LONG);
	set("objects", ([
		__DIR__"npc/bycaisang.c" : 3,
		]));
	set("exits", ([
		"northdown" : __DIR__"minov26",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
