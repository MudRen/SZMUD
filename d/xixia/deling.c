// Code of ShenZhou
// Room: /d/xixia/deling.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������Ԫ껵ĸ����Ե�������Ĺ����ʮ�׸����ף�Ϊ����������
��ߴ�Ҳ���������Ľ�������ǰ���Ҹ�������ʯ����ʿ��������ǰ��
����������Χ�ɵ�ƽ̨������ʯ��ʯ��һӦ��ȫ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gongling",
  "south" : __DIR__"chiling",
]));
	set("objects", ([
		__DIR__"npc/lingshi" : 3,
	]));
	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
