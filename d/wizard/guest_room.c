// /d/wizard/guest_room.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��罻����");
	set("long", @LONG
���������ɺ���ҽ����ĵط����������ʲô������Ҫ��������̣�������
��������(post)�������������ǣ�浽���ջ����Ѿ��ڰ����ļ�������ϸ˵����
�����ǾͲ�һ����ش�¥������ʦ��Ϣ�ң�������������﹫�洦��
LONG
	);

	set("exits", ([
		"up": __DIR__"wizard_room",
		"west" : __DIR__"proom",
               "southwest" : __DIR__"news_room",
		"southeast": "/d/city/wumiao" ]));
	set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");
    //  create_door("southeast", "����", "northwest", DOOR_CLOSED);

	set("cost", 0);
	setup();
	call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
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
        tell_object(me, "���������ͻ�������������\n");
        return 1;
}

int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "�ڿ�����Ҳ��������̫�����˰ɣ�\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "���ͻ�����飬����ô����ò��ã�\n");
        return 1;
}

