// Code of ShenZhou

inherit ITEM;
void create()
{
	set_name("��ԲԲ����", ({ "shoupa" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ԲԲ�ù��������������е���������������������(ca)�����������š�������ء����֡�\n");
		set("value", 10000);
		set("material", "paper");
		set("skill", ([
			"name":	"beauty",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	150	// the maximum level you can learn
		]) );
	}
}

void init()
{
        add_action("do_ca","ca");
}

int do_ca(string arg)
{
	object who;
	object me = this_player();

	if (!arg) {
		message_vision("$N��" + query("name")+"���Լ���������\n", me);
		return 1;
	}
	if (!(who = present(arg, environment(me))) ||
		! who->is_character()) {
		write("����û������ˡ�\n");
		return 1;
	}

	if (who == me) {
                message_vision("$N��" + query("name")+"���Լ���������\n", me);
                return 1;
        }
	message_vision("$N��" + query("name")+"��$n��������\n", me,who);
	tell_object(who,"���ŵ�һ�ɵ�����������Ī���ж�����\n");
	return 1;
}
