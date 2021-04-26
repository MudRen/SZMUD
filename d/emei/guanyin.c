// Code of ShenZhou
// guanyin.c ������
// by Shan

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ø߾��¸ڣ�����Σ�£������ľ���������ľ��������Ŀ���ġ���˵
��ɽ�ڴˣ����ѳ�������ɽ�ڴˣ��������裬�ֹ��������֡���ɽ�����ڴ˷�
��ϴ�ģ���ɽ���ɻ���Ϊ�ģ�����ƽ�������ﶫ�¿ɴ�����£�������Լ����
�ɵ����Ƹ�
LONG
        );
        set("exits", ([
		"westup" : __DIR__"guiyun",
                "east" : __DIR__"jietuo",
        ]));

	set("outdoors", "emei");
        set("fjing", 1);

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

void init() 
{
	add_action("do_burn", "burn");
	add_action("do_burn", "fen");
}

int do_burn(string arg)
{
	object me = this_player();

	if ( !arg || (arg != "incense" && arg != "��" && arg != "xiang") )
		return command("burn "+arg);

	this_player()->set_temp("apply/karma", 20+random(20));
	message_vision(YEL"$N�ϵ��ڹ�����ǰ����ϴ�ģ�������ɽƽ����\n"NOR, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "east") me->delete_temp("apply/karma");
	return ::valid_leave(me, dir);
}

