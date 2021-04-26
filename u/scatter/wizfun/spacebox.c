 //spacebox.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;


void create()
{
set_name(HIW"超大贮物箱"NOR,({"space"})); 

        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","只");
                set("long","打 open space 就可以增加一个永久的存放空间\n");
                set("value", 0);
                set("material", "steel");
        }
        init_sword(1);
        setup();
}


void init() 
{
        add_action("do_openbox", "open");
                add_action("do_wield", "wield");
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


int do_openbox (string arg)
{
        object me = this_player();
        if(arg = "space")
        {
                message_vision(HIY"$N将礼盒打开.\n$N多了一个存放位置了.\n"NOR, me);
                                me->add("itembank/maxitem", 1);
                                destruct(this_object());
                return 1;
        }

        return 0;
}
