// Code of ShenZhou
// shandong2.c ����������ɽ��
// qfy July 9, 1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
�ⶴ��ʵ��ǳ���в������ɣ��ѵ־�ͷ�����г���һ��ʯ����һ��ʯ
��֮����ޱ������һ����ʯ���𣬼���һ����Ĺ(grave)������(wall)
ȫ������̦�Σ��ڰ���ʲô�Ʋ������
LONG
        );

	set("exits", ([
                "out" : __DIR__"dongqian",
        ]));

	set("item_desc",([
	    "wall"  : "һ��������̦��ʯ�ڡ�\n",
	    "grave" : "һ����ʯ�ѳɵķ�Ĺ����֪������λǰ�������֮����\n"
        ]));

	set("cost", 2);
        setup();
}

void init()
{
	add_action("do_kneel", "kneel");
	add_action("do_use", "use");
}

int do_use(string arg)
{
    object me = this_player();

    if( !arg || arg=="" ) return 0;

    if (!present("fire", me))  return 0;

    if( arg=="fire" ) {
	write("���ȼ�˻��ۣ�����Ĩȥ�����ϵ���̦��ͻȻ�ֳ������������ּ���\n");
	write("����ϸ����ʯȴ�Ǽ�������ü������ı��л��ɡ����������ֵ���\n\n");
	write("�ݺὭ����ʮ���أ�ɱ����ܣ��ܾ�Ӣ�ۣ����¸��޿��֣��޿��κ�\n");
	write("Ω������ȣ��Ե�Ϊ�ѡ��غ�����ƽ��һ���ֶ����ɵã��ϼ����ѿ�\n");
	write("Ҳ��\n");
	write("\t\t\t\t\t��ħ�������\n");
	me->set_temp("marks/ǽ", 1);
    }	

    return 1;
}

int do_kneel(string arg)
{
	object me = this_player();

	if( !arg || arg != "grave" ) 
	   return notify_fail( "ʲô��\n" );

	message_vision("$N��ʯĹ֮ǰ���������ع������������˼��ݡ�\n", me);
	me->set_temp("marks/Ĺ", 1);

	return 1;
}
