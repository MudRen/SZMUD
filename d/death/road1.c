// Code of ShenZhou
// Room: /d/death/road1.c

inherit ROOM;

void create()
{
	set("short", "���Ŵ��");
	set("long", @LONG
������һ����ɭɭ��·��, ŨŨ���������������, ������
Զ������ɢȥ�Ƶ�. ���Ͽ�ȥ����ǿ���Էֱ��һ����¥��ģ��,
������Լ���Կ�����յ����, ��Ũ�����Եø���Ĺ���. ·������
����һ��ľ��Ľ���, �Ŷ��ǰ뿪��, ���㿴�����������ʲ��.

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/death/road2",
  "south" : "/d/death/gateway",
  "west" : "/d/death/inn1",
  "east" : "/d/death/inn2",
]));

	set("no_fight", 1);
	set("cost", 0);
	setup();
}

void init()
{
        add_action("do_suicide","suicide");

}

int do_suicide(string arg)
{
        object me = this_player();
        tell_object(me, "�㻹�����ء�\n");
        return 1;
}


