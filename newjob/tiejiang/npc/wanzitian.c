                                         //万子天 wanzitian.c
//Code by Scatter
//V. 1.0

#include <ansi.h>
inherit NPC;
void create()
{
set_name("万子天",({"Wan Zitian", "wan", "zi", "tian", "zitian"}));
set("title",HIW"物品保管"NOR);
set("age",40);
set("gender","男性");
set("long", "他是物品保管的总管，物品保管处里的大小事务都是由他来
管理，人人都叫他万总管。 \n");
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
                return notify_fail("你要寄放什么？\n");
       if (me->query("itembank/item") > 0)
                                return notify_fail("对不起, 因为空间有限, 所以每人只能在这了存放最多一件物品\n");
       if(!ob->query("wposition"))
                return notify_fail("这样东西不是标准产品，我们不能收．\n");
           if (ob->query("food_supply"))
                return notify_fail("剩菜剩饭我们不收的。\n");
	   if(ob->query("family/family_name") == "古墓派");
				return notify_fail("古墓弟子不是隐居了吗, 不应该寄放东西呀!\n");

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
                        message_vision("$N将一" + ob->query("unit") +
                        ob->query("name") + "交给$n。\n", this_player(), this_object());
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
    write("你没有东西在我这里呀!\n");
    return 1;
    }


    obj = new( me->query("wposition") );

       obj->move(me);
       me->delete("itembank/item");

       message_vision("$n将一" + obj->query("unit") +
       obj->query("name") + "交给$N。\n", this_player(), this_object());

       return 1;
}
