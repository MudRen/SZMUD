// Code of ShenZhou
inherit ROOM;
#include <ansi.h>
#include "battlefield.h"

void create()
{
  set("short", HIG"��Ժ����"NOR);
  set("long", @LONG
������Ǳ��䳡�ˣ���·Ӣ�����������֣�ף����ˣ�
����ɱ��һ����Һ�Ҫ���˽����� (finish)���߳����䳡��
LONG
  );

  set("exits", ([
		 "south" : __DIR__"bf1",
		 "north" : __DIR__"bf1nn",
		 "east" : __DIR__"bf1ne",
		 ]));
  // must have this line
  createRoom();
  setup();
}

void init()
{
  // must have this line
  initRoom();
}

