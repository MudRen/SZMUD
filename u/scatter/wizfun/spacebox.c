 //spacebox.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;


void create()
{
set_name(HIW"����������"NOR,({"space"})); 

        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","ֻ");
                set("long","�� open space �Ϳ�������һ�����õĴ�ſռ�\n");
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
                write("���ǳ�������, ��������\n");
                return 1;
        }

        return 0;
}


int do_openbox (string arg)
{
        object me = this_player();
        if(arg = "space")
        {
                message_vision(HIY"$N����д�.\n$N����һ�����λ����.\n"NOR, me);
                                me->add("itembank/maxitem", 1);
                                destruct(this_object());
                return 1;
        }

        return 0;
}
