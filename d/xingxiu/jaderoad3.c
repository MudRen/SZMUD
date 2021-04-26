// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;
string look_long();
string look_door();
string look_axe();
string look_lock();
string look_loop();
string look_skeleton();

void create()
{
	set("short", "����ͨ��");
	set("long", (: look_long :));

	set("exits", ([
		"south" : __DIR__"jaderoad2",
	]));
	set("item_desc", ([
	"door" : (: look_door :),
	"axe" : (: look_axe :),
	"lock" : (: look_lock :),
	"loop" : (: look_loop :),
	"skeleton" : (: look_skeleton :),
	]));

	set("cost", 1);
	set("loop_rust", 1);
	set("lock_rust", 1);

	set("door_axe", 1);
	set("door_lock", 1);
	setup();
}

string look_long()
{
	object armor = new("/d/xingxiu/obj/jinjia");
	string desc;
	desc = 
	"һ������������ǰ��ɽʯ��·����ͷ����һ��ʯ��(door)��\n";
	if (armor) {
	desc += HIY"ֻ����ͷ���������⣬����һ�ѻƽ�"NOR+"�߽���ʱ��ȴ��һ���ƽ���ף�\n��������һ�ѿݹ�(skeleton)��\n";
	destruct(armor);
	}
	else desc += "";
	return desc;
}

string look_door()
{
	object axe = new("/clone/unique/jinfu");
	string msg, desc;
	if(axe) {
	msg = HIY"��"NOR;
	destruct(axe);
	}
	else msg = "�ָ�";

	desc = "���ź������ֱ��һ��޴����ʯ��\n";
	if(query("door_axe"))
	desc += "һ��"+msg+"(axe)������ʯ���ŵ��Ż�(loop)�\n";
	if(query("door_lock")) 
	desc += "�������һ����ĸ��Ż����������߶೤�Ĵִ���ť(lock)��ס��\n";

	if(query("exits/enter"))
	desc += "�������ǿ��ŵġ�\n";
	return desc;
}

string look_axe()
{
	object axe = new("/clone/unique/jinfu");
	string msg, desc;
	if(axe) {
	msg = HIY"��"NOR;
	destruct(axe);
	}
	else msg = "�ָ�";

	if(!query("door_axe")) return 0;
	
	desc = msg+"����һ�����Ż��\n";
	return desc;
}

string look_lock()
{
	string desc;
	if(!query("door_lock"))
	desc = "ʯ���Ľǵ���ť���������ˡ�\n";
	else desc = "�ĸ���ť��ס��ʯ���Ľǡ�\n";
	return desc;
}

string look_loop()
{
	object axe = new("/clone/unique/jinfu");
	string msg, desc;
	if(axe) {
	msg = HIY"��"NOR;
	destruct(axe);
	}
	else msg = "�ָ�";

	if(!query("door_axe")) desc = "һ�����Ż��������������(pull)ʯ�š�\n";	
	else desc = "һ��"+msg+"�����Ż��\n";
	return desc;
}

string look_skeleton()
{
	object armor = new("/d/xingxiu/obj/jinjia");
	object me = this_player();
	string desc;
	if(armor) {
	message_vision("$N��"+armor->name()+"�Ӻ�����ȡ�£����˿����ǡ�\n", me);

	desc = "�⺡����ǰ�����Ǹ��������������ӡ�����Ź��У�ֻ�й��������Է��������ռǡ�\n";	
	CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ���ƽ���ס�", me->query("name")));
	armor->move(this_player());
	return desc;
	}
	else return "��Ҫ��ʲô��\n";
}

void init()
{
	add_action("do_scrape", "scrape");
	add_action("do_push", "push");
	add_action("do_pull", "pull");
}

