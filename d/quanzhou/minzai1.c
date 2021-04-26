// Code of ShenZhou
// Room: /u/qfy/quanzhou/minzai1.c

inherit ROOM;

void create()
{
	set("short", "լ��");
	set("long", @LONG
����Ȫ�ݾ�����������С���ݺᣬ��ͨ�˴һʽ��ʯ�����ݣ��춥��ǽ��
  �����Գƣ�����������ɫ����ν�������£�С�����硣�����Ǽ�ϷԺ���ϱ�Ҳ
��һ��Ƭլ����
LONG
	);

	set("objects", ([ ]));

	set("outdoors", "quanzhou");

	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"xiyuan",
  		"south" : __DIR__"minzai2",
  		"east" : __DIR__"citong_s1",
	]));

	set("objects", ([ 
                __DIR__"npc/boy" : 2,
	]));

	set("no_clean_up", 0);

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
