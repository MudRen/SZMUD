// Code of ShenZhou
// Room: /d/xixia/yinfang.c

inherit ROOM;

void create()
{
	set("short", "Ӫ��");
	set("long", @LONG
����������Ӫ��Ӫ����һ����ľ��ɷ������, �ſڿյ�����ʿ
��Χ�ɸ�Ȧ�����֣����ľ��г����������������Ӣ�ۣ�ʿ��������
�Ǳ��δ󺺡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"biaoqiyin",
]));
	set("objects", ([
                __DIR__"npc/xxbing2" : 3,
        ]));
	set("cost", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
