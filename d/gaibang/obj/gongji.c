// Code of ShenZhou
// gongji.c ����

inherit ITEM;
inherit F_FOOD;

void init();
int do_cut(string);
int do_wash(string);
int do_wrap(string);
int do_bake(string);
int do_clean(string);

void create()
{
	set_name("����", ({"gong ji", "ji", "chicken"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ʴ�Ĺ�����\n");
		set("unit", "ֻ");
		set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 40);
	}

	setup();
}

void init()
{
	add_action("do_cut", "cut");
	add_action("do_cut", "po");
	add_action("do_wash", "wash");
	add_action("do_wash", "xi");
	add_action("do_wrap", "wrap");
	add_action("do_wrap", "guo");
	add_action("do_bake", "bake");
	add_action("do_bake", "kao");
	add_action("do_clean", "clean");
	add_action("do_clean", "bo");
}

// step1 �ʹ���
int do_cut(string arg)
{
	object ji = this_object(), me = this_player();
	object weapon = me->query_temp("weapon");

	if ( !arg || arg == "") return 0;

	if ( arg == "����" || arg == "chicken" ) {

		if ( objectp(weapon) 
		&& ((string)weapon->query("skill_type") != "sword" 
                || (string)weapon->query("skill_type") != "blade" )) {
			message_vision( "$N��" + weapon->query("name") + "�ʿ�" + ji->query("name") + "���ӡ�\n", me);
			ji->set("step", 1);
			ji->set("long", "һֻ�ʿ����ӵĴ󹫼���\n");
			return 1;
		}

		else {
			message_vision( "$N���ֳ���һֻ�󹫼���\n", me);
			ji->set("fake", 1);
			return 1;
		} 
	}
	tell_object( me, "��Ҫ��ʲô��\n");
	return 1;
}

// step2 ϴ����

int do_wash(string arg)
{
	object ji = this_object(), me = this_player();

	if ( !arg || arg == "") return 0;

	if ( arg == "����" || arg == "chicken" || arg == "����" || arg == "intestine" ) {
		message_vision( "$N��" + ji->query("name") + "����ϴ���ɾ���\n", me);
		ji->set("long", "һֻ�����ʿ�������ϴ�ɾ��Ĵ󹫼���\n");

		if ( ji->query("step") != 1) 
			ji->set("fake", 1);
		else ji->set("step", 2);
		return 1;
	}
	tell_object( me, "��Ҫϴʲô��\n");
	return 1;
}

// step3 ��ˮ��
int do_wrap(string arg)
{
	object ji = this_object(), me = this_player(), ni = present("shi ni", me);

	if ( !arg || arg == "") return 0;

	if ( arg == "����" || arg == "chicken" || arg == "��" || arg == "mud" ) {
		ji->set("mud", 1);

		if (!objectp(ni)) {
			message_vision( "$N��ˮ����һ�������" + ji->query("name") + "�⡣\n", me);
			ji->set("fake", 1);
		}
		else {
			message_vision( "$Nȡ�����ϵ�ʪ�࣬����" + ji->query("name") + "�⡣\n", me);
			destruct(ni);
		}
			
		ji->set("long", "һֻ����ʪ����Ĺ�����\n");

		if ( ji->query("step") != 2) 
			ji->set("fake", 1);
		else 
			ji->set("step", 3);
		return 1;
	}

	tell_object( me, "��Ҫ��ʲô��\n");
	return 1;
}

// step4 ����
int do_bake(string arg)
{
	object ji = this_object(), fire, me = this_player();
	fire = present("fire", me);

	if ( !arg || arg == "") return 0;

	if ( arg == "����" || arg == "chicken" ) {
		if ( !objectp(present("fire", me)) ) {
			tell_object( me, "������û�л��ۣ������˻�\n");
			return 1;
		} 
 
		else {
			fire = present("fire", me);
			message_vision( "$N������" + ji->query("name") + "����\n", me);
			if ( ji->query("step") != 3) 
                		ji->set("fake", 1);
        		else ji->set("step", 4);
			ji->set("cook_time", 0);
			remove_call_out("cooking");
			call_out("cooking", 1, me, ji, 0);
			return 1;
		}
	}
	tell_object( me, "��Ҫ��ʲô��\n");
	return 1;
}

// step5 ��
int cooking(object me, object ji, int cook_time)
{
	ji->set("cook_time", cook_time);
//	message_vision( cook_time + "\n", me);
	if ( cook_time == 25 ) {
		if ( !ji->query("mud")) {
			message_vision( "����һ���������͸������\n", me);
			ji->set("long", "һֻ��������Ĺ�����\n");
		}
		else {
			message_vision( "����һ���������͸������ʪ�ཥ����͸��\n", me);
			ji->set("long", "һֻ���Ÿ��࣬��������Ĺ�����\n");
		}
	}

	if ( cook_time == 50 ) {
		message_vision( "�ٿ���һ��������ƺ��ᵽʲ�ᶫ�������ˡ�\n", me);
		if ( !ji->query("mud")) 
			ji->set("long", "һֻ�����˵Ĺ�����\n");
		else
			ji->set("long", "һֻ���Ÿ��࣬�����˵Ĺ�����\n");
	}

	if ( cook_time < 50) {
		cook_time = cook_time + 1;
		remove_call_out("cooking");
        	call_out("cooking", 1, me, ji, cook_time);
	}

	return 1;
}

// step6 ������ 
int do_clean(string arg)
{
	object ji = this_object(), me = this_player();
        object ob = new(__DIR__"jiaohua-ji");

	if ( !arg || arg == "") return 0;

	if ( !ji->query("mud", 1) ) {
		if ( arg == "��ë" || arg == "hair" ) {
			message_vision( "$N��ȥ��ë��\n", me);
                	ob->move(me);
			ob->set("fake", 1);
			return 1;
		}
		tell_object(me, "��Ҫ��ʲô��\n");
		return 1;
	}
			
	if ( arg == "����" || arg == "mud" ) {
		message_vision( "$N��ȥ���࣬��ë������䡣\n", me);
                ob->move(me);

		if ( ji->query("step") != 4 )
			ob->set("fake", 1);
		else if ( ji->query("cook_time") < 36 ) {
			ob->set("undercook", 1);
			ob->set("fake", 1);
		}
		else if ( ji->query("cook_time") > 40 )  {
			ob->set("overcook", 1);
			ob->set("fake", 1);
		}
                destruct(ji);
		return 1;
	}
	tell_object( me, "��Ҫ��ʲô��\n");
	return 1;
}

