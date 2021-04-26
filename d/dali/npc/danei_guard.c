// Code of ShenZhou
#include <ansi.h>

inherit NPC;

void create()

{
      //  string *order = ({"大内高手", "锦衣侍卫", "地方巡捕"});

        set_name("侍卫",({ "guard", "huwei"}) );
        set("long", "这是一位侍卫，专门担任护驾之责。\n");
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
"说道：在下公务在身，现在已经完成护驾任务，就此告辞！\n\n"
                + name() + "转身远去。\n" NOR,
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
"高升泰背后走出一人，低声说道：“在下将随这位"+RANK_D->query_respect(who)+"鞍前马后的服伺。\n" NOR,
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
        command("say 小的只是个下人，不敢惹事生非，小的只好告退了。\n");
	      me->apply_condition("dlkiller", 100);
	        destruct(this_object());
}
	
int accept_kill(object me)
{
        command("say 小的只是个下人，不敢惹事生非，小的只好告退了。\n");
              me->apply_condition("dlkiller", 100);
                destruct(this_object());
}       

