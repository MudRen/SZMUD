// Code of ShenZhou
inherit ROOM;
#include <ansi.h>
#include "battlefield.h"

void create()
{
  set("short", HIG"���䳡"NOR);
  set("long", @LONG
������Ǳ��䳡�ˣ���·Ӣ�����������֣�ף����ˣ�
����ɱ��һ����Һ�Ҫ���˽����� (finish)���߳����䳡��
LONG
  );

  set("exits", ([
		 "north" : __DIR__"bf1",
		 "out" : __DIR__"exit1",
		 ]));
  // must have this line
  createRoom();
  setup();
}

void init()
{
  // must have this line
  initRoom();
  add_action("do_jump", "jump");
}

int do_jump(string arg)
{
  if (!arg || arg!="out")
	return notify_fail("��Ҫ���Ķ�����\n");
  message_vision("$N����һԾ���ӱ��䳡���˳�ȥ��\n", this_player());
  this_player()->move("/d/xingxiu/xueling/exit1");

  message_vision("$N�ӱ��䳡�����˳�����\n", this_player());
  return 1;
}

int valid_leave(object who, string dir)
{
  if (!wizardp(who) && dir == "out") 
    return notify_fail("��Ҫ�������ȥ�� jump out\n");
  return ::valid_leave(who, dir);
}

