inherit ITEM;
void create()
{
    set_name("大力丸",({"dali wan","wan"}));
     if(clonep())
    set_default_object(__FILE__);
    else{
    set("unit","颗");
    set("value",4000);
      set("long","这是一颗大力丸(不可流落凡间)。\n");
                set("medicine", 1);
    }
    setup();
}


int cure_ob(object me)
{
      me->set("max_neili",me->query("max_neili")+2);
    me->set("neili",me->query("neili")+200);
    me->set("max_jingli",me->query("max_jingli")+2);
    me->set("jingli",me->query("jingli")+200);
    message_vision("$N服下一颗大力丸，立即出了一身热汗！\n",me);
    return 1;
}
// 注：切勿流落凡间
