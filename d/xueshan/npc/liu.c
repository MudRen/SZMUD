// Code of ShenZhou
// liu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("���з�", ({ "liu chengfeng","liu" }) );
	set("nickname","���ƽ�");
	set("gender", "����");
	set("age", 45);
	set("con", 30);
	set("str", 24);
	set("dex", 25);
	set("long",

"����λ̫���ŵĸ��֣��米�����������Ľ������Ʈ������ƺ������ա�\n");
//	set("title","�仨��ˮ����");
	set("combat_exp", 550000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("jiali", 70);
	set("max_neili",1500);
	set("neili", 3000);
	set("chat_chance", 3);
	set("chat_msg", ({
//		"���з�޺޵�˵����Ѫ�����������������֪����ʲ��ط����ҵ����ǰ�����ʬ��Σ�\n",
	"���з糤���е����仨������ˮ�⣬������ˮ�仨��\n",
        }) );
	/*
	set("chat_combat_chance", 100);
	set("chat_combat_msg", ({
	(:perform_action, "chan":)
	}));
	*/

	set_skill("sword", 145);
	set_skill("cuff", 140);
	set_skill("parry", 140);
	set_skill("force", 120);
	set_skill("taiji-jian", 140);
	set_skill("taiji-shengong", 120);
	set_skill("taiji-quan", 60);
	set_skill("ding-dodge", 120);
	set_skill("dodge", 170);

	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "ding-dodge");
	map_skill("cuff", "taiji-quan");
	prepare_skill("cuff", "taiji-quan");
	setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}
//#include "/d/qilian/npc/auto_perform.h"
void die()
{
        object corpse, killer;
        int i;

        if( !living(this_object()) ) revive(1);
        this_object()->clear_condition();
        if( objectp(killer = query_temp("last_damage_from")) ) 
        {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
         if (killer->query_temp("jidao",1)>0)
                {
                killer->add_temp("jidao", -1);
                killer->improve_skill("blade",
(int)(killer->query_skill("blade", 1)+1) * 40);
                killer->add("shen", -30000);

tell_object(killer,HIR"��ֻ����ɲ�Ǽ�����һ��ɱ����ӿ��������Ѫ����Ϊһ�壡\n",NOR);

                }
        }
	::die();
}

