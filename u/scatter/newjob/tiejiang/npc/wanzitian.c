                                         //������ wanzitian.c
//Code by Scatter
//V. 1.0

#include <ansi.h>
inherit NPC;
void create()
{
set_name("������",({"Wan Zitian", "wan", "zi", "tian", "zitian"}));
set("title",HIW"��Ʒ����"NOR);
set("age",40);
set("gender","����");
set("long", "������Ʒ���ܵ��ܹܣ���Ʒ���ܴ���Ĵ�С������������
�������˶��������ܹܡ� \n");
setup();
carry_object("/clone/armor/cloth")->wear();

}


void init()
{
        ::init();
        add_action("do_cun", "cun");
        add_action("do_qu", "qu");
}

int do_cun(string arg)
{
       object ob, *inv;
       object me;
       int value, i;
       int totalitem;
       me = this_player();


       inv = all_inventory(this_object());
       if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ�ķ�ʲô��\n");
       if (me->query("itembank/item") > 0)
                                return notify_fail("�Բ���, ��Ϊ�ռ�����, ����ÿ��ֻ�������˴�����һ����Ʒ\n");
       if(!ob->query("wposition"))
                return notify_fail("�����������Ǳ�׼��Ʒ�����ǲ����գ�\n");
           if (ob->query("food_supply"))
                return notify_fail("ʣ��ʣ�����ǲ��յġ�\n");
	   if(ob->query("family/family_name") == "��Ĺ��");
				return notify_fail("��Ĺ���Ӳ�����������, ��Ӧ�üķŶ���ѽ!\n");

       // Saving Data
           
       totalitem = totalitem + 1;
       me->set("itembank/item", totalitem);
       
           /*
           me->set("itembank/itemname", ob->query("name"));
       me->set("itembank/itemweight", ob->query("weight"));
       me->set("itembank/itemunit", ob->query("unit"));
       me->set("itembank/itemmaterial", ob->query("material"));
       me->set("itembank/itemrigidity", ob->query("regidity"));
       me->set("itembank/itemwieldmsg", ob->query("wield_msg"));
       me->set("itembank/itemunwieldmsg", ob->query("unwield_msg"));
       me->set("itembank/itenunequipmsg", ob->query("unequip_msg"));
       */
       // End of saving Data


        // THIS IS A NEW WAY TO SAVE STANDAR ITEMS
           if ( ob->query("wposition") )
           {
                        //write( ob->query("wtype") );  // For Test Only
                        me->set("wposition", ob->query("wposition"));
           }



        value = ob->query("value");
                        message_vision("$N��һ" + ob->query("unit") +
                        ob->query("name") + "����$n��\n", this_player(), this_object());
                        for (i = 0; i < sizeof(inv); i++)
                        if (inv[i]->query("name") == ob->query("name")){
                        inv[i]->add("quantity", 1);
                        destruct(ob);
                        return 1;
                        }
                        ob->move(this_object());
                        ob->set("quantity", 1);
                        if (ob->query_amount())
                        destruct(ob);
        return 1;
}


int do_qu(string arg)
{
    object me, obj;
    me = this_player();

    if (!me->query("itembank/item"))
    {
    write("��û�ж�����������ѽ!\n");
    return 1;
    }


    obj = new( me->query("wposition") );

       obj->move(me);
       me->delete("itembank/item");

       message_vision("$n��һ" + obj->query("unit") +
       obj->query("name") + "����$N��\n", this_player(), this_object());

       return 1;
}