int do_scrape(string arg)
{
	object me, room, weapon;
	string type;

	me = this_player();
	
	if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲ�ᶫ����\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("����æ���ء�\n");

	if( !objectp(weapon = me->query_temp("weapon")) ) 
		return notify_fail("�����Щ���ֵĹ��ߡ�\n");

	type = weapon->query("skill_type");
	if(type != "sword" && type != "blade" && type != "axe" ) 
		return notify_fail(weapon->name()+"���ʺ����������⡣\n");

	if( arg == "door")
		return notify_fail("��ʯ������ûʲ��ùεġ�\n");

	if( arg == "loop") {
		if(!query("loop_rust")) 
			return notify_fail("�Ż��ϵ������Ѿ��ε�ǬǬ�����ˡ�\n");
	message_vision("$N��"+weapon->name()+"��ȥ�Ż��ϵ����⡣\n", me);
	me->add("jingli", -30);
	delete("loop_rust");
	return 1;
	}
	if( arg == "lock") {
		if(!query("lock_rust")) 
			return notify_fail("��ť�ϵ������Ѿ��ε�ǬǬ�����ˡ�\n");
	message_vision("$N��"+weapon->name()+"��ȥ�ĸ���ť�ϵ����⡣\n", me);
	me->add("jingli", -120);
	me->start_busy(1);
	delete("lock_rust");
	return 1;
	}

	return 0;
}

int do_pull(string arg)
{
	object me, room;
	object axe;
	string msg;

	me = this_player();

	if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲ�᣿\n");

	if( arg=="axe" )
	{
		axe = new("/clone/unique/jinfu");

		if(axe) msg = HIY"��"NOR;
		else {
		msg = "�ָ�";
		axe = new("/d/dali/obj/gangfu");
		}

		if(!query("door_axe"))
			return notify_fail("��Ҫ��ʲ�᣿\n");

		if(query("loop_rust")) {
			destruct(axe);
			return notify_fail("������ȥ��"+msg+"�����Ż��ϵ���������ס������ȡ���������������ȹε�(scrape)���⡣\n");
		}
		message_vision("$N˫�ְγ�"+msg+"���������ǳ��ء�\n", me);
		axe->move(me);
		delete("door_axe");
		if(msg == HIY"��"NOR) CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ�ѻƽ𸫡�", me->query("name")));

		return 1;
	}

	if( arg=="lock" )
	{
		if(!query("door_lock"))
			return notify_fail("��ť�Ѿ����������ˡ�\n");

		if(query("lock_rust")) 
			return notify_fail("������ȥ����ť������ť�Ѿ����⣬�Ʋ��������������ȹε�(scrape)���⡣\n");
		message_vision("$N����ťһһ����\n", me);
		delete("door_lock");
		return 1;
	}
	
	if( arg=="door" ) return notify_fail("ʯ���Ϲ������������֮�������Ż�(loop)�ɡ�\n");

	if( arg=="loop" ) {
		if(query("exits/enter")) {
		message_vision("$Nʹ�������Ż���ʯ��ߴߴ�����˼������������һ�����죬ʯ�Ź����ˡ�\n", me);
		delete("exits/enter");
			if( room = find_object(__DIR__"jaderoad4") ) {
			room->delete("exits/out");
			message("vision", "ֻ����ߴߴ֮�����������һ�����죬ʯ���Ѵ�������˹��ϡ�\n", room );
			}
		return 1;
		}
		else {
		message_vision("$Nץס�Ż�����һ������ʯ������˿������\n", me);
		return 1;
		}
	}

	return 0;
}

int do_push(string arg)
{
	object me, room;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "door") {

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("����æ���ء�\n");

	if (query("exits/enter"))
		return notify_fail("��ʯ�����Ѿ����ƿ��ˡ�\n");

	if(query("door_axe"))
		return notify_fail("����ȰѴ����Ż��еĸ�ͷ�γ�(pull)��\n");

	if(query("door_lock"))
		return notify_fail("����Ȱѿ�ס�ŵ���ť����(pull)��\n");

	message_vision("$N˫�ֳ��ţ�����������ȥ����ʯ����ߴߴ�������������ˡ�\n", me);

	me->add("jingli", -50);

	set("exits/enter", __DIR__"jaderoad4");
		if( room = find_object(__DIR__"jaderoad4") ) {
			room->set("exits/out", __FILE__);
			message("vision", "������ߴߴ���������˴����潫��ʯ�����ƿ��ˡ�\n",room );
		}
	return 1;
	}
	else return notify_fail("��Ҫ��ʲ�᣿\n");
}

