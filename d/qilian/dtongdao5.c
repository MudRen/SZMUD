// Code of ShenZhou
inherit ROOM;

void create()
{
  set ("short", "��");
  set ("long", @LONG
����һ���������������������ǲ��ܣ�ǧ�𡢷��졢�ּˡ�
��������Ρ�
LONG);
set("exits", ([
  "east" : __DIR__"shiku0",
  "west" : "/d/xingxiu/mogaoku",
  "down" : __DIR__"dtongdao4",
]));
	set("cost", 1);
  setup();
  replace_program(ROOM);
}

