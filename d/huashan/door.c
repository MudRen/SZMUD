// Code of ShenZhou
// door1.c ��ɽ��ɽС·����ʯ��ǰ
// qfy 8/11/97

inherit ROOM;

void create()
{
	set("short", "ʯ��ǰ");
	set("long", @LONG
ʯ��(door)�����ţ��������ƺ��൱�ĺ�������������ʯ��������
Ƕ�������������ͷ���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"up" : __DIR__"stair",
	]));

	set("item_desc",([
	    "ʯ��" : "ʯ���Ͽ��š����彭�����ĸ���׭���֣����ܽ��Ǿ��µĸ���\n",
	    "door" : "ʯ���Ͽ��š����彭�����ĸ���׭���֣����ܽ��Ǿ��µĸ���\n",
	]));

	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}

int do_open()
{
	object me=this_player();

	if ( query_temp("open") ) {
		write("ʯ���Ѿ��ǿ��ŵ��ˣ�\n");
		return 1;
	}

	message_vision("$N�����ڹ���˫�ư���ʯ���ϣ�����������ȥ��\n", me);
	message_vision("ʯ����һ�����֮�ᣬ�����ؿ����ˡ�\n", me);

	set("exits/enter", __DIR__"mishi");
	set("long", "ʯ�ų����ţ�������Լ��һ������\n");
	set_temp("open", 1);
	remove_call_out("auto_close");
	call_out("auto_close", 5, this_object());

	return 1;
}

int do_close()
{
	object me=this_player();

	if ( !query_temp("open") ) {
		write("ʯ���Ѿ��ǹ��ŵ��ˣ�\n");
		return 1;
	}

	message_vision("$N�����ڹ���˫��ץ��ʯ���Ż��ϣ���������ǰ����\n", me);
	message_vision("ʯ����һ�����֮�ᣬ�����عر��ˡ�\n", me);

	set("long", "ʯ��(door)�����ţ��������ƺ��൱�ĺ�������������ʯ��������\nǶ�������������ͷ���\n");
	delete("exits/enter");
	delete_temp("open");
	remove_call_out("auto_close");

	return 1;
}

void auto_close(object room)
{
    	if ( room->query_temp("open") ) {
    		message("vision","ʯ��ͻȻ����һ����죬�Զ��ر�������\n", room);
		set("long", "ʯ��(door)�����ţ��������ƺ��൱�ĺ�������������ʯ��������\nǶ�������������ͷ���\n");
    		room->delete("exits/enter");
		room->delete_temp("open");
	}
}	