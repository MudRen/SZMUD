inherit ITEM;
void create()
{
      set_name("金蛋",({"jin dan","dan"}));
     if(clonep())
    set_default_object(__FILE__);
    else{
    set("unit","颗");
    set("value",4000);
        set("long","这是一颗金光灿烂的金蛋(听说可以治相思病)。\n");
                set("medicine", 1);
    }
    setup();
}


int cure_ob(object me)
{
    object ob1=this_object();
    object ob=new("clone/money/gold");
         ob->set_amount(10);
      me->set("max_neili",me->query("max_neili")+2);
    me->set("neili",me->query("neili")+200);
    me->set("max_jingli",me->query("max_jingli")+2);
    me->set("jingli",me->query("jingli")+200);
     message_vision("$N服下一颗金蛋，新年一定发大财！\n",me);
    ob->move(me);
    destruct(ob1);
    return 1;
}
// 注：切勿流落凡间
