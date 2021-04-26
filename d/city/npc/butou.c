// Code of ShenZhou
// xunbu.c ��ͷ
// Fang 8/21/96
// Modified by Zhuang@XKX 960903 - disable hatred autofight
// modified by xuy, remove move(this_object()) in init

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ͷ", ({ "bu tou", "tou" }));
        set_color("$YEL$");
	set("age", 42);
	set("gender", "����");
	set("long", "����Զ�����������ݵ�һ��ͷ��һ�����������ɰ���\n");
	set("attitude", "heroism");
//	set("vendetta_mark", "authority");
        set("pursuer", 1);

	set("str", 30);
	set("dex", 25);
	set("combat_exp", 100000);
	set("shen_type", 0);
        set("max_neili", 700);
        set("neili", 700);
        set("jiali", 20);
	set_skill("unarmed", 55 + random(10));
	set_skill("dodge", 55 + random(10));
	set_skill("parry", 55 + random(10));
	set_skill("blade", 55 + random(10));
	set_skill("luan-blade", 55 + random(10));
	set_skill("force", 55 + random(10));

	map_skill("blade", "luan-blade");
	map_skill("parry", "luan-blade");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);
        set("chat_chance", 5);
        set("chat_msg", ({
                "��ͷ��: ������\n",
                (: random_move :)
        }) );

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"��ͷ�ȵ����󵨵��񣬻���������־��ܣ�\n",
	}));
	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N�첽���˹�����\n$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/city/guangchang");
        message_vision("$N�첽���˹�����\n", this_object());
}

void init()
{
        if( strsrch(file_name(environment()), "/d/city/") == -1 ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
		return;
        } else if( interactive(this_player())
	&& (int)this_player()->query_condition("killer")) {
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

