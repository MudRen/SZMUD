// Code of ShenZhou
// Room: /d/heimuya/basket.c
// Date: fear 1999/12/18

inherit ITEM;
#include <ansi.h>;

void on_basket();
void arrive();
void close_passage();
int do_knock(string arg);
void reset();

void create()
{
        set("short","����¨");
	set("long",@LONG
����һֻ����¨�����װ��ʮ��ʯ�ס��Ա߹���һ��Сͭ�ࡣ
LONG);
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}

void init()
{
    add_action("do_knock", "knock");
}

void on_basket()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "ֻ����¨һ��,��ʼ�����ƶ���\n",
        this_object() );

    if( room = find_object(__DIR__"basket") )
    {
        room->delete("exits/out");
        message("vision", "��¨��ס�ƶ���һƬƬ���ƴ�ͷ��Ʈ������������
������¨�ף�ȴʲôҲ��������\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 40);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"basket") )
    {
        room->set("exits/out", __DIR__"clifftop");
        message("vision", "ֻ���ý���һ����¨��ͣ����������Ҳû��ֶ�����\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 1);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"basket") ) {
        room->delete("exits/out");
        message("vision","����¨����ʼ�����ƶ���\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_knock(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="tongluo" ) arg = "ͭ��";
        message_vision("��������$Nʹ�����̵���������ͭ�����¡�\n",
            this_player());
    if( arg=="ͭ��")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("��Ҫ��ʲô��\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"basket") )
        room->delete("yell_trigger"); 
}
