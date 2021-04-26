// Code of ShenZhou
// rope.c
// xbc added hanging on 11/2/98

inherit ITEM;

void init();
int do_hang(string);

void create()
{
		set_name("����", ({"sheng zi", "sheng", "rope" }));
		set_weight(200);
		if( clonep() )
				set_default_object(__FILE__);
		else {
		set("value", 30);
				set("unit", "��");
				set("long", "һ���м�ʮ�ɳ���������\n");
				set("material", "cloth");
		}
	setup();
}

void init()
{
	add_action("do_hang", "hang");
	add_action("do_hang", "shangdiao");
}

int do_hang(string arg)
{
	object sheng = this_object(), me = this_player();

	if ( !arg || arg == "") return 0;

	if ( arg == "����" || arg == "rope" || arg == "sheng zi" || arg == "sheng") {
		tell_object(me, "���ó�һ����������������֦�ϣ�����һ���ᣬ�Ѳ���������ȥ��\n");
		message("vision", me->name()+"�ó�һ����������������֦�ϣ�����һ���ᣬ�Ѳ���������ȥ��\n", 
			environment(me), ({me}));

   		if ( random((int)me->query("food")) > 200 ) {
			tell_object(me, "���ӡ�ž������һ�����ˣ������ص�ˤ�����ϡ�\n");
			message("vision", "���ӡ�ž������һ�����ˣ�"+me->name()+"���ص�ˤ�����ϡ�\n", 
				environment(me), ({me}));
			me->receive_damage("jing", (int)me->query("food"), "�ϵ�δ�죬ˤ����");
			me->receive_damage("qi", (int)me->query("food"), "�ϵ�δ�죬ˤ����");
		}
		else if ( random((int)me->query("food")) > 100 ) {
			tell_object(me, "����ҡҡ�λΣ����ŵ����˹�ȥ��\n");
			message("vision", "����ҡҡ�λΣ�"+me->name()+"�ŵ����˹�ȥ����\n", 
				environment(me), ({me}));
			me->unconcious();
		}
		else {
			me->set_temp("last_damage_from", "�ϵ��Ծ���");
			me->die();
		}
	}
	return 1;
}

