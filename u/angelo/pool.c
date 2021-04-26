// Code of ShenZhou
// pool.c
// xQin 3/00
inherit ROOM;
#include <ansi.h>

int do_halt(object);
void out_of_pool(object, int);

void create()
{
	set("short", HIC"����"NOR);
	set("long", "����һ��ʯ��������С�أ���˵���ͳ������ˣ������ڴ˳���ԡ���󣬶�\n"
"��������𶥣���Ϊ��ϴ��ء���\n\n"
"����"HBBLU+HIC"��ˮ�峺͸��\n"NOR
	);

	set("xixiang", 1);
	set("resource/water", 1);
        setup();
}

void init()
{
	int i;
	object room, me = this_player();
	object *inv = all_inventory(environment(me));

	if( !(room = find_object(__DIR__"xixiang")) )
		room = load_object(__DIR__"xixiang");

	if( interactive(me) )
	{ 
		tell_room(environment(me), "���ˡ���ͨ��һ�����˽�����\n", ({ me }));
		tell_object(me, "�㡰��ͨ��һ�������˳�ˮ��\n");
		tell_room(room, "ֻ������ͨ��һ����"+me->name()+"�Ѿ������˳�ˮ�\n");
		me->start_call_out( (: call_other, __FILE__, "do_swim", me :), 1);

		for( i=0 ; i < sizeof(inv); i++)
			if( inv[i] != me && inv[i]->query_temp("xixiang_swimming") )
			{
				me->start_call_out( (: call_other, __FILE__, "disturb", inv[i], this_player() :), 0);
				break;
			}
	}

	add_action("do_halt", "halt");
}

int do_ban()
{
	write("��ˮ�������£��㲻�±���������\n");
	return 1;
}

void disturb(object bather, object freeloader)
{
	int i, check=0;
	object *ob;
	if( environment(freeloader) != environment(bather)
	 || !(environment(bather))->query("xixiang") ) return;

	ob = all_inventory(environment(freeloader));
	for( i=0; i < sizeof(ob); i++ )
		if ( ob[i]->is_character() && ob[i] != freeloader ) check++;

	if( check > 1 )
	{
		tell_object(freeloader, "��ͻȻ���ֳ�ˮ�����ˣ����һ���ֹһ����\n");
		do_halt(freeloader);
		return;
	}

	if( bather->is_spouse_of(freeloader) )
	{
		tell_object(bather, HIB"����ϸһ����ԭ�������"+ bather->query("spouse/title")
				+ "���龪һ����\n"NOR);
		message("vision",CYN + freeloader->name() + "��������ĵ�һЦ��\n"NOR, bather);
		message("vision",CYN"�����" + bather->name() + "���ĵ�һЦ��\n"NOR, freeloader);
		return;
	}

	tell_object(freeloader, "�㷢�ֳ���Ҳ��������ˮ��");
	if( (string)freeloader->query("race") != "����" )
	{
		tell_object(bather, HIB"����ϸһ����ԭ����" + freeloader->query("unit")
			+ freeloader->name() + "���龪һ����\n"NOR);
		return;
	}
	if( (string)bather->query("race") != "����" )
	{
		tell_object(freeloader, HIB"��ϸһ����ԭ����" + bather->query("unit")
			+ bather->name() + "���龪һ����\n"NOR);
		return;
	}
	if( freeloader->query("gender") == "����" )
	{
		if( bather->query("gender") != "Ů��" )
		{
			tell_object(freeloader, "��ϸһ�����Է�ȴ����Ů�ӡ�\n");
			message("vision",CYN + bather->name() + "������ü���ƺ������˵Щʲô��\n"NOR, freeloader);
			message("vision",CYN + freeloader->name() + "������ü���ƺ������˵Щʲô��\n"NOR, bather);
			return;
		}
		else
		{
			if( !living(bather) ) return;
			tell_object(bather, RED"����ϸһ����������е��˾��������ӣ����������㲻������ؿ����ţ�\n"NOR);
			tell_object(bather, HIR"��ֻѪ���ϳ壬��ʱ�е�һ�����Σ�\n"NOR);             
			tell_object(freeloader, RED"\n��ϸһ�����������ԡ������Ů�ӣ�������Ҫ�����ŵ����˹�ȥ��\n"NOR);
			bather->set("jing", 0);
			bather->set_temp("been_looked", 1);
			bather->start_busy(1);
			if( random(bather->query_per()/6) ) 
			{
				bather->unconcious();
				bather->set_temp("apply/short", ({ bather->query("title")+ " "
				+ bather->query("name")+ "("+capitalize(bather->query("id"))+")"+HIW" <ȫ��>"NOR }) );
			}
			return;
		}
	}
	if( freeloader->query("gender") == "Ů��" )
	{
		if( bather->query("gender") == "Ů��" )
		{
			tell_object(bather, "����ϸһ����ԭ���Է�Ҳ�Ǹ�Ů�ӡ�\n");
			tell_object(freeloader, "��ϸһ����ԭ���Է�Ҳ�Ǹ�Ů�ӡ�\n");
			message("vision", CYN + freeloader->name() + "����������һЦ��\n"NOR, bather);
			return;
		}
		else
		{
			tell_object(freeloader, "��ϸһ����ԭ���Է�����λ��������\n");
			if( bather->query("gender") == "����" )
				tell_object(bather, HIY"����ϸһ�����������ľ���Ů�ӣ���\n"NOR);
			else 	tell_object(bather, "����ϸһ����������������Ů�ӡ�\n"NOR);
			do_halt(freeloader);
			return;
		}
	}
	else
	{
		tell_object(bather, RED"��ͻȻ�������������������޲����Ҹ��ط����ȥ��\n"NOR);
		do_halt(bather);
		bather->set("jing", 0);
		bather->start_busy(1);
		return;
	}	
}

