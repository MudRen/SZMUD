// /d/shaolin/shiting.c
// �����ɵ���֮��


#include <ansi.h>
inherit ROOM;

#include "/d/kunlun/obj/shijing.c"

void create() {
    set("short", "ªͤ");
	
	set("long", @LONG
����·��һ��СС��ªͤ��ƽ�չ��������Ъ�����á�ªͤ
�޽������Ѿã�ľ���ϵ������Ѱ��䣬�߰ߵ�㡣ͤ����һȪС
Ϫ��Ϫˮ�峺�����˹�֮������
LONG
	);
	
	set("exits", ([
                       "east" : "/d/shaolin/shiting",
	]));
   set("fjing",1);

	set("outdoors", "shaolin");
	set("cost", 2);
	set("resource/water", 1);
	setup();
}

void init() 
{
    add_action("do_play", "play");
    add_action("do_giveup", "giveup");
	add_action("do_fight", "fight");
}

int do_fight(string arg)
{
	object ob, me=this_player();
	if (!present("shaolin dizi", environment(me)))
		return 0;
	ob = me->query_temp("challenger");
	if ((arg == "dizi" || arg == "shaolin dizi") && ob && !me->is_fighting(ob))
	{
		message_vision(HIC"\n$N������ʾ���죬�����������ϣ�ȴ�������ֳ��С�\n"NOR, me);
		return 0;
	}
	return 0;
}

int do_play(string arg) 
{
    object ob, challenger, me = this_player(), *inv;
    int count, can_play, i;
	ob = this_object();

	if (me->is_busy())
        return notify_fail("��������æ���أ���\n");

	if (!arg || (arg != "qin" && arg != "yao qin" ))
		return notify_fail("��Ҫ��ʲô��\n");
	
	inv = all_inventory(me);
	can_play = 0;
	for(i=sizeof(inv)-1; i>=0; i--)
		if (inv[i]->query("id") == "yao qin")
			can_play = 1;
	if (!can_play)
		return notify_fail("���ϲ������ѵ�����ָ��\n");
	
	if (ob->query_temp("kunlun_played"))
		return notify_fail("�Ѿ������ڵ��������ˣ����ӳ���֮������������������ˡ�\n");

    
	if (present("shaolin dizi", environment(me)))
		return notify_fail("�����µĺ������鷳���ˣ�������\n");

	if (me->query("jingli") < 500)
    	return notify_fail("���Ѿ��۵ò����ˣ�ЪЪ�ɡ�\n");
	message_vision("\n$Nȡ������ң�٣����ְ������ң����ֵ�������������ԶԶ�����˳�ȥ����ɽ�лص���\n", me);
	message_vision(songs[random(sizeof(songs))], me);
	me->start_busy(2);
	
	me->add("jingli", -random(30));
    me->start_busy(1);
    if ( (wizardp(me) || me->query("family/family_name") == "������" && me->query_skill("qinqi-shuhua",1) >= 120)
         && time() > me->query( "mp_job_time" ) + 180 && !present("shaolin dizi", environment(me)))
		 
	{
	    me->set( "map_job_time", time() );
        message_vision(HIR "ͤ������ͻȻ����һλɮ�ˣ���$N��ʮΪ��\n" NOR, me);
        this_object()->set_temp("fighter", me);
		challenger = new(__DIR__"npc/kunlun_jobnpc");
        challenger->move(environment(me));
        me->set_temp("challenged", 1);
        me->set_temp("challenger", challenger);
		challenger->set_temp("opponent", me);
		
    }
	return 1;
}



int do_giveup() {
    object ob, me = this_player();

    if ( me->query_temp("challenged") 
		&& present(me->query_temp("challenger"), environment(me)) ) 
	{
			ob = me->query_temp("challenger");
            message_vision("\n$N���ֵ����������������˴���������ޣ���������뿪����\n", me);
            me->add("combat_exp", -random(20));
        
        me->delete_temp("challenger");
        me->delete_temp("challenged");
        message_vision("\n$N�뿪�ˡ�\n", ob);
        destruct (ob);
    }
    else
        return notify_fail("ʲô��\n");

    return 1;
}            
        
int valid_leave(object me, string dir)
{
    object ob;

    ob = me->query_temp("challenger");
	if ( me->query_temp("challenged") 
		&& objectp(ob) 
		&& me == ob->query_temp("opponent") )
	{
		message_vision("\n$N��ס$n��˵������" + RANK_D->query_respect(me) + "�������¸���������û���������ѵ����������ˣ���\n", ob, me);
		return notify_fail("�������߲����ˣ�����취�ɡ�\n");;
	}

    else 
	{ 
        me->delete_temp("challenged");
        me->delete_temp("challenger");
 	}
    return ::valid_leave(me, dir);
}
