// Room /d/wulin/shishe.c
// updated by Lara 2001/10/17
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ʫ��");
        set("long", @LONG
����һ�����µ��ŵ�ȥ�����м���������������Ʒ����̸��˵�أ���
�����ڡ�����㸹�о��ڡ����к���������������ī��ʫ����ʹ���Ĳɲ�
������Ҳ��������������Ĵ�������ֽ��board�� �Ѿ�Ϊ��׼�����ˡ���
ע�⣬����ֻ��ӭ���ġ��Ļ��⣬����Ϸ�κΡ��ġ��ķ���Ĳ���򲻺�
��֮���㶼�����������������Ϸ�����߻��ڵ�һʱ������ǡ��������
�������ƶ�����ͬ�˷�չ����ң����˸�����ҹ����й涨�Ľ����⣬��
��õ�����ͬ������ͷ�ε����⽱���������������
LONG
        ); 
              set("exits", ([
		"east" : __DIR__"dating",
    ]));
                set("no_fight", "1");
                set("cost", 1);
                setup();
           call_other("/clone/board/shishe_b", "???");
}
void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}

int do_respirate(string arg)
{
        object me = this_player();
        tell_object(me, "���ں���ʫ�����ֻ�����Ļ����ң�ȫ������Ҳ�޷�����������\n");
        return 1;
}
int do_practice(string arg)
{
     object me = this_player();
        tell_object(me, "����վ������ȴ���û�����ȫ���᲻��һ˿������������\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "��ֻ�����Դ��﷢�Σ��鱾��һ�����ֶ�������ȥ����Ҳ������ȥ��\n");
        return 1;
}
