//buwu.c 布武出气娃娃

#include <ansi.h>
#include <weapon.h>
inherit SWORD;


void create()
{
        set_name("布武可爱出气娃娃 (V 3.0)",({"buwu"}));

        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                    set("unit","只");
                set("long","这是布武可爱出气娃娃, 可以对他下以下的指令 (V, 3.0)\n kick buwu \n da buwu \n smash buwu \n sorry buwu \n roll buwu \n sit buwu \n stand buwu \n left buwu \n right buwu\n sing buwu \n还有存放功能喔!!\n");
                set("value", 0);
                set("material", "steel");
        }
                set("wposition", "/u/scatter/wizfun/buwu30.c"); 
        init_sword(1);
        setup();
}


void init() 
{
        add_action("do_wield", "wield");
        add_action("do_kick", "kick");
        add_action("do_da", "da");
        add_action("do_smash", "smash");
        add_action("do_sorry", "sorry");
        add_action("do_roll", "roll");
        add_action("do_sit", "sit");
        add_action("do_stand", "stand");
        add_action("do_left", "left");
        add_action("do_right", "right");
        add_action("do_sing", "sing");

}

int do_sing (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIG"*****由 菲力克斯(Felix) 提共*****\n$N按了按步武的鼻子\n步武唱起了“娃娃的爱”结果发现 -- 五音不全\n连路过的狗都站不直, 抽续几下, 倒在地上\n"NOR, me);
                return 1;
        }

        return 0;
}



int do_right (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIC"$N说到: 向右转!\n布武说到: YES SIR!  (向右转去了)\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_left (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIY"$N说到: 向左转!\n布武说到: YES SIR!  (向左转去了)\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_stand (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$N说到: 站起来!\n只见到布武被吓的站了起来\n"NOR, me);
                return 1;
        }

        return 0;
}

int do_sit (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$N说到: 坐下!\n只见到布武真的做下了\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_roll (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$N说到: 我不想见到你. 布武倒在地上，像一根大木柱般直滚到一扇门边，咕碌碌的便滚了出去。.\n一边滚一边说, 都是我的错.\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_wield (string arg)
{
        if(arg = "buwu")
        {
                write("这是出气娃娃, 不是武器\n");
                return 1;
        }

        return 0;
}


int do_kick (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$N使出无影脚快速的向布武一脚踢了过去.\n"NOR, me);
                return 1;
        }

        return 0;
}

int do_da (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIC"$N使出铁沙掌一掌将布武压扁在地上.\n"NOR, me);
                return 1;
        }

        return 0;
}



int do_smash (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIG"$N那出一个槌子在布武头上槌了上百下.\n"NOR, me);
                return 1;
        }

        return 0;
}



int do_sorry (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIY"$N骂了布武一顿, 只见布武一直说到: 对不起, 我错了, 打我吧.\n"NOR, me);
                return 1;
        }

        return 0;
}

