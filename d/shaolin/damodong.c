// Code of ShenZhou
// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��Ħ��");
	set("long", @LONG
�����Ǵ�Ħ�Ŷ��������ǰ������ɮ�������Ħ���������£���
�˷�ˮ���أ���ס�������޵��ӣ��������ڣ����������·������ǧ
�겻��֮������Ħ��ʦ���ڴ���������һ��ʮ�꣬�ڼ��������Կ�
���������ʱ�Ĵ�����̬�������ϵļ�����Ƭ�⣬���п���һ�
LONG
	);

	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));

	set("bamboo_count", 1);
	set("cost", 0);
	setup();
}

void init()
{
	object me, ob;

	me = this_player();

	if( !userp(me) ) return;

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
		me->improve_skill("dodge", me->query_dex()*2);

	add_action("do_mianbi","���");	
	add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	object ob, *obs, me = this_player();

	message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ڵ�����˼�����ã���������\n", me);
	
	me->start_busy(5);
	me->set("jing",1);
	if (me->query("shen") < 0)
	me->add("shen", 1);
	if (me->query("shen") > 0)
	me->add("shen", -1);
	
	obs = filter_array(children(__DIR__"obj/book-bamboo.c"), (: clonep :));
        if ( query("bamboo_count") > 0 && sizeof(obs) < 3){
	ob = new("/d/shaolin/obj/book-bamboo");
        ob->move("/d/shaolin/damodong");
	add("bamboo_count", -1);
	CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ�����׽�Ṧƪ��", me->query("name")));
	}
	return 1;
}

