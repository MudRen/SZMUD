//万子天 wanzitian.c
//Code by Scatter
//V. 2.0

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
        object obj, me=this_player();
        ::init();
        add_action("do_cun", "cun");
        add_action("do_qu", "qu");
                add_action("do_check", "checkspace");

                if(!this_player()->query("itembank/olduser"))
                {
                        if(this_player()->query("itembank/item") > 0)
                        {
                                if(!this_player()->query("wposition"))
                                {
                                        this_player()->set("itembank/olduser", 1);
                                }
                                else
                                {
                                        obj = new( me->query("wposition") );
                                        obj->move(me);
                                        me->add("itembank/item", -1);
           
                                        if( me->query("itembank/item") < 1 )
                                        {
                                                me->delete("itembank/item");
                                        }

                                        me->delete("wposition");
                                        message_vision("$n将一" + obj->query("unit") +
                                        obj->query("name") + "交给$N。\n", this_player(), this_object());
                                        write("因为新的功能关系，所以先把东西还给你，你可以从新存一次。\n有问题请找我  神州创意巫师 -- 分冥子\n");
                                }
                        }
                }
}

int do_check(string arg)
{
        object me = this_player();
        int maxspace;

        maxspace = me->query("itembank/maxitem") - me->query("itembank/item");
        write("你还可以放最多 " + maxspace + " 样东西。\n");
        return 1;
}


int do_cun(string arg)
{
       object ob, *inv;
       object me;
       int value, i;
       int totalitem, maxitem;
           string idname, wposname, tempdummy;

       me = this_player();
           maxitem = me->query("itembank/maxitem") + 1;

           if( !arg || sscanf(arg, "%s %s", tempdummy, idname)!=2 ) 
           {
                   write("格式不对，cun <存放物品的名字> <为存放空间取名字>\n例: cun jian item1\n");
                   return 1;
           }

       inv = all_inventory(this_object());
       if (!arg || !(ob = present(tempdummy, this_player())))
                   return notify_fail("你要寄放什么？\n");
       if (me->query("itembank/item") > maxitem)
                   return notify_fail("对不起，你已经放过多的东西了．\n如果空间不够，目前可以先向巫师购买，每增加一个空位定价为三百两黄金。\n");
       if(!ob->query("wposition"))
           return notify_fail("这样东西不是标准产品，我们不能收．\n");
       if (ob->query("food_supply"))
           return notify_fail("剩菜剩饭我们不收的。\n");
           

           wposname = "weaponpos/" + idname;
           // THIS IS A NEW WAY TO SAVE STANDAR ITEMS
                           if(!me->query(wposname))
                           {    
                                   me->set(wposname, ob->query("wposition"));
                                   me->add("itembank/item", 1);
                           }
                           else
                           {
                                   write("你已经有位置是用这个名字了，请取别的名字吧。\n");
                                   return 1;                                       
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
        string tempdummy, idname;
        string weaponpos;
    me = this_player();

        if( !arg ) 
           {
                   write("格式不对，qu <存放空间取名字>\n例: qu item1\n");
                   return 1;
           }



    if (!me->query("itembank/item"))
    {
    write("你没有东西在我这里呀!\n");
    return 1;
    }


        weaponpos = "weaponpos/" + arg;
        if(!me->query(weaponpos))
        {
                write("对不起，没有找到你要的东西，请确定名字没错。\n");
                return 1;
        }

    obj = new( me->query(weaponpos) );

       obj->move(me);
       me->add("itembank/item", -1);
           
           if( me->query("itembank/item") < 1 )
           {
                   me->delete("itembank/item");
           }

           me->delete(weaponpos);
           message_vision("$n将一" + obj->query("unit") +
       obj->query("name") + "交给$N。\n", this_player(), this_object());

       return 1;
}

