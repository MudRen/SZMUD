//JAIL.C
//CODE BY SCATTER
//V. 1.0

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY"���ʸ�"NOR);
        set("long", "�������ר�Ź���ʦ�ĵ���"+HIY"���ʸ�"+NOR"���������˳�����ڣ�������ڣ�\nֱ������Ը�����ų���Ϊֹ����������ſ���һ�����ؼ������ˣ�\n������κ�����(ask guard about all)����Ҫ����������(post TITLE)��\n�͸���˵�ɣ��ܶ���֮���㲻�ظ���һ���Ӷ��������ģ������������ͨѶ\nȨ��������ʱȡ���ˣ����������Ϊ֮�ɣ�\n\n ���ʸ�����(GUARD)\n");
        set("no_fight", "1");
        set("no_steal", "1");
        set("cost", 3);
        setup();
}
void init()
{
        object me = this_player();
        
        add_action("do_leave", "leave");
        add_action("do_err", "chat");
        add_action("do_err", "tell");
        add_action("do_err", "goto");
        add_action("do_err", "summon");
        add_action("do_err", "more");
        add_action("do_err", "tail");
        add_action("do_err", "say");
        add_action("do_err", "emote");
        add_action("do_err", "reply");
        add_action("do_err", "quit");
        add_action("do_err", "exit");
        add_action("do_err", "sys");
        add_action("do_err", "wiz");
        add_action("do_err", "rumor");
        add_action("do_err", "copy");
        add_action("do_err", "destroy");
        add_action("do_err", "home");
        add_action("do_err", "cp");
        add_action("do_err", "set");
        add_action("do_err", "chat*");
        add_action("do_err", "sys*");
        add_action("do_err", "rumor*");
        add_action("do_err", "xkx");
        add_action("do_err", "xkx*");
        add_action("do_err", "call");
//        add_action("do_err", "look");
//        add_action("do_err", "l");
        add_action("do_err", "hp");
        add_action("do_err", "i");
        add_action("do_err", "where");
        add_action("do_err", "data");
        add_action("do_err", "suicide");
        add_action("do_err", "menpai");
        add_action("do_err", "menpai*");
        add_action("do_err", "whisper");
        add_action("do_err", "read");

}

int do_err()
{
        object me;
 
        me = this_player();


        if (me->query("id") == "huaishi")
        {
        return 0;
        }

        else if (me->query("id") == "scatter")
        {
        return 0;
        }

        else
        {
        tell_object(me,"���ʸ�����˵������Ϣһ�°ɣ�\n"NOR);
        return 1;
        }
}

int do_leave()
{
        object me;
 
        me = this_player();


        if (me->query("id") == "buwu")
        {
        me->move("/d/wizard/wizard_room.c");
        }


        else if (me->query("id") == "celery")
        {
        me->move("/d/wizard/wizard_room.c");
        }

        else
        {
        tell_object(me,"���ʸ�����˵������Ϣһ�°ɣ�\n"NOR);
        return 1;
        }
return 0;
}
