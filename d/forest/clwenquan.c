//Cracked by Yujie
///d/forest/shilu.c
// by yujie 10 / 2001

inherit ROOM;

#include <ansi.h>


void create()
{
        set("short", HIG"��Ȫ��"NOR);
        set("long", @LONG
����һ��¶�����Ȫ�������곤�ְ�������ǿ��������
��Ȼ��Ȫ���ž������ܶ�������һ���ġ�����������ڽ���
�����������ֻ���������ϵ��˲������������ʵ���Ȫԡ��
LONG );
        set("exits", ([
		"south": __DIR__"shilu",
	]));
	
        set("outdoors","forest");
        
        set("cost",0);
        
        setup();
 
}

void init()
{
	add_action("do_bath","bath");
}

int do_bath()
{
	object me = this_player();
		
	if (!stringp(me->query_temp("bangs/pos")) )
	{	
		write("�㲻�ǳ��ְ����������������������Ȫԡ��\n");
		return 1;
	}
	
	if (me->query_temp("is_swim") == 1)
		return notify_fail("��������Ȫ�������أ�\n");
		
	
	if (me->is_busy())
		 return notify_fail("��������æ���ء�\n");
		 
	
	if ( intp (me->query("bangs/bathtime")) )
		if (uptime() < me->query("bangs/bathtime") + 1800 )
			return notify_fail("���ϴ�����ã��ݶ��˿ɲ�̫�á�\n");
			
	message_vision(HIG"$NѰ�˴����ʵĵط�����ȥ����������Ȫ֮�С�\n"NOR,me);
	me->set_temp("is_swim",1);
	me->start_busy(3);
	call_out("bathtwo",3,me);
	return 1;
}

void bathtwo(object me)
{
	write(HIG"�������Ȫ֮�У�ȫ����ɣ���Ȫˮ��͸�������ÿ�缡����ë����\n"NOR);
	me->start_busy(3);
	call_out("baththree",3,me);
}

void baththree(object me)
{
	write(HIG"��������Ȫˮ�����󣬸о��Լ�ȫ��ľ�������Ѹ�ٵĻָ��С�\n"NOR);
	me->start_busy(3);
	call_out("bathfour",3,me);
}

void bathfour(object me)
{
	if (!random(4))
	{
		write(HIW"����һ�˹��������Լ���������ȫ����������Ϊ�ƺ������н�����\n"NOR);
                me->add("max_jingli",1);
	}
	me->start_busy(3);
	call_out("bathfive",3,me);
}

void bathfive(object me)
{
	write(HIG"���˴���ʱ��������������������������·����˰���\n"NOR);
	// �ָ���
        me->set("qi", me->query("max_qi"));
        me->set("eff_qi", me->query("max_qi"));

        // �ָ���
        me->set("jing", me->query("max_jing"));
        me->set("eff_jing", me->query("max_jing"));

        // �ָ�����
        me->set("neili", me->query("max_neili"));

        // �ָ�����
        me->set("jingli", me->query("max_jingli"));

	me->delete_temp("is_swim");
	me->set("bangs/bathtime",uptime() );
}

	

		


