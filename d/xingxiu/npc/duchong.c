// Code of ShenZhou
// wsky, 22/7/00.
#include <ansi.h>

inherit NPC;

void create()
{
        switch( random(6) ){
        	case 0:
        	set_name(RED"���޶���"NOR, ({ "du zhu", "spider", "zhu" }) );
        	set("long", "һֻ����Ĵָ��С����ɫ�ʰ���ɫ��֩�룬�ƺ��庬�綾��\n");
        	break;
        	case 1:
        	set_name(HIG"����Ы"NOR, ({ "scorpion", "xie", "xie zi" }) );
        	set("long", "������ڣ���ɱ��̣����޺����С�\n");
        	break;
        	case 2:
        	set_name(HIR"�쾦��"NOR, ({ "zhu wa", "wa", "frog" }) );
        	set("long", "һֻ���ÿɰ���С�ܣ����۳����ɫ��\n");
        	break;
        	case 3:
        	set_name(HIC"����"NOR, ({ "e", "du e"}) );
        	set("long", "һֻ�庬�綾�Ķ��ӡ�\n");
        	break;
        	case 4:
        	set_name(HIR"���ļ׳�"NOR, ({ "beetle", "jia chong", "chong" }) );
        	set("long", "һֻ�庬�綾��Ӳ�Ǽ׳档\n");
        	break;
        	case 5:
        	set_name(YEL"Ұ��"NOR, ({ "bee", "ye feng", "feng" }) );
        	set("long", "һֻҰɽ�䣬����һ�¿��ǲ����ܵġ�\n");
        	break;
        	case 6:
        	set_name(HIB"����֩��"NOR, ({ "bee", "ye feng", "feng" }) );
        	break;
        }
        
        set("sub", "xx_job");
        set("race", "����");
        set("subrace", "����");
        set("age", 3);
        //set("limbs", ({ "ͷ��", "����", "����", "ǰ��" }) );

        set("combat_exp", 100);
        //set_color("$HIY$");
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 6);
        set_temp("apply/armor", 1);

        setup();
}

void init()
{
        object ob=this_object();
        object me=this_player();
        
        ::init();
        
        set("combat_exp", me->query("combat_exp"));
       
        call_out("kill_ob", 1, me);
        call_out("dest_bug",20,ob);
        
}

void die(object ob)
{
        object killer = query_temp("last_damage_from");
        if(!objectp(killer)) {
                ::die();
                return;
        }
        killer->delete_temp("bug_out");
	::die();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("insect_poison", 50 +
                victim->query_condition("insect_poison"));
}

void dest_bug(object ob){
        if(!this_player()) {
                destruct(ob);
                return;
        }
	message_vision (HIC+ob->query("name")+"ͻȻ�굽һƬ��Ҷ���棬��Ӱȫ�ޡ�\n"NOR, this_player());
        this_player()->delete_temp("bug_out");
	destruct(ob);
	
}

