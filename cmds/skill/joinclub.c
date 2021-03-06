// Code of ShenZhou
// joinclub.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_app;
        mapping family, skills;
        int i;
        string *skname;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( !arg ) 
                return notify_fail("指令格式：joinclub <对象>\n");

        if( !(ob = present(arg, environment(me)))
        ||      !ob->is_character() )
                return notify_fail("你想加入谁的帮派？\n");

        if( !living(ob) ) 
                return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

        if( ob==me ) 
                return notify_fail("加入自己的帮派？。。不过没有用。\n");
        
        if (!ob->query("in_club"))
                return notify_fail("对方好像无帮无派啊。\n"); 
        if (me->query("in_club"))
                return notify_fail("你必须先退帮，才能从新入帮。\n"); 
        
        me->start_busy(1);
        me->set_temp("joinclub",ob->query("id"));
        message_vision(HIR"看来$N想加入$n的帮派。\n",me,ob);
        return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : joinclub <对象>
此命令用来加入一个帮派。 
HELP
        );
        return 1;
}
