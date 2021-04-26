// Code of ShenZhou
// cliff.c ����

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������ǰ��һ���ͱ���(wall)����Χ���ǰ�ãã������ʲôҲ����
����
LONG
        );

	set("item_desc",([
		"wall" : "һ���ͱڡ�\n",
	]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
	set("invalid_startroom", 1);

	set("cost", 7);
        setup();
//      replace_program(ROOM);
}

void init()
{
	if ( this_player()->query_temp("exit") ||  this_player()->query("jinshe") )
		set("exits/enter", __DIR__"yongdao3");

	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_break", "break"); 
	add_action("do_break", "dig");
	add_action("do_break", "wa");
	add_action("do_sleep", "sleep");
//	add_action("do_quit", "quit");
}
/*
int do_quit()
{
	object me = this_player();

	me->move("/d/huashan/fengding");
	me->command("quit");
	return 1;
}
*/
int do_sleep()
{
	write("�����ڰ�������˯����\n");
	return 1;
}

int do_climb(string arg)
{
        object me = this_player();

        if ( arg && arg != "up" )
                return notify_fail("ʲô��\n");

        if ( !me->query_temp("tied") )
                return notify_fail("û����֧������ô��ѽ��\n");

        message_vision("$N�������ӿ�ʼ���¶�����ȥ��\n", me);
        message("vision", me->name()+"һ�������ʧ���������ˡ�\n", environment(me), ({me}) );

	me->move(__DIR__"fengding");
	message("vision", me->name()+"����������ɾ���������������\n", environment(me), ({me}) );

	me->receive_damage("qi", 150, "����͸֧��������");

	return 1;
}

int do_break(string arg)
{
	object weapon, me = this_player();

        if ( !arg || arg != "wall" ) return 0;

	if ( objectp(weapon=me->query_temp("weapon")) && weapon->name() != "����" ) {
		message_vision("$N����"+weapon->name()+"���ͱ������˼��¡�\n", me);
		message_vision("ֻ���á�ž����һ����"+weapon->name()+"��Ϊ���أ�\n", me);
		destruct(weapon);
		return 1;
	}

	if ( !weapon ) {
		message_vision("$N�������ͱ������˼��£�ͻȻһ��ʹ�У��ƺ���ʲô�������ţ����������Ѫ���죡\n", me);
		me->receive_wound("qi", 20, "���˹�������");
		return 1;
        }

	if ( random(10) == 1 ) {
		message_vision("$N�������ھ���һ��ͻȻ���ñ���һ���ɶ���æ�ӽ����Ʒ��࣬¶��һ��С��Ѩ��\n", me);
		set("exits/enter", __DIR__"yongdao3");
		me->set_temp("exit", 1);
	}
	else message_vision("$N�������ھ���һ��ʲôҲû���֡�\n", me);

	me->receive_damage("qi", 20, "����͸֧���ȣ�ʧ�ֵ��¾�������");
	
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !me->query("jinshe") && me->query("age") > 22 && me->query_str() > 20 ) 
		return notify_fail("������̫���ˣ�����������ȥ��\n");

	return ::valid_leave(me, dir);
}
