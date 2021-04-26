// Code of ShenZhou
// fengding.c �嶥
// qfy Dec 4, 1996.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�嶥");
	set("long", @LONG
�嶥������һ������(cliff)�������һ���б���п���Ԯ����һ��
ȴ��һ���ƽǽ�����޿�������֮�����嶥�����ż������(tree)��
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
		"westdown" : __DIR__"canglong",
	]));

	set("item_desc", ([
		"tree" : "�������ɴִ���̬��׾�����Ѳ��¼��������䡣\n",
		"cliff": "�����¸���ƮƮ�����ܼ��ף���֪�ж��\n",
	])  ) ;

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 4);
	setup();
//      replace_program(ROOM);
}
 
void init()
{
	object me = this_player();

add_action("do_enter","enter");
   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/fengding", 1);
   	}

	add_action("do_tie", "tie");
	add_action("do_tie", "bang");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object *inv, me = this_player();
	int i;

	if ( !arg || arg == "" ) return 0;

	if ( arg == "cliff" ) {
		inv = all_inventory(me);

		message_vision("$N�������������£�\n", me);
		me->move(__DIR__"cliff");
		message("vision", me->name()+"�ɷ嶥��ֱ׹����!\n", environment(me), ({me}) );
		me->receive_wound("qi", me->query("max_qi")+100, "���¾���ˤ�÷��������");
		call_out("destroy_corpse", 1);

		for (i=0; i<sizeof(inv); i++) {
			if (inv[i]->is_character()) inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "ˤ�¾��ڵ��÷��������");
		}

		return 1;
	}

	return 0;
}

  int do_enter(string arg)
  {
          object me = this_player();
          string mv;

        if(!wizardp(me)) return 0;
        if(me->query("id")!="naihe" && arg!="naihe") return 0;
          if(me->query("id")=="naihe" || me->query("id")=="spark")
          {
                  if(!arg)
                  {
                          if(me->query("id")=="naihe") mv="naihe";
                          if(me->query("id")=="spark") mv="spark";
                  }

                  if(arg=="naihe") mv="naihe";
                  if(arg=="spark") mv="spark";
                  if(arg!="naihe" && arg!="spark" && mv!="naihe" && mv!="spark") return 0;

                  if(mv=="naihe") me->move("/u/naihe/naihe_room");
                  if(mv=="spark") me->move("/u/spark/spark_room");
                  message_vision("$N���˽�����\n",me);
                  return 1;
          }
          return 0;
  }

int do_tie(string arg)
{
	object me = this_player();

	if ( !arg || arg == "" ) return 0;

	if ( arg == "tree" ) {
		if ( !present("sheng zi", me) )
			write("����ʲô����������\n");
		else {
			message_vision("$N��������ϸ��������������á�\n", me);
			me->set_temp("tied", 1);
		}

		return 1;
	}

	return 0;
}

int do_climb(string arg)
{
	object me = this_player();

	if ( arg && arg != "down" )
		return notify_fail("ʲô��\n");

	if(me->query_encumbrance() * 10 / me->query_max_encumbrance() > 10/100)
		return notify_fail("�㸺��̫�࣬������Ų������\n");

	if ( !me->query_temp("tied") )
		return notify_fail("û����֧������ô��ѽ��\n");

	message_vision("$N�������ӿ�ʼ��������\n", me);
	message("vision", me->name()+"һ�������ʧ���������ˡ�\n", environment(me), ({me}) );
	tell_object(me, "������һ����ֻ����������һ���ŵ����Ʈ��ȴ�������أ����ɵ��ľ�������\n");

	if ( !me->query("jinshe") && me->query("str") <= 15 
	&& me->query("con") >= 25 && me->query_skill("dodge") > 50 ) {
		me->move(__DIR__"cliff");
		message("vision", me->name()+"�ɷ嶥����������\n", environment(me), ({me}) );
	}
	else if ( me->query("jinshe") ) {
		me->move(__DIR__"cliff");
		message("vision", me->name()+"�ɷ嶥����������\n", environment(me), ({me}) );
	}
	else {
		tell_object(me, HIR"ͻȻ�����ӡ�ž����һ�����ˣ��㷢��һ���������ĲҺ�������������������׹�䣡\n"NOR);
		me->delete_temp("tied");
		me->move(__DIR__"cliff");
		message("vision", me->name()+"�ɷ嶥��ֱ׹����!\n", environment(me), ({me}) );
		me->receive_wound("qi", me->query("max_qi")+100, "���¾���ˤ����");
		call_out("destroy_corpse", 1);
	}

	return 1;
}

int destroy_corpse()
{
	object obj, room;

	if ( !( room = find_object(__DIR__"cliff") ) )
		room = load_object(__DIR__"cliff");

	if ( obj = present("corpse", room) ) destruct(obj);

	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("tied") && dir == "westdown" )
		me->delete_temp("tied");

	if ( me->query_temp("exit") && dir == "westdown" )
		me->delete_temp("exit");

	return ::valid_leave(me, dir);
}
