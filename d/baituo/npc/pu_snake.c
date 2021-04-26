// Code of ShenZhou
// pu_snake.c ��˹����
// by maco

#include <ansi.h>

inherit NPC;

void create()
{
	int poison = 8;
	set_name("��˹����", ({ "pusiqu she", "snake", "she", "pusiqu" }) );
	set_color("$HIY$");
	set("race", "����");
	set("age", 100);
	set("long", "�������Ͻ��������ͷ��������ǣ���״ʮ�ֹ��졣\n�������м��أ���Ϊ��˹���ߣ���˵����������磬���Ѳ�׽��\n");
	set("attitude", "peaceful");

	set_weight(poison*600 + 9000);
	set("str", 20 + poison );
	set("con", 30 + poison );
	set("int", 20);
	set("dex", 30 + poison );

	set("max_jing", 4000);
	set("max_qi", 4000);
	set("max_jingli", 4000);

	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��", "���" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 1000000);

	set_temp("apply/attack", 150);
	set_temp("apply/damage", 150);
	set_temp("apply/dodge", 200);
	set_temp("apply/armor", 150);

	set("snake_poison", 60 + poison*40 +random(61));
	set("bt_snake", 1);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && !is_fighting()
	     && random(ob->query_kar()) < 25) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}
}

void unconcious()
{	
	if(random(4) == 0 ) {
		message_vision("��˹�����������У���һ���㼱�ܶ��ӣ����֮������Ӱ���١�\n", this_object());
		destruct(this_object());
	}
	else {
		this_object()->disable_player(" <���Բ���>");
		this_object()->set("jing", 0);
		this_object()->set("qi", 0);
		COMBAT_D->announce(this_object(), "unconcious");
		call_out("revive", random(100 - query("con")) + 30);
	}
}

void die()
{
	object ob;
	message_vision("$Nȫ��Ť�������ڻ���һ��������ֱ������\n", this_object());
	ob = new(DRUG_D("mangshe-dan"));
	ob->set("name","��˹���ߵ�");
	ob->set("long", "һö����ɫ���ߵ��������ȳ���\n");
	ob->move(environment(this_object()));
	destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 10 + me->query("snake_poison")/5 +
		victim->query_condition("snake_poison") );
}