int do_swim(object me)
{
	mixed local;
	int t, time;

	if( !living(me) )
	{
		out_of_pool(me, 0);
		return;
	}
	if( !(environment(me))->query("xixiang") ) return;

	if( me->query_con() < 25 )
	{
		tell_object(me, HIB"���ϳ�ˮ����̹ǣ����͵�һ������æ�������⣡\n"NOR);
		tell_room(environment(me), me->name()+"����ȫ����£�����ææ����������ȥ��\n", ({ me }));
		me->move(__DIR__"xixiang");
		tell_room(environment(me), me->name()+"����ææ�ش�ϴ���������������ȫ���ף�ֱ����£�\n", ({ me }));
		me->start_busy(2);
		me->receive_damage("jingli", 100);
		me->receive_damage("qi", 100);
		me->receive_damage("jing", 100);
		return 1;
	}

	local = localtime(time()*60);
	t = local[2]*60 + local[1];

time=(1000/me->query_skill("swimming")+random(1000/me->query_skill("swimming")))/2;
	if( time > 30 ) time = 30;
	if ( t > 1200 || t < 300 )
	{
		write(HIB"��ʱҹ���˾����㾡����ڳ���Ϸˮ����������ĳ�ˮ���һ���ƣ�͡�\n"NOR);	
		call_out("out_of_pool", time, me, 1);
	}
	else
	{
		write(HIB"��ˮ�������㾡����ڳ���Ϸˮ������ʱʱ�����Ƿ�����·�����ӡ�\n"NOR);
		call_out("out_of_pool", time, me, 0);
	}

	me->set_temp("xixiang_swimming", 1);
	me->set_temp("apply/short", ({ me->query("title")+ " " +me->query("name")+"("+capitalize(me->query("id"))+")"+HIC" <��ˮ��>"NOR}));

        me->start_busy(6);      
        return 1;         
}

void out_of_pool(object me, int recover)
{
	if( !me->query_temp("xixiang_swimming") ) return;
	if( !(environment(me))->query("xixiang") ) return;

	me->delete_temp("xixiang_swimming");
	me->delete_temp("been_looked");
	me->delete_temp("apply/short");

	if( !living(me) )
	{
		message_vision("һ����紵���������Ե�$N�Ƶ��رߡ�\n", me);
		me->move(__DIR__"xixiang");
		message_vision("һ��������紵���������Ե�$N�Ƶ��˳رߡ�\n", me);
		return;
	}
	if( recover )
	{
		tell_object(me, GRN"����һС��������������⣬ֻ��ƣ�;�ȥ�������ӡ�\n"NOR);
		message("vision", "ֻ��"+me->name()+"������������ϳرߣ������·���\n",
			environment(me), ({ me }) );
		me->move(__DIR__"xixiang");
		message("vision", "ֻ��"+me->name()+"��������ش�ϴ���������������\n",
			environment(me), ({ me }) );
		if( me->query("gender") == "Ů��" )
		{
			me->add("jing", (me->query("eff_jing") - me->query("jing"))/2);
			me->add("qi", (me->query("eff_qi") - me->query("qi"))/2);
			me->add("jingli", (me->query("max_jingli") - me->query("jingli"))/2);
			me->add("neili", (me->query("max_neili") - me->query("neili"))/2);
			me->improve_skill("beauty", 15*me->query_per());
			me->improve_skill("force", random(me->query_con()*5));
		}
		else
		{
			me->add("jing", ((int)me->query("eff_jing")-(int)me->query("jing"))/(3+random(5)));
			me->add("qi", ((int)me->query("eff_qi")-(int)me->query("qi"))/(3+random(5)));
			me->add("jingli", ((int)me->query("max_jingli")-(int)me->query("jingli"))/(3+random(5)));
			me->add("neili", ((int)me->query("max_neili")-(int)me->query("neili"))/(3+random(5)));
		}
	}
	else
	{
		tell_object(me, GRN"����һС�����������ڳ��������ˣ����س��⡣\n"NOR);
		message("vision", "ֻ��"+me->name()+"����ϴ��أ������·���\n",
			environment(me), ({ me }) );
		me->move(__DIR__"xixiang");
		message("vision", "ֻ��"+me->name()+"��ϴ���������������\n",
			environment(me), ({ me }) );
		me->improve_skill("force", random(me->query_con()/5));
		if( me->query("gender") == "Ů��" )
			me->improve_skill("beauty", 5*me->query_per());
	}
	if( me->query_skill("swimming") < 125 ) me->improve_skill("swimming", random(me->query("dex"))*random(me->query_skill("swimming")/4)+1 );
	me->start_busy(1);      
}

int do_halt(object me)
{
	if( !me ) me = this_player();
//	if( me->is_busy() ) return notify_fail("�㻹��æ�ء�\n");

	me->delete_temp("xixiang_swimming");
	me->delete_temp("apply/short");

	if( me->query_temp("been_looked") )
	{
		me->delete_temp("been_looked");
		tell_object(me, "����æ�����·�������ϴ��ء�\n");
		message("vision", me->name()+"�Ҵ�ææ����������ϳرߡ�\n",
			environment(me), ({ me }) );
		me->move(__DIR__"xixiang");
		message("vision", me->name()+"һ�������ܻ��ش�ϴ���������������\n",
			environment(me), ({ me }) );
		return 1;
	}

	tell_object(me, "����æ���ϳرߴ����·���\n");
	message("vision", me->name()+"��æ���ϳرߴ����·���\n",
			environment(me), ({ me }) );
	me->move(__DIR__"xixiang");
	message("vision", me->name()+"����ææ�ش�ϴ���������������\n",
			environment(me), ({ me }) );
	return 1;         
}
