// Code of ShenZhou
// Room: /d/dali/wuhua4.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ��ͷ�����ǽ����һ����ľ�󴲣�����ı��쾡����
�壬�������ס����з���һ�Ű���������������������ڸ�̸��
�ۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wuhua8.c",
]));
	set("objects", ([
__DIR__"npc/pucong" : 2,
        ]));

	set("no_clean_up", 0);
set("cost", 1);

	setup();
	replace_program(ROOM);
}
