inherit ITEM;
void create()
{
      set_name("��",({"jin dan","dan"}));
     if(clonep())
    set_default_object(__FILE__);
    else{
    set("unit","��");
    set("value",4000);
        set("long","����һ�Ž����õĽ�(��˵��������˼��)��\n");
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
     message_vision("$N����һ�Ž𵰣�����һ������ƣ�\n",me);
    ob->move(me);
    destruct(ob1);
    return 1;
}
// ע���������䷲��
