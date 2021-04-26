// Code of ShenZhou
// xunbu.c Ѳ��
// Fang 8/21/96
// modified Zhuang@XKX 960903
// fixed move in init(), xuy 08/11/97
// Don't move or destruct this_object or this_player in init()
// If necessary, use call_out to do it.
//
// This NPC is confined in the city now.
//
// if we call ::init() in init(), they'll start autofight because of hatred
// even after a player's death, which is not good.
//

#include <ansi.h>
inherit NPC;

private string *home_locations = ({
	"/d/city/dongdajie1",
	"/d/city/xidajie1",
	"/d/city/nandajie1",
	"/d/city/beidajie1",
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
	set_skill("luan-blade", 35 + random(10));
	set_skill("force", 35 + random(10));
	map_skill("blade", "luan-blade");
	map_skill("parry", "luan-blade");

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
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
}

private void go_home()
{
	if( !living(this_object()) ) return;
	message_vision("$N�첽���˹�����\n$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
	this_object()->move(home_locations[random(sizeof(home_locations))]);
	message_vision("$N�첽���˹�����\n", this_object());
}

void init()
{
	if( strsrch(file_name(environment()), "/d/city/") == -1 ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
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
        return 1;
}

