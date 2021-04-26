// Code of ShenZhou
// road: /zhongnan/xuanya3.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
int do_climb(string arg);
int do_exercise(string arg);
int do_practice(string arg);
int do_study(string arg);

void create()
{
		  set("short",HIC"����"NOR);

		  set("long",@LONG
�����������ϣ��������涼�����ҹ�ʯ��Խ���Ͼ�Խ���ʣ������������¶�
��ڣ���ݲ���������һ�ƣ�ֻ�ŵû����ɢ��ԭ������ʱһ������Ӳͦ�����ԭ
·��ȥʱ�����������֮���Ѹ�͹������ʯ��ס����Ҳ��������������ӿ������һ
�����Ʊ�����ɽʯ��ײ������ֻ�޴�ĺڵ������ڿ��С�
LONG);

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_exercise",  "exercise");
	add_action("do_exercise",  "dazuo");
	add_action("do_exercise",  "respirate");
	add_action("do_exercise",  "tuna");
	add_action("do_practice",  "practice");
	add_action("do_practice",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
}

int do_exercise(string arg)
{
		  object me = this_player();
		  tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ�������������\n");
		  return 1;
}

int do_practice(string arg)
{
		  object me = this_player();
		  tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ�������������\n");
		  return 1;
}

int do_study(string arg)
{
		  object me = this_player();
		  tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ��������鰡��\n");
		  return 1;
}

int do_climb(string arg)
{
	object me = this_player();
	int gain,cost;

	if(me->is_busy())
		return notify_fail("�㻹��æ���ء�\n");

	if( me->query_skill("dodge") < 135 && arg == "up" )
		return notify_fail("�����������¶���ڣ����Ṧ��������ôҲ������ȥ��\n");

	cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
	if ( cost<10 )cost = 10;
	cost = cost * 3;

	if( me->query("jingli") < 30)
		return notify_fail("���۵�ʵ���������ˡ�\n");

	me->start_busy( 1 );

	me->add("jingli",-cost);

	if( arg != "up" && arg != "down" )
		return notify_fail("�Ǹ�����û������\n");

	gain = me->query("con",1)*2;
	gain *= 3;

	if ( me->query_skill("dodge") > 300 ) gain /= 2;

	me->improve_skill( "dodge",gain/2+random( gain ) );
	if( me->query_skill( "jinyangong",1) > 0 )
		me->improve_skill( "jinyangong",random( gain ) );


	if(arg == "up" )
	{
		message_vision( HIY"\n$N�����������ٸ���һ����������ȥ��\n"NOR, me);
		me->move("/d/zhongnan/xuanya4");
		message_vision( HIY"\n$N����������\n"NOR, me);
		me->improve_skill( "dodge",(gain+random( gain ))/2 );
		me->add("jingli",-cost);
		return 1;
	}
	else if(arg == "down" )
	{
		message_vision( HIY"\n$N�����������ٸ���С�Ľ���������ȥ��\n"NOR, me);
		me->move("/d/zhongnan/xuanya2");
		message_vision( HIY"\n$N����������\n"NOR, me);
		return 1;
	}

  return notify_fail("�Ǹ�����û������\n");
}

