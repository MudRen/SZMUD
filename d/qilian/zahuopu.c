// Code of ShenZhou
// Summer, 10/3/96. 

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ��
̯������һ������(zhaopai)��
LONG
	);

	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ��С�����\n",
	]));
	set("exits", ([
		"north" : __DIR__"weststreet",
	]));
	set("objects", ([
		__DIR__"npc/xiao-fan": 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

