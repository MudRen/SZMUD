// Code of ShenZhou
// Room: /d/xiangyang/wofang2.c

inherit ROOM;

void create()
{
	set("short", "�Է�");
	set("long", @LONG
����Է��ǹ��Ҵ�С���ܽ�Ĺ뷿������һ����ױ�����ϵ�
��һ�Ժ����յ÷���ů����ء���ǰ��ɴ���ӵʹ������Ϸ�����
һ�Ű�ɫ��б���
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 5, "y" : -5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huilang1",
]));

	setup();
	replace_program(ROOM);
}
