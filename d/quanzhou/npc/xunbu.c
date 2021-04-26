// Code of ShenZhou
// xunbu.c Ѳ��
// Fang 8/21/96
// modified Zhuang@XKX 960903
//
// This NPC is confined in the city now.
//
// if we call ::init() in init(), they'll start autofight because of hatred
// even after a player's death, which is not good.
//

#include <ansi.h>
inherit NPC;

private string *home_locations = ({
	"/d/quanzhou/gushao",
	"/d/quanzhou/xiqiao",
	"/d/quanzhou/alabo",
	"/d/quanzhou/citong_e2",
	"/d/quanzhou/jishi"
});

void create()
{
	set_name("Ѳ��", ({ "xun bu", "bu" }));
        set_color("$YEL$");
	set("age", 32);
	set("gender", "����");
	set("long", "����һ�������ϵ���Ѳ����һ˫�������۾�����ض����㡣\n");
	set("attitude", "heroism");
//	set("vendetta_mark", "authority");
	set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 0);

	set_skill("unarmed", 35 + random(10));
	set_skill("dodge", 35 + random(10));
	set_skill("parry", 35 + random(10));
	set_skill("blade", 35 + random(10));
	set_skill("force", 35 + random(10));
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
        set("chat_chance", 5);
        set("chat_msg", ({
                "Ѳ����: ������\n",
                (: random_move :)
        }) );

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"Ѳ���ȵ����󵨵��񣬾����췴���ɣ�\n",
		"Ѳ���ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
	}));
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/armor/junfu")->wear();
}

void init()
{
	if( strsrch(file_name(environment()), "/d/quanzhou/") == -1 ) {
		message_vision("$N�첽���˹�����\n$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
		this_object()->move(home_locations[random(sizeof(home_locations))]);
		message_vision("$N�첽���˹�����\n", this_object());
		return;
	} else if( interactive(this_player())
	&& (int)this_player()->query_condition("killer") ) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, this_player());
	} else if( is_killing(this_player()->query("id")) )
		remove_killer(this_player());
}

int accept_fight(object me)
{
        command("say С���й�����������������С�\n");
        return 0;
}

int accept_kill(object me)
{
        command("say ������̫��ͷ�϶�������ò��ͷ��ˣ������ʱ������ļ��գ�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

