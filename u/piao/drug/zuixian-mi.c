// Code of ShenZhou
// zuixianmi.c
// fixed bug, sdong, 7/16/1999

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"������"NOR, ({"zuixian mi", "mi"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "����һ��ʯ�����¼��洫����ҩ��\n" );
                set("unit", "��");
                set("value", 286);
                set("medicine", 1);
        }
        setup();
}

void init()
{
        add_action("do_pour", "pour");
}

int do_pour(string arg)
{
        int da;
        string me, what;
        object ob;
        function f;

        if( !arg
        ||      sscanf(arg, "%s in %s", me, what)!=2
        ||      !id(me) )
                return notify_fail("�����ʽ: pour <ҩ> in <��Ʒ>��\n");

        ob = present(what, this_player());
        if( !ob )
                return notify_fail("������û��" + what + "����������\n");
        if( !ob->query("liquid/remaining") )
                return notify_fail(ob->name() + "��ʲôҲû�У���װЩ��ˮ�����ܻ�ҩ��\n");
        da = ob->query("liquid/drunk_apply");

        if (da > 8 )da = 8; // must set uplimit, otherwise pour in jiuping with guiyuan dan can add nieli 100M

        ob->set("liquid/drunk_apply",da*5);
        ob->set("zuixian",1);
        message_vision("$N��һ��"+ name() + "����" + ob->name() 
                + "ҡ���˼��¡�\n", this_player());
        destruct(this_object());
        return 1;
}
