// Code of ShenZhou
// Room: /d/dali/shibei.c

inherit ROOM;

void create()
{
	set("short", "��������ʮ�߲����˱�");
	set("long", @LONG
�˱������������꣬�Ǵ����������ʱ��������൱����
̫�濪�����꣬����һ.�����ף�����.����ף�����ʮһ�У�ÿ
��ʮ���֣���ĩ��ְ���������У�ÿ���������ȣ����Ĺ��ƶ���
���֡�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"taihejie6.c",
]));
        set("objects", ([
                "/d/village/npc/boy" : 1,
		"/d/village/npc/girl" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
