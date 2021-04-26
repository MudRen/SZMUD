// Code of ShenZhou
// shui.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ˮ�", ({ "shui dai","shui" }) );
	set("nickname","���½�");
	set("gender", "����");
	set("age", 45);
	set("str", 24);
	set("max_neili", 1000);
	set("neili", 2000);
	set("con", 27);
	set("dex", 31);
	set("long",
		"���Ǹ�����������ò���ŵ����ߡ�\n");
//	set("title","�仨��ˮ����");
	set("combat_exp", 600000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("jiali", 80);
	set("chat_chance", 3);
	set("chat_msg", ({

//	"ˮ᷺޺޵�˵����Ѫ�����������������֪����ʲ��ط����ҵ����ǰ�����ʬ��Σ�\n",
	"ˮᷳ����е����仨��ˮ�����⣬ˮ���������䣡\n",
        }) );


	set_skill("sword", 180);
	set_skill("cuff", 120);
	set_skill("wuxing-quan", 140);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("fumo-jian", 170);
	set_skill("ding-force", 120);
	set_skill("wuxingbu", 120);
	set_skill("dodge", 120);

	map_skill("sword", "fumo-jian");
	map_skill("parry", "fumo-jian");
	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff", "wuxing-quan");

	prepare_skill("cuff", "wuxing-quan");

	setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void die()
{
        object corpse, killer, ob;
        int i;

        if( !living(this_object()) ) revive(1);
        this_object()->clear_condition();
        if( objectp(killer = query_temp("last_damage_from"))) {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
	if (killer->query_temp("jidao",1)>0)
                {
                killer->add_temp("jidao", -1);
                killer->improve_skill("blade",
		(int)(killer->query_skill("blade", 1)+1) * 10);
                killer->add("shen", -6000);
	tell_object(killer,HIR"��ֻ����ɲ�Ǽ�����һ��ɱ����ӿ��������Ѫ����Ϊһ�壡\n",NOR);
                }
        }
	::die();
}

