// Code of ShenZhou
:// room: /d/baituo/barn
// Jay 10/8/96

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ���ɽׯ�����ᣬ���ﵽ�����Ƕ��ߣ�ǽ����һ�š��߾���
(shejing)���������һ�Ѳ����õ���¨(zhulou)��
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"road1",
                    "west" : __DIR__"barn2a",
	]));
	         create_door("west", "ľ��", "east");
	set("item_desc", ([
		"shejing" : 
		"����ɽѵ���ܷ�����Ԧ�����ﵽ��ʮ�����ϣ��ɳ��Խ����߱�(bian)�����ȣ�\n"
		"�������ǰ���ɽׯ�Ķ��ű�����Ҳ���԰����ȱ�ض��ߣ���ʹ���ˡ�\n",
		"zhulou" : "һ�Ѳ����õ���¨������ɽׯ������Ҫ����ʱ��������������(take)��\n",
	]));
	set("objects", ([ 
                "/d/baituo/npc/snake" : 2,
	 ]) );
//	replace_program(ROOM);
	set("cost", 0);
	setup();
}


void init()
{
	add_action("do_lingwu","lingwu");
	add_action("do_take","take");
//	add_action("do_consult","consult");
//	add_action("do_chayue","chayue");
}

int do_lingwu(string arg)
{
	object me = this_player();
	int level, check;

	level = (int)me->query_skill("poison",1);
	check = level*level*level;

	if (!arg || arg!="shejing") 
		return notify_fail("��Ҫ����ʲô��\n");
	
	if (!me->query("family") || me->query("family/family_name") != "����ɽ")
		return notify_fail("����δ����գ���������߾���\n");

	if ( level < 30) 
		return notify_fail("�������Զ�����ڸ�����޷�����\n");

	if ( level > 100) 
		return notify_fail("�������Զ���̫ǳ��û���κΰ�����\n");

	if ( check > (int)me->query("combat_exp")*10 )
		return notify_fail("��ʵս���鲻�㣬�޷�����\n");

	if ( (int)me->query("jing") < 30 )
		return notify_fail("�㾫���޷����С�\n");

	me->receive_damage("jing", 20);
	me->improve_skill("poison", me->query("int"));
	write("�������߾���������ʩ���ķ��š�\n");
	return 1;
}

int do_take(string arg)
{
	object me = this_player(), obj, fire;

	if( me->query("family/family_name") != "����ɽ" ) return 0;

	if (!arg && arg != "zhulou" && arg != "basket" ) 
		return notify_fail("��Ҫ��ʲ�᣿\n");

	if ( this_object()->query("take/"+me->query("id") ) >= 3 )
		return notify_fail("���Ѿ����˲�����¨����ʱ�����˰ɣ�\n");

	obj = new("/d/baituo/obj/zhulou");
	obj->move(me);
	obj->set("keeper", me->query("id"));
	obj->set("long", 
	"һ��������ɵ�¨�ӣ��ǰ���ɽׯ����ר��������(catch)�ߵġ�\n"
	"¨���������һ��СֽƬ������д�šu"+me->name()+"�v��\n"
	);
	message_vision("$N����������ҳ���һ����¨��\n", me );

	add("take/"+me->query("id"), 1);
	fire = new("/d/xingxiu/npc/obj/fire");
	fire->move(obj);

	return 1;
}
