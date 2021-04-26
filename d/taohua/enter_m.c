// Code of ShenZhou
// Room: // Date: 

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ʯ�����");
	set("long",@LONG
����һƬ������ɰʯ̲���ϱ���һ��СС�ĸ��壬�����ƺ���
һ����ʯ�󣬵���һ�ɱ�����������ʯ��ʹ�˿����������о�
����ͨ�����е�ΨһС·�ֱ�һ���ʯ��(shibei)��ס��
LONG
	);

	set("exits", ([
		"south" : __DIR__"harbor",
	]));

	set("item_desc", ([
	"shibei" : "
ʯ������ʮ�ֹ⻬���ƺ�������������Ħ���������м����֣�
����������ص�������������˳��֪�����档
\n",
	]));

	set("cost", 2);
	setup();
}

void init()
{
	 add_action("do_push", "push");
}


int do_push(string arg)
{
  object me = this_player();

  if (!arg || arg != "shibei")
    return notify_fail("ʲ�᣿\n");
  
  if ( me->query_str() < 25 && me->query("combat_exp") > 100000) {
    return notify_fail("��û��ô�������ᶯʯ����\n");
  }

/*
  if ( (me->query("age") - me->query("taohua_maze")) < me->query("taohua_maze2"))
    return notify_fail("�������ͨ���һ������������������\n");
*/

  message_vision(HIW"ʯ������������棬ʯ����ӿ��һ�ɹַ�Ю��Ũ����$N������\n$N��Ӱ��ʱ��ʧ��Ũ��֮��......\n\n\n\n\n"NOR,me);
  if( me->query("taohua_maze") )
	me->move("/d/taohua/maze/zhongshu");
  else
	me->move("/d/taohua/maze/maze"+(random(63)+1));
	
  return 1;
}
