//JAIL.C
//CODE BY SCATTER
//V. 1.0

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY"宗仁府"NOR);
        set("long", "这里就是专门关巫师的地牢"+HIY"宗仁府"+NOR"．近来的人除了忏悔，还是忏悔．\n直到有人愿意把你放出来为止．在这里的门口有一个看守监狱的人，\n如果有任何问题(ask guard about all)或是要他帮你留言(post TITLE)，\n就跟他说吧．总而言之，你不回改是一辈子都出不来的．现在你的所有通讯\n权力都被暂时取消了．所以你好自为之吧！\n\n 宗仁府守卫(GUARD)\n");
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
        tell_object(me,"宗仁府守卫说道：休息一下吧！\n"NOR);
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
        tell_object(me,"宗仁府守卫说道：休息一下吧！\n"NOR);
        return 1;
        }
return 0;
}
