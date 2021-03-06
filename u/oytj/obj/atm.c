// atm.c 自动取款机

#include <ansi.h>

inherit ITEM;

int do_withdraw(string);
void init();

void create()
{
        set_name("自动取款机", ({ "ATM machine", "atm", "machine"}) );
        set_weight(5000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "台");
                set("long", "这是一台自动取款机，可用来提取现金。\n");
                set("value", 1000000);
                set("material", "steel");
                set("no_get",1);
        }
        setup();
}

void init()
{
        add_action("do_withdraw", "withdraw");
}

int do_withdraw(string arg)
{
        object me, ob;
        string id;
        int amount;
        
        me = this_player();
        
        if( !wizardp(me) )
                return notify_fail("你不是巫师，无权用这台机器! \n");
                
        if( !arg || sscanf(arg, "%d %s", amount, id) != 2 )
                return notify_fail("使用方法：withdraw <amount> <money>\n");
                
        if( amount < 1 )
                return notify_fail("你太抠门儿了吧! \n");
                
        if( file_size("/clone/money/" + id + ".c") < 0 )
                return notify_fail("这种钱还没造出来。\n");
                
        ob = present(id + "_money", me);
        if( !ob ) {
                ob = new("/clone/money/" + id);
                ob->move(me);
                ob->set_amount(amount);
        } else ob->add_amount(amount);
        
        message_vision(sprintf(HIY "$N从自动取款机里取出%s%s%s，揣在怀里。\n" NOR,
                chinese_number(amount), ob->query("base_unit"),
                ob->query("name")), me);
                                
        return 1;       
}
