// Code of ShenZhou
// new_snake.c 
// maco

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("С��", ({ "snake" }) );
	set("long", "�ɰ���ɽׯ��������������С�ߣ����׻���ʲ���ߣ�����code��֪����\n");
	set("race", "����");
	set("unit", "��");
	set("age", 1);
	set("attitude", "peaceful");

	set("auto_follow",0);
	set("wildness", 90);

	set("str", 20);
	set("cor", 20);
	set("dex", 20);

	set("combat_exp", 100000);

	set_temp("apply/attack", 40);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 60);

	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_skill("force", 10);

	setup();
}

void init()
{
	::init();
	add_action("convert","bian");
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if(me->query("name") == "����" )
	victim->apply_condition("bt_poison", 10 + me->query("snake_poison")/5 +
		victim->query_condition("bt_poison"));

	else victim->apply_condition("snake_poison", 10 + me->query("snake_poison")/5 +
		victim->query_condition("snake_poison"));
}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="snake" && arg!="she") return 0;
	if (me->query("family/family_name") != "����ɽ") 
		return notify_fail("�㲻�ܻ���Ϊ�ȡ�\n");

	return notify_fail(this_object()->name()+"�������ã�����̫С�������ܻ�Ϊ���ȡ�\n");
}
