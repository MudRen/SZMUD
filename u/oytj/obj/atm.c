// atm.c �Զ�ȡ���

#include <ansi.h>

inherit ITEM;

int do_withdraw(string);
void init();

void create()
{
        set_name("�Զ�ȡ���", ({ "ATM machine", "atm", "machine"}) );
        set_weight(5000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "̨");
                set("long", "����һ̨�Զ�ȡ�������������ȡ�ֽ�\n");
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
                return notify_fail("�㲻����ʦ����Ȩ����̨����! \n");
                
        if( !arg || sscanf(arg, "%d %s", amount, id) != 2 )
                return notify_fail("ʹ�÷�����withdraw <amount> <money>\n");
                
        if( amount < 1 )
                return notify_fail("��̫���Ŷ��˰�! \n");
                
        if( file_size("/clone/money/" + id + ".c") < 0 )
                return notify_fail("����Ǯ��û�������\n");
                
        ob = present(id + "_money", me);
        if( !ob ) {
                ob = new("/clone/money/" + id);
                ob->move(me);
                ob->set_amount(amount);
        } else ob->add_amount(amount);
        
        message_vision(sprintf(HIY "$N���Զ�ȡ�����ȡ��%s%s%s�����ڻ��\n" NOR,
                chinese_number(amount), ob->query("base_unit"),
                ob->query("name")), me);
                                
        return 1;       
}
