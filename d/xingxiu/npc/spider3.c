// Code of ShenZhou
// Ryu, 11/20/96.
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ѩ��", ({ "caixue zhu", "spider", "zhizhu" }) );
	set_color("$HIW$");
        set("race", "����");
        set("subrace", "����");
        set("age", 3);
        set("long", "һֻ�Ʊ��ڴ�С��֩�룬֩��ģ�����ǹ��죬ȫ�����ƺ�����䣬\n"+
		"���޵��˼���������һ��������Ķ��ǡ�\n"+
		"����֩��������ѩɽ֮����������������֮һ��");
        set("attitude", "peaceful");

//      set("limbs", ({ "ͷ��", "����", "����", "ǰ��" }) );

        set("combat_exp", 900);
	set("qianzhu-wandu/spider", 15);
  	set("qianzhu-wandu/poison", 100);   // speed up
        set("qianzhu-wandu/level", 130);   // min level that can use 
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 6);
        set_temp("apply/armor", 1);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
        }
}

void die()
{
        object ob;
        message_vision("\n$N��������£���³�һ��˿�����ˡ�\n", this_object());
        ob = new(__DIR__"zhusi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("insect_poison", 100 +
                victim->query_condition("insect_poison"));
}



