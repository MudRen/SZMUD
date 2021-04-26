// /d/city/ftb_mishi.c
//Alan.F 20010927
#include "room.h"
#include "ansi.h"

int do_break(string);


inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ�ͷ���һ�����ң�ǽ�Ϲ���һյ�͵ƣ��м���Ÿ��㰸��������һ
�˵���λ��lingwei����һ����(letter)����ϸһ������д��Ԭ�����ԭ��������
�����İ����ҳ�����λ��û�뵽��ͷ�ﾹ��˾��ذ������졣�㰸��������һֻ��
���ӣ�xiangzi��,�����Ѿ���Ĵ򲻿��ġ�
LONG
        );
        set("exits", ([
                "up" : __DIR__"minwu1",
        ]));
        set("cost", 1);
        set("invalid_startroom", 1);
        
	set("item_desc", ([
		"lingwei": "Ԭ�������λ\n",
		"letter": "����Ԭ�������������Ϊ��ͷ��������ٽ����粨��׳ʿΪ��ͷ�ﾡ�ľ�������һ���������α�����\n",
		"xiangzi": "һ�������ӣ����Ѿ����ˣ���������������˿���break��\n",
	]));
        
        
        setup();
}
        
void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
    int qi,max_qi;
    object me = this_player();
    object gold,jian;
    max_qi = me->query("max_qi");
    qi = me->query("qi");


    if( !arg || arg!="xiangzi" ) {
        write("��Ҫ��������˵Ķ�����\n");
        return 1;
    }

if (me->query("mishi")){

    message_vision(
    "$N��������������һ�š�\n", me);
        
        message_vision(
        "ֻ��һ�����죬$N�����Ӹ���ɢ�˼ܣ�\n", me);
        tell_object(me,HIR "�����鱦ɢ��һ�ء�\n" NOR);
        me->set("max_qi",max_qi-1);
//        jian = new ("/clone/unique/bixue-jian");
        gold = new("/clone/money/gold");
        gold->set_amount(100);
//        jian -> move(me);
        gold -> move(me);
        tell_object(me,HIR "���æſ����ȥ������������һ�ţ����±�������ġ�\n" NOR);
        tell_object(me,HIY "��������һ��ѻƽ�\n" NOR);
//        tell_object(me,RED "����һ������\n" NOR);
        me->delete("mishi");
  }
  else {
        message_vision(
        "$N��������������һ��,����ȶ��ˡ�\n", me);
        me->set("max_qi",max_qi-10);
        me->set("qi",qi-100);
        
    }
    return 1;

  }