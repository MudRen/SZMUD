// Code of ShenZhou
#include <ansi.h>

inherit NPC;

void create()

{
      //  string *order = ({"���ڸ���", "��������", "�ط�Ѳ��"});

        set_name("����",({ "guard", "huwei"}) );
        set("long", "����һλ������ר�ŵ��λ���֮��\n");
        set("attitude", "friendly");

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("max_neili", 1000);
	set("str", 30);
        set("con", 30);
        set("dex", 25);
        if( this_player() ) 
	{
        set("combat_exp", this_player()->query("combat_exp",1));
	set("jiali",this_player()->query("jiali",1)*2);
	set("qi",(int)this_player()->query("qi",1)/2);
set_skill("duanjia-jian",this_player()->query_skill("duanjia-jian",1));
set_skill("duanshi-shenfa",this_player()->query_skill("duanshi-shenfa",1));	
	}	
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 40);

        set_skill("sword", 90);
        set_skill("parry", 70);
        set_skill("dodge", 50);

map_skill("dodge", "duanshi-shenfa");
map_skill("sword", "duanjia-jian");
map_skill("parry", "duanjia-jian");

        setup();

        carry_object("/clone/armor/tiejia")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

int heal_up()
{

	        if( environment() && !is_fighting() ) 
		{
                call_out("leave", 300);
                return 1;
        }
        return ::heal_up() + 1;
}
void leave()
{
        message("vision",
                HIB + name() +
"˵�������¹������������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
                + name() + "ת��Զȥ��\n" NOR,
environment(),
                this_object() );
        destruct(this_object());
}

void invocation(object who)
{

        int i;
        object *enemy;

        message("vision",
                HIW
"����̩�����߳�һ�ˣ�����˵���������½�����λ"+RANK_D->query_respect(who)+"��ǰ���ķ��š�\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
}
int accept_fight(object me)
{
        command("say С��ֻ�Ǹ����ˣ������������ǣ�С��ֻ�ø����ˡ�\n");
	      me->apply_condition("dlkiller", 100);
	        destruct(this_object());
}
	
int accept_kill(object me)
{
        command("say С��ֻ�Ǹ����ˣ������������ǣ�С��ֻ�ø����ˡ�\n");
              me->apply_condition("dlkiller", 100);
                destruct(this_object());
}       

