// /d/wizard/news_room.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", GRN"������﹫�洦"+NOR);  
        set("long", @LONG
��������������ͨ�淲�磬���������������Ĺ���塣��������ڵ�һ
ʱ��֪����Ϸ�����¶�̬�������µ����⡢�µĹ������µ�ϵͳ���µ������书��
��Ӧ�þ�����������תת�������������ӣ���Ҷ��ھ���������Ϸ���±仯��
LONG
        );
        set("exits", ([
                "northeast": "/d/wizard/guest_room",
    ]));
        set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        "/clone/board/toplayer_b"->foo();
}
void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}
int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "�����������Ż�������������\n");
        return 1;
}
int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "�����Ѿ��������ˣ����������ˣ�\n");
        return 1;
}
int do_study(string arg)
{
      object me = this_player();
        tell_object(me, "��������ù�Ҳ������һ��ɣ�\n");
        return 1;
}
