// Code of ShenZhou
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "lao xianshen", "xianshen" }));
	set_color("$YEL$");
	set("long","����һλ�ڴ�����ڽ������������\n");
	set("gender", "����");
	set("age", 65);
	set("max_jing", 2000);
	set("max_qi", 2000);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 30);
	set("combat_exp", 40000);
	set("shen_type", 1);
	setup();
}
void init()
{
	object ob;
	if (interactive(ob = this_player()) && !is_fighting() && this_player()->query_temp("dalibook") > 1)
	{
		call_out("greeting2", 1, ob);
	}
	if (interactive(ob = this_player()) && !is_fighting() &&
	!(this_player()->query_temp("dalibook")))
	{
		call_out("greeting1", 1, ob);
	}
	add_action("do_qingjiao","qingjiao");
	add_action("do_taojiao","taojiao");
}

void greeting1(object ob)
{
	message_vision(HIW"������ҡͷ���Ե�������\n\n"NOR, ob);
	ob->set("potential",ob->query("max_potential"));
	return ;
}

void greeting2(object ob)
{
	command("hi");
	return ;
}
int do_qingjiao(string arg)
{
	object me=this_object(), who=this_player();
	int b;

	if (!arg) return notify_fail("�������ʲô����\n");
	if (who->is_busy()) return notify_fail("��������æ���ء�\n");
	if (who->is_fighting()) return notify_fail("����ĥǹ������������\n");
	if (me->is_fighting() || me->is_busy()) return notify_fail("����æ���أ�û������㡣\n");
	if (!living(me)) return notify_fail("�� ... ����Ȱ���Ū����˵��\n");
	if ((int)who->query("potential") < 10) return notify_fail("���Ǳ�ܲ��㣬�޷�����κζ�����\n");
	if ((int)who->query("jing") <110 ) return notify_fail("��̫���ˣ��޷�����κζ�����\n");
	message_vision("$N��$n���ѧ���ϵ����⣬�ƺ���������\n", who, me);
	who->improve_skill(arg, 1);
	b = who->query_skill(arg, 1)+1;
	who->improve_skill(arg, b*b+1);
	return 1;
}
int do_taojiao(string arg)
{
	object me=this_object(), who=this_player();

	if (!arg) return notify_fail("�������ʲô����\n");
	message_vision("$N��$n���ѧ���ϵ����⣬�ƺ���������\n", who, me);
	who->set(arg, who->query(arg)+1);
	return 1;
}
